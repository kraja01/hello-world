//studentlist.cpp
//  with the command "g++ -c  studentList.cpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "studentList.h"
#include<vector>
using namespace std;
/*------------------------------------------------------------------------
Functions for handling and processing the list of students
-------------------------------------------------------------------------*/
bool studentList::addStudent(student emp)
{  
  //cout << maxSize << endl;
  if ((sList.size()) >= maxSize)
     return false;  
  sList.push_back(emp);
 // sLists[0]= emp;
 
  return true;  
}  
void studentList::writeData(ostream& outfile)
{
    //sLists[0].writeStudent(outfile);
  for(unsigned int index = 0; index < sList.size(); index++)
    {       
      (sList.at(index)).writeStudent(outfile);
        
       outfile << endl;
    }
}