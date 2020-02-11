#include "abcrus.h"

AbcRus::AbcRus()
= default;

QChar AbcRus::getChar(int i)
{
  if(i < 33 && i >= 0)
    return abc[i];
  return '!';
}

int AbcRus::getChar(QChar ch)
{
  int i = 0;
  for(auto chr : abc)
    if(chr == ch)
    {
      return i;
      break;
    }
    else
    {
      i++;
    }
}
