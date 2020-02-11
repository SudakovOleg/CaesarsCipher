#ifndef ABC_H
#define ABC_H

#include <QString>

class AbcRus
{
public:
  AbcRus();
  QChar getChar(int i);
  int getChar(QChar ch);
private:
  QString abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
};

#endif // ABC_H
