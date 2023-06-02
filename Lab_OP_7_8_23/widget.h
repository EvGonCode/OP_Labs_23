#ifndef WIDGET_H
#define WIDGET_H
#include "BinaryFile.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QListWidget>
#include <QMovie>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *addNumberBtn;
    QPushButton *clearFileBtn;
    QLabel *inputLabel;
    QLabel *calculationsLabel;
    QLabel *positiveListLabel;
    QLabel *negativeListLabel;
    QLabel *giphLabel;
    QMovie *giphMovie;
    QLineEdit *inputText;
    QListWidget *listOfPositive;
    QListWidget *listOfNegative;
    BinaryFile *bf;
    QMessageBox *messageBox;

private:
    void resetLists();
    void recalculate();
public slots:
    void trySaveNumber();
    void clearFile();
};
#endif // WIDGET_H
