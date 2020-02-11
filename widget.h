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

private:
  Ui::Widget *ui;
  QString decode(QString str, int depos);
};

#endif // WIDGET_H
