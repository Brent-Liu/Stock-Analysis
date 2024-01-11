#include "stock.h"
#include <cstring>
#include <cstring>

Stock::Stock()
{
    max_time_gap = 0;
    last_traded = 0;
    max_price = 0;
    min_price = INT32_MAX;
    total_qty = 0;
    weighted_av_p = 0;
}

bool Stock::operator==(const Stock& stock) const {
    return std::memcmp(symbol, stock.symbol, 3) == 0;
}