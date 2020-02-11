#ifndef FHACK_H
#define FHACK_H

#include <QString>

struct chrCount
{
  int count = 0;
  QChar ch = ' ';
};

class FHack
{
public:
  FHack();
  int hack(QString str);
private:
  int mostPopular = 0;
  QChar findCh(QString str);
  int findKey(QChar ch);
};

#endif // FHACK_H
