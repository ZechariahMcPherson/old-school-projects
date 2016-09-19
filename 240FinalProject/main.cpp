//Gregory Zechariah McPherson
//CSCSE 240 Final Project

#include <iostream>
#include "Array.h"
#include "Array.cpp"
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
	Array<int> ArrayInt(2,1);

	cout<<"ArrayInt "<<ArrayInt<<endl;;

	Array<int> ArrayInt2(2,-2);

	cout<<"ArrayIn2 "<<ArrayInt2<<endl;;

	Array<int> ArrayInt3(2,3);

	cout<<"ArrayInt3 "<<ArrayInt3<<endl;
	
	cout<<"\n-----------------------------------------------------------"<<endl;

	cout<<"ArrayInt3 = (ArrayInt - ArrayInt2) + ArrayInt3"<<endl;

	ArrayInt3 = (ArrayInt - ArrayInt2) + ArrayInt3;

	cout<<"ArrayInt"<<endl;

        cout<<ArrayInt;
        
        cout<<"ArrayInt2"<<endl;

        cout<<ArrayInt2;

	cout<<"ArrayInt3"<<endl;
	
	cout<<ArrayInt3;

	cout<<"\n---------------------------------------------------------------"<<endl;

	Array<double> ArrayDouble(2,3.3);

	cout<<"ArrayDouble "<<ArrayDouble;

	Array<double> ArrayDouble2(2,-4.3);

	cout<<"ArrayDouble2 "<<ArrayDouble2;

	Array<double> ArrayDouble3(2,4.5);

	cout<<"ArrayDouble3 "<<ArrayDouble3;

	cout<<"\n----------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3 = (ArrayDouble + ArrayDouble) - (ArrayDouble3 + ArrayDouble2)"<<endl;

	ArrayDouble3 = (ArrayDouble + ArrayDouble) - (ArrayDouble3 + ArrayDouble2);

	cout<<"ArrayDouble "<<ArrayDouble;

	cout<<"ArrayDouble2 "<<ArrayDouble2;

	cout<<"ArrayDouble3 "<<ArrayDouble3;
	
	cout<<"\n----------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3[1] = -3.8"<<endl;;

	ArrayDouble3[1] = -3.8;

	cout<<"ArrayDouble3 "<<ArrayDouble3<<endl;    
	
	cout<<"\n---------------------------------------------------------------"<<endl;

	cout<<"cout<<ArrayDouble3[1]"<<endl;
	
	cout<<ArrayDouble3[1];

	cout<<"\n----------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3 += ArrayDouble3"<<endl;

	ArrayDouble3 += ArrayDouble3;

	cout<<"ArrayDouble3 "<<ArrayDouble3<<endl;

	cout<<"\n----------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3 -= ArrayDouble3"<<endl;

	ArrayDouble3 -= ArrayDouble3;

	cout<<"ArrayDouble3 "<<ArrayDouble3<<endl;

	cout<<"\n-----------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3 = ArrayDouble2++ -  ArrayDouble3"<<endl;

	ArrayDouble3 = ArrayDouble2++ - ArrayDouble3;

	cout<<"ArrayDouble3 "<<ArrayDouble3<<endl;

	cout<<"ArrayDouble2 "<<ArrayDouble2<<endl;

	cout<<"\n---------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3 = ++ArrayDouble2 + ArrayDouble3"<<endl;

	ArrayDouble3 = ++ArrayDouble2 + ArrayDouble3;

	cout<<"ArrayDouble3 "<<ArrayDouble3<<endl;

	cout<<"ArrayDouble2 "<<ArrayDouble2<<endl;

	cout<<"\n--------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3 = (-ArrayDouble2)"<<endl;

	ArrayDouble3 = (-ArrayDouble2);

	cout<<"ArrayDouble3 "<<ArrayDouble3<<endl;

	cout<<"ArrayDouble2 "<<ArrayDouble2<<endl;

	cout<<"\n--------------------------------------------------------------"<<endl;

	cout<<"ArrayDouble3 == ArrayDouble3"<<endl;

	cout<<(ArrayDouble3 == ArrayDouble3)<<endl;

	cout<<"ArrayDouble3 == ArrayDouble2"<<endl;

	cout<<(ArrayDouble3 == ArrayDouble2)<<endl;
}
