#include "widget.h"
#include "ui_widget.h"
#include "abcrus.h"

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

void Widget::on_CodeText_textChanged()
{
    QString str = decode(ui->CodeText->toPlainText(), 1);
    ui->DecodeText->setText(str);
}

QString Widget::decode(QString str, int depos)
{
  AbcRus abc;
  for(int i(0); i < str.count(); i++)
  {
    if(!(str[i] == ' ' || str[i] == '\n'))
      str[i] = abc.getChar(abc.getChar(str[i]) + depos);
  }
  return str;
}
