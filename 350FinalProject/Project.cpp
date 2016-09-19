//Gregory Zechariah McPherson & Nick Puig

#include "Project.h"

//is used for the native sort() to sort by the second element in the vector
bool Compare(const std::pair<int,float> &a, const std::pair<int,float> &b)
{
        return (a.second>b.second);
}

//sends all of the files to the Solve()
Project::Project(const string Path)
{
	std::stringstream T, Q1, Q2, Q3;

	//runs through the first ten templates and 30 queries
	for(int i = 1; i < 10; i++)
	{
		T<<Path<<"00"<<i<<"_template.dat";
		Q1<<Path<<"00"<<i<<"_AU01_query.dat";
		Q2<<Path<<"00"<<i<<"_AU12_query.dat";
		Q3<<Path<<"00"<<i<<"_AU17_query.dat";
		
		Solve(T.str(),Q1.str(),Q2.str(),Q3.str());
		
		T.str(std::string());
		Q1.str(std::string());
		Q2.str(std::string());
		Q3.str(std::string());
	}

	//runs through the next 37 templates and 111 queries
	for(int i = 10; i < 48; i++)
	{
		T<<Path<<"0"<<i<<"_template.dat";
		Q1<<Path<<"0"<<i<<"_AU01_query.dat";
                Q2<<Path<<"0"<<i<<"_AU12_query.dat";
                Q3<<Path<<"0"<<i<<"_AU17_query.dat";
	
		Solve(T.str(),Q1.str(),Q2.str(),Q3.str());

		T.str(std::string());
                Q1.str(std::string());
                Q2.str(std::string());
                Q3.str(std::string());
	}
}

//gets the template data and saves it. Then  
void Project::Solve(string Template, string Query1, string Query2, string Query3)
{
	float val(0.0);

	int Row(0),Col(0);
	
	std::ifstream TemplateFile(Template.c_str(), std::ifstream::in);

	TemplateFile.seekg(0,TemplateFile.end);
	int length = TemplateFile.tellg();
	TemplateFile.seekg(0,TemplateFile.beg);
	
	char *buffer = new char[length];

	TemplateFile.read(buffer,length); //load file into ram

	std::stringstream TemplateContents(buffer);
		
	std::string token;
	
	//gets all of the floats in the template file and saves them in the TemplateArray
	while(TemplateContents >> token)
	{
		val = atof(token.c_str());			

		TemplateArray[Row][Col] = val;
			
		if(Col == 5631)
		{
			Col = -1;
			++Row;
		}			

		++Col;
	}	
	
	delete [] buffer;//delete file from ram
	
	//runs simularity of the three queries	
	ReadQueryAndDoSimularity(Query1);
	ReadQueryAndDoSimularity(Query2);
	ReadQueryAndDoSimularity(Query3);

	TemplateFile.close();
}

//reads in the query file and runs the silmularity function for each file
void Project::ReadQueryAndDoSimularity(const string &FileName)
{	
	v.reserve(138);//reserves the required slots need for the vector to save allocation time

	std::ifstream FileIn(FileName.c_str(), std::ifstream::in);

	float val(0.0), temp(0.0), TempVal(0.0), X2(0.0), Y2(0.0), XkYjk(0.0);

	int r(0);

	FileIn.seekg(0,FileIn.end);
	int length = FileIn.tellg();
	FileIn.seekg(0,FileIn.beg);	
	
	char *buffer = new char[length];

	FileIn.read(buffer,length); //load file into ram

	std::stringstream FileInContents(buffer);
		
	std::string token;

	//gets the floats in the query and saves them in the Query array
	while(FileInContents >> token)
	{
		val = atof(token.c_str());
			
		Query[r] = val;
		
		X2 += (val*val); //gets the summation of each element squared as needed for the simularity function

		++r;
	}		
	
	//simularity funciton
	for(int i = 0; i < 138; i++)
	{
		for(int j = 0; j < 5632; j++)
		{
			TempVal = TemplateArray[i][j];						

			XkYjk += (TempVal * Query[j]);
			Y2 += (TempVal * TempVal);
		}
		
		temp = sqrt(X2*Y2);
		temp = (XkYjk/temp);
		
		v.push_back(std::pair<int,float> ((i+1),temp));//pushes back the row and value of the simularity function	
		
		XkYjk = 0.0;
		Y2 = 0.0;
	}

	std::sort(v.begin(),v.end(),Compare);//sorts the results of the simulartity function
		
	Print(v,FileName);
		
	v.clear();
	FileIn.close();
	delete [] buffer; //delete file from ram;
}

//prints the top ten closest rows  of each file
void Project::Print(const std::vector<std::pair<int,float> > &a,const string &FileName)
{
	std::fstream WriteFile("Out.txt", std::ios::out | std::ios::app);

	WriteFile<<"---------------------------------\n";
	
	WriteFile<<"Ten closest for "<<FileName<<" are: \n";

	for(int i = 0; i < 10; ++i)
	{
		WriteFile<<"Row: "<<a[i].first<<", Value: "<<a[i].second<<" \n";
	}

	WriteFile.close();
}
