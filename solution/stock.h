#ifndef STOCK_H
#define STOCK_H

#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Stock
{
public:
  mutable long max_time_gap;
  mutable long last_traded;
  char symbol[ 3 ];
  mutable int total_qty;
  mutable int max_price;
  mutable int min_price;
  mutable double weighted_av_p;
  
  Stock();

  struct HashFunction
  {
    size_t operator()(const Stock& stock) const
    {
      size_t hash = 0;
      for (size_t i = 0; i < sizeof(stock.symbol); ++i) {
          hash = (hash * 31) + stock.symbol[i];
      }
      return hash;
    }
  };
  
  bool operator==(const Stock& s) const;

  friend ostream & operator<<(ostream & os, const Stock & t)   
    {
      os << t.symbol[ 0 ] << t.symbol[ 1 ] << t.symbol[ 2 ] <<
      ',' << t.max_time_gap << ',' << t.total_qty << ',' <<
      floor( t.weighted_av_p ) << ',' << t.min_price << ',' << t.max_price;
      return os;
    }
};

#endif