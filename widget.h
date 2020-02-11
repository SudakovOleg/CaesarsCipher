#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
  class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_CodeText_textChanged();

  void on_radioButton_2_clicked();

  void on_spinBox_valueChanged(int arg1);

private:
  Ui::Widget *ui;
  QString decode(QString str, int depos);
};

#endif // WIDGET_H
