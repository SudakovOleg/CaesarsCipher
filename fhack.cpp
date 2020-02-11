#include "fhack.h"
#include <QList>
#include "abcrus.h"

FHack::FHack()
= default;

int FHack::hack(QString str)
{
  return findKey(findCh(str));
}

QChar FHack::findCh(QString str)
{
  QList<chrCount> *chrs = new QList<chrCount>;
  for(auto ch : str)
  {
    if(!(ch == ' ' || ch == '\n'))
    {
      bool flag = false;
      for(auto &ch_fromList : *chrs)
      {
        if(ch == ch_fromList.ch)
        {
          flag = true;
          ch_fromList.count++;
          break;
        }
      }
      if(!flag)
      {
        chrCount nChr;
        nChr.ch = ch;
        nChr.count++;
        chrs->push_back(nChr);
      }
    }
  }
  int max = 0;
  QChar res;
  for(auto ch_fromList : *chrs)
  {
    if(ch_fromList.count > max)
    {
      res = ch_fromList.ch;
      max = ch_fromList.count;
    }
  }
  return res;
}

int FHack::findKey(QChar ch)
{
  AbcRus abc;
  int res = mostPopular - abc.getChar(ch);
  return res < 0 ? res + 33: res;
}
