#include <fstream>
using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "student.h"
#ifndef STUDENTLIST
#define STUDENTLIST
//will store the data from student which has already processed the attributes of each student
//the vector will use the entirety of "student" as an object
//list will add, drop, change item
//student will take in data to create an entire student
class studentList
{
    private: 
        unsigned int maxSize;
        int nameLength, idLength;
    
    vector<student> sList;
    student sLists[20];

    public:
    studentList(unsigned int size = 0)
    {
        maxSize= size;
        nameLength = student::nameLength;
    }

    bool addStudent(student);
    void writeData(ostream & outfile);
};
#endif