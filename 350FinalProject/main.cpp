//Gregory McPherson & Nick Puig
//CSCE 350 Final Project

#include <iostream>
#include "Project.h"
#include <ctime>


int main(int argc, char** argv)
{
	clock_t begin = clock(); //starts timer

	Project Test1("DATA/");
			
	clock_t end = clock();
	
	double time  = double(end - begin) / CLOCKS_PER_SEC; //gets runtime

	std::cout<<time<<std::endl; //displays runtime

	return 0;
}

