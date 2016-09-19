//Gregory McPherson & Nick Puig
//CSCE 350 Final Project

#ifndef PROJECT_H
#define PROJECT_H

#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

#include <vector>

using std::string;

class Project
{

        public:
		Project(const string Path); //Takes path of the folder that hold the .dat files
				

		void Solve(string,string,string,string);
		
		void ReadQueryAndDoSimularity(const string &FileName);

		void Print(const std::vector<std::pair<int,float> > &a, const string &FileName);

        private:
		std::vector<std::pair<int,float> >v;			
	
		float TemplateArray [138][5640];

		float Query [5640]; 
};
#endif /*PROJECT_H*/
