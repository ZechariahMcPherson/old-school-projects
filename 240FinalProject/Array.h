//Gregory Zechariah McPherson
//CSCE 240 Final Project

#ifndef ARRAY_H
#define	ARRAY_H
#include <iostream>
using namespace std;

template <class T>
class Array {
public:
    Array();
    Array(int arraySize, T value);
    Array(T anArray[], int arraySize);
    Array(const Array<T> &orig);
    virtual ~Array();

    const Array<T> & operator=(const Array<T> & rhs);
    const Array<T> operator+(const Array<T> & rhs) const;
    const Array<T> operator-(const Array<T> & rhs) const;
    const Array<T> & operator+=(const Array<T> & rhs);
    const Array<T> & operator-=(const Array<T> & rhs);
    
    const Array<T> & operator++();
    const Array<T> operator++(int dummy); //change to return by value which stopped a memory leak
    const Array<T> operator-() const; //changed to return by value whcich stopped a memory leak 
    
    bool operator==(const Array<T> & rhs) const;
    T operator[](int index) const; // Equivalent to get
    T & operator[](int index); // Equivalent to set

    void Print(void) const;
    void set(int index, T value);
    T get(int index) const;
    int size() const;
    T remove(int index);

    //I had to put this here or it would not compile correctly
    friend ostream & operator<<(ostream & outStream, const Array<T> & rhs)
    {

        cout<<"Printing Array:"<<endl;

        for(int i = 0; i < rhs.size(); i++)
        {
                cout<<rhs.get(i)<<endl;
        }

        return outStream;


    }

    //I had to put this here or it would not compile correctly
    friend istream & operator>>(istream & inStream, Array<T> & rhs)
    {
        int temp;
        for(int i = 0; i < rhs.size(); i++)
        {
                cout<<"Enter Data element "<< i << " " <<endl;
                cin >> temp;
                rhs.set(i, temp);
        }

        return inStream;


    }



private:
    int Size;
    T *Data;
};

#endif	/* ARRAY_H */

