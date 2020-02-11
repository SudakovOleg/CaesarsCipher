#include "hack.h"

Hack::Hack()
= default;

bool Hack::isWords(QString str)
{
  int gl = 0;
  int sg = 0;
  for(auto ch : str)
  {
    if(!(ch == ' ' || ch == '\n'))
    {
      if(isHasCh(ch))
      {
        gl++;
        sg = 0;
      }
      else
      {
        sg++;
        gl = 0;
      }
    }
    else
    {
      sg = 0;
      gl = 0;
    }
    if(sg > 3 || gl > 3)
      return false;
  }
  return true;
}

bool Hack::isHasCh(QChar ch)
{
  for(auto glas : chs)
    if(ch == glas)
      return true;
  return false;
}
