    // Programming Technique II

//? EXERCISE 3: STRING MANIPULATIONS
//? file: custom_string.cpp

//!----------------------------------------------------------------------------------------
//! This is the only file that you will need to modify in this exercise.
//! And, submit only this file.
//! This file is the implementation for the class CustomString.
//!----------------------------------------------------------------------------------------


/// Programming Technique II

// Member 1's Name: Nasaaie Bin Noriskamar
// Member 2's Name: Muhammad Fairuz bin Herman
//
// Section: 02
// Member 1's Name: Nasaaie Bin Noriskamar    Location: K11,Ktr Utm SKudai (i.e. where are you currently located)
// Member 2's Name: Muhammad Fairuz bin Herman  Location: K11 KTR UTM Skudai

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

// Video link:
//   _________


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "custom_string.hpp"

//?----------------------------------------------------------------------------------------
//? The following methods are fully given: a constructor, getData() and setData()
//?----------------------------------------------------------------------------------------

CustomString::CustomString(const string &_data) : data(_data) {}
string CustomString::getData() const { return data; }
void CustomString::setData(const string &_data) { data = _data; }

//! Task 1: Complete the implementation of the following mutator methods:
//!        (a) pushFront()
//!        (b) pushBack()
//!        (c) pop()
//!        (d) popFront()
//!        (e) popBack()

void CustomString::pushFront(const string &s)
{
    data= s + data; // TASK 1(a)
}

void CustomString::pushBack(const string &s)
{
    data = data + s; // Task 1b
}

string CustomString::pop(int index, int count)
{
    string extracted = data.substr(index,count);
    data.erase(index, count) ;

    return extracted; //Task 1c
}

string CustomString::popFront(int count)
{
    return pop(0,count); // Task 1d
}

string CustomString::popBack(int count)
{
    int startIndex= data.length() - count;
    return pop(startIndex, count); //Task 1e
}

//! Task 2: Complete the implementation of the following overloaded operators:
//!        (a) operator !
//!        (b) operator *

CustomString CustomString::operator!() const
{
    string reversedData = data; // Task 2a
    reverse(reversedData.begin(),reversedData.end());
    return CustomString(reversedData);
}

CustomString CustomString::operator*(int count) const
{
    string repeatedData="";
    for (int i=0;i<count;i++){
        repeatedData += data;
    }
    return CustomString(repeatedData); //Task 2b
}

//! Task 3: Complete the implementation of the following conversion methods:
//!        (a) toDouble()
//!        (b) toUpper()

double CustomString::toDouble() const
{
    return stod(data);// Task 3a
}

CustomString CustomString::toUpper() const
{
    string upperData = data; // Task 3b
    for ( int i = 0; i < upperData.length(); i++)
    {
        upperData[i] = toupper(upperData[i]);
    }
    return CustomString(upperData);
}