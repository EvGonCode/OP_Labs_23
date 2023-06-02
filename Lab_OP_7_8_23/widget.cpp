#include "widget.h"
#include "BinaryFile.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Binary File Calculator");
    resize(600,400);

    inputLabel = new QLabel(this);
    inputLabel->move(20, 0);
    inputLabel->setText("Input int numbers");

    positiveListLabel = new QLabel(this);
    positiveListLabel->move(60, 130);
    positiveListLabel->setText("Positive numbers");

    negativeListLabel = new QLabel(this);
    negativeListLabel->move(200, 130);
    negativeListLabel->setText("Negative numbers");

    calculationsLabel = new QLabel(this);
    calculationsLabel->setGeometry(320, 130, 200, 20);
    calculationsLabel->setText("Calculations: 123.456");


    addNumberBtn = new QPushButton(this);
    addNumberBtn->setText("Add number");
    addNumberBtn->setGeometry(20, 60, 100, 20);
    connect(addNumberBtn, SIGNAL(clicked()), this, SLOT(trySaveNumber()));

    clearFileBtn = new QPushButton(this);
    clearFileBtn->setText("Clear file");
    clearFileBtn->setGeometry(400, 20, 100, 20);
    connect(clearFileBtn, SIGNAL(clicked()), this, SLOT(clearFile()));


    inputText = new QLineEdit(this);
    inputText->setGeometry(20, 20, 200, 30);

    listOfPositive = new QListWidget(this);
    listOfPositive->setGeometry(60, 150, 100, 200);
    listOfNegative = new QListWidget(this);
    listOfNegative->setGeometry(200, 150, 100, 200);

    giphLabel = new QLabel(this);
    giphLabel->setGeometry(350, 200, 250, 200);
    giphMovie = new QMovie(":images/ggif.gif");
    giphLabel->setMovie(giphMovie);
    giphMovie->start();


    messageBox = new QMessageBox(this);
    messageBox->setWindowTitle("Error");

    resetLists();
    recalculate();
}

void Widget::trySaveNumber(){
    try{
        BinaryFile bf;
        if(!bf.isInteger(inputText->text().toStdString())){
            throw WrongInputException();
        }
        int input = inputText->text().toInt();
        bf.writeNumber(input);
        resetLists();
        recalculate();
    }catch(WrongInputException &e){
        messageBox->setText(e.what());
        messageBox->exec();
    }catch(exception &e){
        messageBox->setText(e.what());
        messageBox->exec();
    }
}


void Widget::resetLists(){
    try{
    listOfPositive->clear();
    listOfNegative->clear();

    int size;
    int* arr = bf->getAllNumbers(&size);
    if(size != 0){
        for(int i = 0; i < size; i++){
            if(arr[i] > 0){
                listOfPositive->addItem(QString::number(arr[i]));
            }else{
                listOfNegative->addItem(QString::number(arr[i]));
            }
        }
    }

    delete[] arr;
    }catch(FailedOpenFileException &e){
    messageBox->setText(e.what());
    messageBox->exec();
    }catch(exception &e){
    messageBox->setText(e.what());
    messageBox->exec();
    }
}

void Widget::clearFile(){
    try{
    bf->clear();
    resetLists();
    recalculate();
    }catch(FailedOpenFileException &e){
    messageBox->setText(e.what());
    messageBox->exec();
    }catch(exception &e){
    messageBox->setText(e.what());
    messageBox->exec();
    }
}

void Widget::recalculate(){
    try{
    int size;
    int* arr = bf->getAllNumbers(&size);
    double avg = 0;
    double t = 1;
    for(int i = 0; i < size; i++){
        if(arr[i] > 0){
            avg += ((double)arr[i] - avg) / t;
            ++t;
        }
    }
    if(!(avg > 0)){
        throw PositiveNotFoundException();
    }
    stringstream stream;
    string number;
    stream << fixed << setprecision(2) << avg;
    stream >> number;
    string str = "Average positive: " + number;
    calculationsLabel->setText(QString::fromStdString(str));
    delete[] arr;
    }catch(PositiveNotFoundException &e){
    calculationsLabel->setText("Average positive: No data");
    }catch(FailedOpenFileException &e){
    messageBox->setText(e.what());
    messageBox->exec();
    }catch(exception &e){
    messageBox->setText(e.what());
    messageBox->exec();
    }
}


Widget::~Widget()
{
}

