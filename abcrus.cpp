#include "abcrus.h"

AbcRus::AbcRus()
= default;

QChar AbcRus::getChar(int i)
{
  if(i < 0)
    return '!';
  return abc[i%33];
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
  return -100;
}
