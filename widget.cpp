#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
   QString stockID = ui->lineEdit->text() + tr(".tw");
   Download mission(this, stockID);
   if( mission.getData() )
   {
       mission.getData();
       mission.writeFile();
       QMessageBox::information(this, "", tr("下載成功"), QMessageBox::Yes);
   }
   else
       QMessageBox::warning(this, tr("Warring"), tr("無此股票"), QMessageBox::Yes);

}
