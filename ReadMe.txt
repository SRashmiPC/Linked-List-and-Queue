<<Linnked List, Queue, Stack>>
This program is linke to oop version of linked list
But there are some difference to make the program better.

>> int DeleteNode(E value) function return the value of deleted node as you have 
   asked in PDF. But most cases it will returnn value which pass to the parameter.
   So I change that to the return type to Node*.
>> To maka easy the cade I have used a tail pointer.. 
>>Enter a int value to terminate the program.

<< compile and run c++ code without IDE >>

1. Download a open source software or gcc compiler (ex: mingw)
2. Install the compiler (if necessary update it)
3. Change environment variable for computer or for your user acccount
	satrt>>computer>>properties>>advaanced system settings>>environment variable
	add new variable using new button
		name: path
		variable: C:mingw\bin {path of bin folder in compiler installed}
	and add c:mingw\bin foloowed by a semicolon
4. Open the cmd..
5. Got to the directory where the source file exist
6. Enter following command
	g++ filename.cpp -o filename
// It will compile your program
//If no errors it will genarate .exe file with same name
7. To run the program  write filename // Do not write the extention