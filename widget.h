#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QList>
#include <QListIterator>

namespace Ui {
class Widget;
class Book;
}



class Book
{
public:
    int     number;
    QString title;
    QString author;
    int     year;
    int     amount;
public:
friend QDataStream &operator <<(QDataStream &stream, const Book &book)
{
stream << book.number;
stream << book.title;
stream << book.author;
stream << book.year;
stream << book.amount
          ;
return stream;
}
friend QDataStream &operator >>(QDataStream &stream, Book &book)
{
    stream >> book.number;
    stream >> book.title;
    stream >> book.author;
    stream >> book.year;
    stream >> book.amount;
return stream;
}
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    int iNum = 1;
    int udk = 1;
private:
    Ui::Widget *ui;

    QListIterator<Book> *Iter, *It;
    QLabel  *label, *label_1, *label_2, *label_3, *label_4, *label_5, *label_6, *label_7;
    QLineEdit *lineEdit, *lineEdit_1, *lineEdit_2, *lineEdit_3, *lineEdit_4, *lineEdit_5;
    QGridLayout *layout;
    QHBoxLayout     *layout_H;
    QVBoxLayout     *layout_V;
    QPushButton *pushButton, *pushButton_1, *pushButton_2, *pushButton_4,  *pushButton_3, *pushButton_5, *pushButton_6;
    QList<Book>  *list;


private slots:
    void add();
    void first();
    void nextel();
    void last();
    void del();
    void find();
};

#endif // WIDGET_H
