# Stock Market Data Analysis Project

## Overview

Our task is to develop a program for a client that processes daily stock market data within an hour. The solution must be maintainable and accurate.

## Input

- Format: `<TimeStamp>,<Symbol>,<Quantity>,<Price>`
- The data represents a series of trades.
- Key Points:
  - TimeStamp: microseconds since midnight, for the same day.
  - Symbol: 3-character identifier.
  - Quantity: amount traded.
  - Price: integer, always positive.

## Objectives

- For each symbol, calculate:
  - Maximum time gap between consecutive trades (0 for a single trade).
  - Total volume traded.
  - Weighted average price (rounded to an integer).
  - Minimum and maximum trade price.
- Produce a sorted file 'output.csv' in the format: `<symbol>,<MaxTimeGap>,<Volume>,<WeightedAveragePrice>,<MinPrice>,<MaxPrice>`

## Constraints

- Opt for C++ or a similar compiled language.
- Work with limited memory; avoid loading the entire file into memory.
- Stick to the base tools of the language/platform, no external libraries.
- Process input from stdin and output to stdout. For example, `cat input.csv | process_trades  > output.csv`.

## Data Visualization

- Create a chart showing the price trajectory over time for the AAA symbol.
- Axis details: X-axis for TimeStamp, Y-axis for Price.
- Save the chart as either `AAA.png` or `AAA.jpg`.