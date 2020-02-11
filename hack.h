#ifndef HACK_H
#define HACK_H

#include <QString>

class Hack
{
public:
  Hack();
  bool isWords(QString str);
private:
  bool isHasCh(QChar ch);
  QString chs = "аеёиоуыэюя";
};

#endif // HACK_H
