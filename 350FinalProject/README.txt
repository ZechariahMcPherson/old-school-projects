This program expects all of the .dat files to be in the same file.
 You must give the path to that file in the main.cpp.
To give the path to the file that contains .dat files go to where 
main.cpp creates the instance of Project. The line
of code is "Project Test1("DATA/");" you want to change what is 
passed to the constructor to be the path to the file that
contains the .dat files. For example "Project Test1("PATH/PATH2/DATA");" 

To compile the program type “make” in the 
Linux terminal. Then type "./a.out" this will
show you the execution time of the program and it will also
 create a file "Out.txt". The file "Out.txt" contains 
the ten nearest neighbors for each query file. 

Best execution time 3.81374 done on machine 01 in lab 1D29