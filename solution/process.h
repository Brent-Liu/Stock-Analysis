#ifndef PROCESS_H
#define PROCESS_H

#include <unordered_set>
#include "stock.h"

bool process( char * buffer, std::unordered_set<Stock, Stock::HashFunction>& all_symbol_info);

#endif