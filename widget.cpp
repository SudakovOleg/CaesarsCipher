#include "widget.h"
#include "ui_widget.h"
#include "abcrus.h"
#include "hack.h"

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  ui->CodeRB->setChecked(true);
  ui->spinBox->setRange(0,33);
}

Widget::~Widget()
{
  delete ui;
}

void Widget::on_CodeText_textChanged()
{
  if(ui->CodeRB->isChecked())
  {
    QString str = decode(ui->CodeText->toPlainText(), ui->spinBox->value());
    ui->DecodeText->setText(str);
  }
  else
  {
    Hack hack;
    QString res = "Have not answer";
    for(int i(0); i < 33; i++)
    {
      QString str = decode(ui->CodeText->toPlainText(), i);
      if(hack.isWords(str))
      {
        QString key;
        key.setNum(i);
        res = str + "\nKey: " + key;
        break;
      }
    }
    ui->DecodeText->setText(res);
  }
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

void Widget::on_spinBox_valueChanged(int arg1)
{
  Q_UNUSED(arg1);
  on_CodeText_textChanged();
}

void Widget::on_HackRB_clicked()
{
  ui->CodeRB->setChecked(false);
  ui->spinBox->setEnabled(false);
  ui->DecodeText->setEnabled(false);
}

void Widget::on_CodeRB_clicked()
{
  ui->CodeRB->setChecked(true);
  ui->spinBox->setEnabled(true);
  ui->DecodeText->setEnabled(true);
}
