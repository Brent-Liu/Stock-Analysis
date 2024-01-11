#include "stock.h"
#include "process.h"
#include <cmath>
# include <cstring>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

unordered_set<Stock, Stock::HashFunction> all_stock_info;
bool compareBySymbol(const Stock& a, const Stock& b);

int main( int argc, char ** argv )
{
    try 
    {

        const int RD_BUF_SZ = 30;
        char buffer[ RD_BUF_SZ ];

        int line_counter = 0;

        while( cin.getline( buffer, RD_BUF_SZ, '\n' ) )
        {
            ++line_counter;
            bool result = process( buffer, all_stock_info);
            if(!result )
            {
                cerr << "Could not successfully parse the line, unexpected format\n";
                cerr << "File is: " << __FILE__ << "Line is: " << __LINE__ << endl;
                cerr << "The error line of the input file is: " << line_counter << endl;
                exit( 1 );
            }
        }

        vector<Stock> stock_form (all_stock_info.begin(), all_stock_info.end());

        sort(stock_form.begin(), stock_form.end(), compareBySymbol);

        for (auto it : stock_form) {
            cout << it << endl;
        }

        return 0;

    }
    catch( const exception & e )
    {
        cout << "Unexpected error encountered, terminating program: " << e.what() << endl;
    }
    catch( ... )
    {
        cout << "Unexpected error encountered, terminating program.\n";
    }
}


bool compareBySymbol(const Stock& a, const Stock& b) {
    return (strncmp(a.symbol, b.symbol, 3) < 0);
}