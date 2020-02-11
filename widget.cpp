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
    QString str = decode(ui->CodeText->toPlainText());
    ui->DecodeText->setText(str);
}

QString Widget::decode(QString str)
{
  for(int i(0); i < str.count(); i++)
  {
    if(!(str[i] == ' ' || str[i] == '\n'))
      str[i] = abc(1, str[i]);
  }
  return str;
}

QChar Widget::abc(int i, QChar ch)
{
  QString abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
  int ni = 0;
  for(auto chr : abc)
    if(chr == ch)
    {
      ni += i;
      if(ni > 32)
        ni -= 33;
      break;
    }
    else
      ni++;
  return abc[ni];
}
