//Gregory Zechariah McPherson
//CSCE 240 Final Project

#include "Array.h"

#include <iostream>

#include <cstdlib>

#include <stdlib.h> //used for Exit_Failure

using namespace std; //removes the need for "std::"

template <class T>
Array<T>::Array() : Size(0)
{
	Data = NULL; //Sets *Data pointer to NULL
}

template <class T>
Array<T>::Array(int arraySize, T value = 0) : Size(arraySize)
{
	Data = new T[size()]; //Initializes Data to the value of Size

        for(int i = 0; i < size(); i++)
        {
                 set(i,value);  //Incriments through Data and assigns each element to Value
        }
}

template <class T>
Array<T>::Array(T anArray[], int arraySize) : Size(arraySize)
{
        Data = new T[size()]; //Initializes Data to the value of Size

        for(int i = 0; i < size(); i++)
        {
                set(i,anArray[i]); //Sets InputedArray's data to the data in Data
        }
}

template <class T>
Array<T>::Array(const Array<T> &orig) : Size(orig.size())
{
        Data = new T[size()]; //Initializes Data to the value of Size

        for(int i = 0; i < size(); i++)
        {
                set(i, orig.get(i)); //copies values over
        }

}

//return size
template <class T>
int Array<T>::size() const
{
	return Size;
}

//equivilent to get
template <class T>
T Array<T>::operator[](int index) const
{
	        if(!(index > size() || index < 0)) //Ensures that the inputed Index isn't larger or smaller  than the Size of Data
        {
                return (*(Data+index)); //Returns the value of Data at Index's location
        }

        else
        {
                cout<<"\n\nYou have accessed Something out of range in Data. Program is now exiting"<<endl; //Informs user of error
                exit(EXIT_FAILURE); //Exits program
        }

}

//equivilent to set
template <class T>
T & Array<T>::operator[](int index)
{
        if(!(index > size() || index < 0)) //Ensures that the inputed Index isn't larger or smaller  than the Size of Data
        {
                return (*(Data+index)); //Returns the value of Data at Index's location
        }

        else
        {
                cout<<"\n\nYou have accessed Something out of range in Data. Program is now exiting"<<endl; //Informs user of error

                exit(EXIT_FAILURE); //Exits program
        }
}

//Checks for equality for the passed objects
template <class T>
bool Array<T>::operator==(const Array<T> & rhs) const
{
      if(size() == rhs.size()) //Ensures both arrays are of the same length
       {
               for(int i = 0; i < size(); i++)
               {
                       if(Data[i] != rhs.Data[i]) //If not all the elements are the same then the arrays are not totally equal and returns false
                       {
                               return false;
                       }
               }

               return true; //All the elements are the same including the size of the arrays
       }

       else
       {
               return false; //Arrays are not the same size
       }
}

//Sets the value of an item to index and value passed to it
template <class T>
void Array<T>::set(int index, T value)
{
        if(!(index > size() || index < 0)) //Ensures that the inputed Index isn't larger or smaller than the Size of Data
        {
                (*(Data+index)) = value; //Sets Value at the requested Index
        }

        else
        {
                cout<<"\n\nYou have accessed something out of range in Data. Program is now exiting"<<endl; //Informs user of error
                exit(EXIT_FAILURE); //Exits program
        }
}

//Gets the value at the passed index      
template <class T>
T Array<T>::get(int index) const
{
        if(!(index > size() || index < 0)) //Ensures that the inputed Index isn't larger or smaller  than the Size of Data
        {
                return (*(Data+index)); //Returns the value of Data at Index's location
        }

        else
        {
                cout<<"\n\nYou have accessed Something out of range in Data. Program is now exiting"<<endl; //Informs user of error
                exit(EXIT_FAILURE); //Exits program
        }
}

////////////////////////////////////////////////////////////////////////////////
//The .h file the professor gave us made it appear as if we were not changing
//the elements in the array but rather that we returned a temperary object that
//had the negated elements in it so if there is an issue please let me know
//but he did not specify how to handle this
///////////////////////////////////////////////////////////////////////////////

//negates every element in the array
template <class T>
const Array<T> Array<T>::operator-() const
{
	Array<T> temp(size());

        for(int i = 0; i < size(); i++)
        {
                temp.set(i, (get(i) * (-1)));
        }
	
	return temp;
}

//Copies the passed array into another array
template <class T>
const Array<T> & Array<T>::operator=(const Array<T> & rhs)
{
        if(size() == rhs.size()) //Ensures both arrays are of the same length
        {
                for(int i = 0; i < size(); i++)
                {
                        set(i,(rhs.get(i))); //Copies the values from ArrayToCopy to data
                }
        }

        else
        {
                cout<<"The arrays do not match in lengh. Program is no exiting"<<endl; //Informs user of error
                exit(EXIT_FAILURE); //Exits program
        }

        return *this;
}

//Adds the values from the passed array and the values
//in the current Array and saves them in temp
template <class T>
const Array<T> Array<T>::operator+(const Array<T>& rhs) const
{
	Array<T> temp(size());
        if(size() == rhs.size()) //Ensures both arrays are of the same size
        {	
                for(int i = 0; i < size(); i++)
                {
                        temp.set(i,(get(i) + rhs.get(i)));
                }
	}

        else
        {
                exit(EXIT_FAILURE);
        }

	return temp;
}

//Subtracts the values from the passed array
//and the array that called the function and
//saves those values in the array that called the function
template <class T>
const Array<T> Array<T>::operator-(const Array<T> & rhs) const
{
	Array<T> temp(size());

        if(size() == rhs.size()) //Ensures both arrays are of the same size
        {
                for(int i = 0; i < size(); i++)
                {
                        //temp.set(i, (get(i) - rhs.get(i)));
			temp.Data[i] = Data[i] - rhs.Data[i];
                }
        }

        else
        {
                exit(EXIT_FAILURE);
        }	
	
	return temp;
}

///////////////////////////////////////////////////////////////////////////////
//I diviated from his .h file since his .h file wanted to return by reference
//the problem with return by reference for this is that there will be a memory leak
//if I return by value I will not get a memory leak and it still works perfectly
//if there is an issue please let me know
////////////////////////////////////////////////////////////////////////////////

//does postfix incrimentation of Data
template <class T>
const Array<T> Array<T>::operator++(int)
{
        Array<T> temp(*this);
        //temp = new Array<T>(*this);
        
	for(int i = 0; i < size(); i++)
        {
                set(i,(get(i) + 1));//Data[i] += 1
        }

        return temp;
}

//does prefix incrimentation of Data
template <class T>
const Array<T> & Array<T>::operator++()
{
        for(int i = 0; i < size(); i++)
        {
                set(i,(get(i) + 1));//Data[i] += 1
        }

        return *this;
}

//prints array
template <class T>
void Array<T>::Print(void) const 
{
        for(int i = 0; i < size(); i++)
        {
                cout<<get(i)<<endl;//Displays contents of Data
        }
}


template<class T>
const Array<T> &  Array<T>::operator+=(const Array<T> &rhs)
{
	if(size() == rhs.size()) //Ensures both arrays are of the same length
        {
                for(int i = 0; i < size(); i++)
                {
                        Data[i] = Data[i] + rhs.Data[i];
                }
        }

        else
        {
                cout<<"The arrays do not match in lengh. Program is no exiting"<<endl; //Informs user of error
                exit(EXIT_FAILURE); //Exits program
        }

        return *this;
}

template<class T>
const Array<T> &  Array<T>::operator-=(const Array<T> &rhs)
{
        if(size() == rhs.size()) //Ensures both arrays are of the same length
        {
                for(int i = 0; i < size(); i++)
                {
                        Data[i] = Data[i] - rhs.Data[i];
                }
        }

        else
        {
                cout<<"The arrays do not match in lengh. Program is no exiting"<<endl; //Informs user of error
                exit(EXIT_FAILURE); //Exits program
        }

        return *this;
}


//destructor
template <class T>
Array<T>::~Array()
{
	delete [] Data; //removes the hold on Data's elements	
}
