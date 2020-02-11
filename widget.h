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
  void on_spinBox_valueChanged(int arg1);

  void on_HackRB_clicked();

  void on_CodeRB_clicked();

private:
  Ui::Widget *ui;
  QString decode(QString str, int depos);
};

#endif // WIDGET_H
