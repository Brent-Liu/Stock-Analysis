## How to execute the project
1. Open the terminal of the folder (in linux environment)

2. Execute the makefile to compile the code.
```
make -f Makefile
```

3. Put the trade data file into the same foler (assume the trade data file name as input.csv)

4. Execute the program, which read from stdin and write to stdout. (assume the output stream redirect to output.csv file)
```
./process_trades >output.csv <input.csv
```

## Answer to the questions in instruction files

To this project, I used Linux Ubuntu 20.02 (WSL) as the development platform, C++ as the language and using VS Code Tools in the development. I tend to develop code in linux, because in linux I don't consider too much about permissions and linux has powerful commands and package management tools in it, which make develop simpler. As to language, C/C++ is my favorate language and most familiar language. C/C++ enjoys the speed, flexible, talk to the hardware directly, root of other modern languages. So I choice C++ as my primitive language and finish this project

It cost me around 90min to finished the C++ streaming project and 20min to finish the plot project, I used pandas and matplotlib to plot the figure.

To verify my solution, I wrote some simple test case to test and the project got expected output. The more strict test need unit test and integration test.

As to setting up the task to run on a daily basis. My Thought is write a bash file and use cron to schedule the execution of the program.

As to monitor the ongoing execution of the task, I want to use the log file. For example, we can generate different log file by ```std::cout``` and ```std:err``` to monitor the execution of the program. Or using external library to help us generate the log file.


Thanks for giving me the opportunity to take this interesting project! 
Please give me instructions and suggestion to make me stronger.