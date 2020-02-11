#include "fhack.h"
#include <QList>

FHack::FHack()
= default;

QChar FHack::findCh(QString str)
{
  QList<chrCount> *chrs = new QList<chrCount>;
  for(auto ch : str)
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
