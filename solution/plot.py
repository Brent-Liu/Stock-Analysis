import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('trades.csv')

data.columns = ['TimeStamp', 'Symbol', 'Quantity', 'Price']

data

aaa_df = data[data['Symbol'] == 'AAA']
aaa_df

aaa_df['Price'].plot(figsize=(10, 5))

plt.title("AAA Stock Price Over Time")
plt.xlabel("Time Stamp")        
plt.ylabel('Price ($USD)')

# plt.savefig('AAA.png', format='png')

plt.show()