#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setText("23232dfv");

    //ui->lineEdit->text()

    ui->label->setText(ui->lineEdit->text());
}

void speed(){

}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    auto start_time = std::chrono::high_resolution_clock::now();
    std::uint64_t count = 0;

    for(int i = 0; i <= 1000000; i++)
    {

        uint64_t aaa = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-start_time).count();
        QString vvv = QString("aaa %1").arg(aaa);
            ui->label->setText(vvv);

     qDebug() << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-start_time).count() << "\n";
    }

//    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now()-start_time).count()<30)
//    {

//        //        while ()
//        //        {

//        //        }
//        //        count++;
//    }

//        https://cplusplus.com/reference/chrono/seconds/
//        duration	Duration (class template)
//        hours	Duration in hours (class)
//        minutes	Duration in minutes (class)
//        milliseconds	Duration in milliseconds (class)
//        microseconds	Duration in microseconds (class)
//        nanoseconds	Duration in nanoseconds (class)

    uint64_t aaa = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-start_time).count();
    QString vvv = QString("aaa %1").arg(aaa);
    ui->label->setText(vvv);

}

