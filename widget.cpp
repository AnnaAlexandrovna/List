#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMutableListIterator>
#include <QLine>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    label = new QLabel("Номер УДК");
    label_1 = new QLabel("Название книги");
    label_2 = new QLabel("Автор книги");
    label_3 = new QLabel("Год издания");
    label_4 = new QLabel("Количество книг");
    label_5 = new QLabel();
    label_6 = new QLabel("1");
    label_7 = new QLabel("Поиск по названию");

    lineEdit = new QLineEdit("1");
    lineEdit_1 = new QLineEdit();
    lineEdit_2 = new QLineEdit();
    lineEdit_3 = new QLineEdit();
    lineEdit_4 = new QLineEdit();
    lineEdit_5 = new QLineEdit();

     list = new QList<Book>;
     QListIterator<Book> It(*list);

    pushButton = new QPushButton("Добавить в список");
    connect(pushButton, SIGNAL(clicked()), this, SLOT(add()));

    pushButton_2 = new QPushButton("|<");
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(first()));

     pushButton_3 = new QPushButton(">>");
     connect(pushButton_3, SIGNAL(clicked()), this, SLOT(nextel()));

    pushButton_4 = new QPushButton(">|");
    connect(pushButton_4, SIGNAL(clicked()), this, SLOT(last()));

    pushButton_5 = new QPushButton("Удалить");
    connect(pushButton_5, SIGNAL(clicked()), this, SLOT(del()));

    pushButton_6 = new QPushButton("Найти");
    connect(pushButton_6, SIGNAL(clicked()), this, SLOT(find()));


    layout = new QGridLayout;
    layout_V = new QVBoxLayout;
    layout_H = new QHBoxLayout;

    layout_V->addLayout(layout);
    layout_V->addLayout(layout_H);

    layout->addWidget(label,0,0);
    layout->addWidget(label_1,0,1);
    layout->addWidget(label_2,0,2);
    layout->addWidget(label_3,0,3);
    layout->addWidget(label_4,0,4);
    layout->addWidget(pushButton, 0,5);

    layout->addWidget(label_6,1,0);
    layout->addWidget(lineEdit_1,1,1);
    layout->addWidget(lineEdit_2,1,2);
    layout->addWidget(lineEdit_3,1,3);
    layout->addWidget(lineEdit_4,1,4);

    layout->addWidget(label_7,2,0);
    layout->addWidget(lineEdit_5,2,1);
    layout->addWidget(pushButton_6,2,2);
    layout->addWidget(pushButton_5,2,3);

    layout_H->addWidget(pushButton_2,1);
    layout_H->addWidget(label_5,1);

    layout_H->addWidget(pushButton_3,1);
    layout_H->addWidget(pushButton_4,1);
     this->resize(750, 150);
    this->setLayout(layout_V);
    this->show();


}

void Widget::add()
{
   QMutableListIterator<Book> it(*list);
    Book t;
    t.number = udk++;
    label_6->setText(QString::number(udk));
    t.title = lineEdit_1->text();
    t.author = lineEdit_2->text();
    t.year = lineEdit_3->text().toInt();
    t.amount = lineEdit_4->text().toInt();

    list->push_back(t);

    lineEdit_1->setText("");
    lineEdit_2->setText("");
    lineEdit_3->setText("");
    lineEdit_4->setText("");
}

void Widget::del()
{
    QString s= "";
    s = lineEdit_5->text();

    QMutableListIterator<Book> i(*list);
    i.toFront();
    while (i.hasNext())
    {
        if(s == i.next().title)
            i.remove();
    }
    iNum=i.next().number;
}

void Widget::find()
{
    QString s= "";
    s = lineEdit_5->text();

    QMutableListIterator<Book> i(*list);
    i.toFront();
    while (i.hasNext())
    {
        if(s == i.peekNext().title)
        { iNum=i.peekNext().number-1;
           nextel();
        }
       i.next();
    }

}

void Widget::first()
{
    QString s= "";
    QListIterator<Book> Iter(*list);
    Iter.toFront();
                s = s + "Номер УДК: "+ QString::number(Iter.peekNext().number) + "\nНазвание: " + Iter.peekNext().title +
                        "\nАвтор:" + Iter.peekNext().author +"\nГод издания: " + QString::number(Iter.peekNext().year)
                        + "\nКоличество:" + QString::number(Iter.peekNext().amount);

    label_5->setText(s);
    iNum=Iter.peekNext().number;
}


void Widget::nextel()
{
   QString s= "";
   QListIterator<Book> it(*list);
   it.toFront();iNum++;
   while (it.hasNext())
    {
        if ( it.peekNext().number == iNum)
        {
            s = s + "Номер УДК: "+ QString::number(it.peekNext().number) + "\nНазвание: " + it.peekNext().title +
                 "\nАвтор:" + it.peekNext().author +"\nГод издания: " + QString::number(it.peekNext().year)
                   + "\nКоличество:" + QString::number(it.peekNext().amount);
           label_5->setText(s);
        }
    it.next();
    }
}

void Widget::last()
{
    QString s= "";
    QListIterator<Book> Iter(*list);
    Iter.toBack();
                s = s + "Номер УДК: "+ QString::number(Iter.peekPrevious().number) + "\nНазвание: " + Iter.peekPrevious().title +
                        "\nАвтор:" + Iter.peekPrevious().author +"\nГод издания: " + QString::number(Iter.peekPrevious().year)
                        + "\nКоличество:" + QString::number(Iter.peekPrevious().amount) ;

    label_5->setText(s);
    iNum=9999;
}
Widget::~Widget()
{
    delete ui;
}
