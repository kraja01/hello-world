#include <iostream>  
#include <fstream>  
#include <cstring>  

#include <string>  
#include <iomanip>  
#include "studentList.h"
#include "student.h"
using namespace std;
const int maxSize = 20; //at most 20 employees  
const int nameLength = student::nameLength;   
//const int idLength = employee::idLength; // 8-character Id  
    
studentList sList(maxSize);  // define the employeeList object.
// some more variables used only main  
ofstream outfile;  
ifstream infile;    
char input_file_name[21], output_file_name[21], name[nameLength+1]; 
string id;

void menu(){
	
	cout << "Please specify what you would like to do" << endl;
	cout << "Enter 'A' or 'a' to enter an input file" << endl;
	cout << "Enter 'B' or 'b' to display the raw data from your input file" << endl;
	cout << "Enter 'C' or 'c' to display the raw data in a specific format" << endl;
	cout << "Enter 'D' or 'd' to search for a student by name OR id" << endl;
	cout << "Enter 'E' or 'e' print the processed grades in a tabular form" << endl;
	cout << "Enter 'F' or 'f' to add a student to the table" << endl;
	cout << "Enter 'G' or 'g' to changes a students' test scores"  << endl;
	cout << "Enter 'H' or 'h' to save the modified data then send it to an outfile specified by you" << endl;
		
}

void getFile()  
{  
  student s_temp;  
  float hwScores[10]; //need another one for tests. get this working first 
  float participationScore; 
  float testScores[3];
  float finalExam;
  int i; 
  bool done;
  cout << "Please enter name of the  data file:  ";  
  cin >> input_file_name;  
  infile.open(input_file_name);  
  if ( !infile)  
    {  
      // abandons operation with error mesg  
      cout << "Could not open input file \n";  
      infile.close();  
      infile.clear();  
      return;  
    }  
  infile >> name; 
  int hwsize=0;
  s_temp.setName(name); //read and store name in s_temp 
  while(!infile.eof())  
    {  
      infile >> id; 
      s_temp.setId(id);  //read and store id in s_temp 
      i = 0; 
      // While loop stores the hours worked into an array. The loop
      // reads numbers for hours worked until it sees a '|' character
      // (every employee has a different number of shifts).
      // This approach allows for a variable number of values to be read.
      // If we have  a fixed number of values, a simple for loop is preferable
        for(int i = 0; i < 10; i++)
        {
            infile>>hwScores[i];
            hwsize++;
        }

      s_temp.setHomeworkScores(hwScores, 10);
      infile >> participationScore;
      s_temp.setParticipation(participationScore);
         for(int i = 0; i < 3; i++)
        {
            infile>>testScores[i];
        }
      s_temp.setTestScores(testScores, 3);
      infile >> finalExam; 
      s_temp.setFinal(finalExam); 
      //now add student 
      sList.addStudent(s_temp);
      
     infile >> name; 
      s_temp.setName(name);
    }  

  infile.close();  
  infile.clear();  
}   

  
void displayRawData()
{
  sList.writeData(cout); //rename empList to sList
}

void displayFormattedData(){
	cout<<"formatted data \n";
}

void studentSearch(){
	cout<<"search for student\n";
}

void printGrades(){
	cout << "print all grades" << endl;
}

void addStudent(){
	cout <<"add student \n";
}

void changeTestScore(){
	cout<<"change test score" << endl;
}

void outputFile(){
	cout<<"send data to output file" << endl;
}

int main()  
{  
  
  char choice;  
  
  menu();  
  cout << "Please indicate your choice of operation (m for menu): ";  
  cin >> choice;  
  
  while ((choice != 'H')&& (choice != 'h')){  
      switch(choice){  
		case 'A':  
		case 'a': getFile(); break;  
	    case 'B':
		case 'b': displayRawData(); break;
		case 'C':  
		case 'c': displayFormattedData();break;  
		case 'D':  
		case 'd': studentSearch();break;  
		case 'E':  
		case 'e': printGrades();break;  
		case 'F':  
		case 'f': addStudent();break;  
		case 'G':  
		case 'g': changeTestScore();break;  
		case 'M':  
		case 'm': menu();break;  
		default : cout << "Not a valid choice" << endl;  
		}  
    cin.ignore(200, '\n'); cin.clear(); //clear out all input  
    cout << "Please indicate your choice of operation (m for menu): ";  
    cin >> choice;  
    }  
   	outputFile();  
  	cout << "Thank-you, good bye! \n";  
}