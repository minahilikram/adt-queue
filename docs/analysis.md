# Overview

The program has a menu of options to choose from to test it. No input validation. I did not have createQueue as an option in main because then I would have to keep track of more than one list. Runs two simulations; first takes random numbers (1 to 3), numbers represent people, adds random numbers (people) to two seperate queues for each simulation. Both queues are identical. Arrays are used to keep track of total and current time, size of the array represents counters at the airport. Simulation goes through a loop to dequeue people while keeping track of current and total time and checks to see which simulation was faster.

## Tests

| TESTS |RESULTS | FIX |
| ------------------ |--------------------| -------------------|
| if dequeue function is called on an empty list     	        | seg fault      		      | check for empty list   			    | 
| if destroy function is called more than once       	        | program crashes		      | destroy and exit together   	    | 
| if the integers entered are too big or too small  	    | overflow        		      | can't take too big or too small numbers	| 
| if any function is sent a bad pionter   		| seg faults        		 |  keep track of pointers			|
| checking for memory leaks using Valgrind 		| no leaks found     		 |  no fix needed  		 | 
| if double or float is sent               		| number truncated   		 |  cannot take decimals, send only int  		|
| if characters are put into the input menu		| crashes   		| check for characters   		|
| if "enter" is put in		| crashes   		| does nothing, waits for input   		| scanf ignores new line, let user know
| if negative numbers are put in 		| runs anyway, does nothing   		| check for negatives, let user know	| 
