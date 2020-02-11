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
  QChar findCh(QString str);
  int findKey();
};

#endif // FHACK_H
