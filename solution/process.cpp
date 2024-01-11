#include <unordered_set>
#include <cstring>
#include "process.h"

using namespace std;

bool process(char * buffer, unordered_set<Stock, Stock::HashFunction>& all_stock_info)
{
    Stock lookup_key;

     // Pick up the timestamp
    char * find_comma = strchr( buffer, ',' );
    if( 0 == find_comma )
        return false;
    *find_comma = 0;
    unsigned long current_time_stamp = atol( buffer );
    buffer = find_comma + 1;

    // Pick up the 3-char symbol
    find_comma = strchr( buffer, ',' );
    if( 0 == find_comma )
        return false;
    *find_comma = 0;
    strncpy( lookup_key.symbol, buffer, 3 );

    pair< unordered_set<Stock, Stock::HashFunction>::iterator, bool> itr = all_stock_info.insert( lookup_key );
    
    if( itr.first->last_traded != 0)
    {
        long current_gap = current_time_stamp - itr.first->last_traded;
        if( itr.first->max_time_gap < current_gap )
            itr.first->max_time_gap = current_gap;
    }
    itr.first->last_traded = current_time_stamp;

    // Pick up and process the quantity info
    buffer = find_comma + 1;
    find_comma = strchr( buffer, ',' );
    if( 0 == find_comma )
        return false;
    *find_comma = 0;
    int current_qty = atoi( buffer );

    // Pick up and process the price info
    buffer = find_comma + 1;
    int current_price = atoi( buffer );
    if( itr.first->max_price < current_price )
       itr.first->max_price = current_price;
    if (itr.first->min_price > current_price) 
        itr.first->min_price = current_price;

    itr.first->weighted_av_p = (( itr.first->weighted_av_p * itr.first->total_qty ) + 
                          ( current_price * current_qty ) ) / ( itr.first->total_qty + current_qty );
    itr.first->total_qty += current_qty;

    return true;
}