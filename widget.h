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
  QString decode(QString str);
  QChar abc(int i, QChar ch);
  Ui::Widget *ui;
};

#endif // WIDGET_H
