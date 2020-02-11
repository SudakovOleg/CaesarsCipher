#include "widget.h"
#include "ui_widget.h"
#include "abcrus.h"
#include "hack.h"
#include "fhack.h"

//Конструктор
Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  ui->CodeRB->setChecked(true);
  ui->spinBox->setRange(0,33);
  ui->pushButton->setVisible(false);
}

//Деструктор
Widget::~Widget()
{
  delete ui;
}

//Слот реагирования на изменения текста
void Widget::on_CodeText_textChanged()
{
  //Если активна радиокнопка шифровки/дешифровки
  if(ui->CodeRB->isChecked())
  {
    QString str = decode(ui->CodeText->toPlainText(), ui->spinBox->value());
    ui->DecodeText->setText(str);
  }
  //Если активна радиокнопка взлома
  else if(ui->HackRB->isChecked())
  {
    Hack hack;
    QString res = "Have not answer";
    for(int i(nowkey+1); i < 33; i++)
    {
      //Запоминаем позицию
      nowkey = i;
      //Декодируем на заданное смещение
      QString str = decode(ui->CodeText->toPlainText(), i);
      //Проверяем смысловую нагрузку, если есть выходим
      if(hack.isWords(str))
      {
        QString key;
        key.setNum(i);
        res = str + "\nKey: " + key;
        break;
      }
    }
    //Выводим результат
    ui->DecodeText->setText(res);
  }
  //Если активна радиокнопка частотного взлома
  else
  {
    FHack hack;
    //Считаем смещение для самого частовстречаемого символа в русском языке и выводим текст
    QString str = decode(ui->CodeText->toPlainText(), hack.hack(ui->CodeText->toPlainText()));
    QString key;
    key.setNum(hack.hack(ui->CodeText->toPlainText()));
    ui->DecodeText->setText(str + "\nKey: " + key);
  }
}

//Метод дешифровки
QString Widget::decode(QString str, int depos)
{
  AbcRus abc;
  str = str.toLower();
  for(int i(0); i < str.count(); i++)
  {
    if(!(str[i] == ' ' || str[i] == '\n'))
      str[i] = abc.getChar(abc.getChar(str[i]) + depos);
  }
  return str;
}

//Слот реакции на изменение спинбокса
void Widget::on_spinBox_valueChanged(int arg1)
{
  Q_UNUSED(arg1);
  if(ui->CodeRB->isChecked())
    on_CodeText_textChanged();
}

//Слот реакции на нажатие кнопки взлома
void Widget::on_HackRB_clicked()
{
  ui->CodeRB->setChecked(false);
  ui->spinBox->setEnabled(false);
   ui->DecodeText->setReadOnly(true);
  ui->pushButton->setVisible(true);
  ui->spinBox->setValue(0);
}

//Слот реакции на нажатие кнопки шифрования
void Widget::on_CodeRB_clicked()
{
  ui->CodeRB->setChecked(true);
  ui->spinBox->setEnabled(true);
   ui->DecodeText->setReadOnly(false);
  ui->pushButton->setVisible(false);
}

//Слот реакции на нажатие кнопки перехода к следующему
//варианту дишифровки
void Widget::on_pushButton_clicked()
{
  if(nowkey > 31)
    nowkey = 0;
  on_CodeText_textChanged();
}

//Слот реакции на нажатие кнопки частотного взлома
void Widget::on_FHackRB_clicked()
{
  ui->CodeRB->setChecked(false);
  ui->spinBox->setEnabled(false);
  ui->DecodeText->setReadOnly(true);
  ui->spinBox->setValue(0);
}
