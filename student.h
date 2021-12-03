#include <iostream>  
#include <fstream>  
#include <cstring>  
#include <string> 
#include <iomanip> 
#ifndef STUDENT
#define STUDENT 
using namespace std;
//name, id, test scores, 10 homework scores(stored in an array), participation score, aggregated test
//and homework scores and the letter grade
//test conditions in main like score < 100 && score > 0
class student
{
    public:

        const static int nameLength = 100;
        const static int idLength = 10;
        const static int numOfTests = 3;
        const static int numOfFinal = 1;
        const static int numOfHW = 10;
        const static int numOfParticipationScores = 1;

    private:
        char name[nameLength];
        string id;
        float testScore;
        float testScores[numOfTests];
        float threeTestTotal;
        float finalTestScore;
        float hwScore;
        float hwScores[numOfHW];
        float hwScoreTotal;
        float participationScore;
        float agTests, agHP;

    public:

        void setName(char n[])
        {
          strcpy(name, n); 
        } 

        void setId(string n)
        {
            id = n;
        }
        
        void setHomeworkScores(float tenHW[], int size)
        {
            hwScore = (size < numOfHW) ? size : numOfHW;
            for(int i = 0; i < numOfHW; i++)
            {
                hwScores[i] = tenHW[i];
                hwScoreTotal = hwScoreTotal + hwScores[i];
            }
        }

        void setParticipation(float pScore)
        {
            participationScore = pScore;
        }

        void setTestScores(float threeTests[], int size) //3 tests excluding the final exam
        {
            testScore = (size < numOfTests) ? size : numOfTests;
            for(int i = 0; i < numOfTests; i++)
            {
                testScores[i] = threeTests[i];
                threeTestTotal = testScores[i] + testScores[i + 1];
            }
        }

        void setFinal(float finalExam)
        {
            finalTestScore = finalExam;
        }

        char* getName() //returns name
        {
            return name;
        }

        string getId() //returns id
        {
            return id;
        }
        
        float* getHomeworkScores() //returns array of 10 hw scores
        {
            return hwScores;
        }

        float getParticipation() //returns participation score
        {
            return participationScore;
        }

        float* getTestScores() //returns array of three test scores
        {
            return testScores;
        }

        float getFinal() //returns final
        {
            return finalTestScore;
        }

        float getTestTotal() //returns combo of three tests
        {
            return threeTestTotal;
        }

        float getHWTotal()
        {
            return hwScoreTotal;
        }

        void setAGTests()
        {
            agTests = (threeTestTotal + (2*finalTestScore))/10;
        }

        float getAGTests() //returns aggregate of three tests and final
        {
            return agTests;
        }

        void setAGHP()
        {
            agHP = (hwScoreTotal + participationScore)/20;
        }

        float getAGHP() //returns aggregate of homework and participation score
        {
            return agHP;
        }

        void writeStudent(ostream& outfile)
        {
            // char space = ' ';
            // outfile << name << space << id << space << hwScores << space << participationScore
            // << space << testScores << space << finalTestScore << space << agTests << space << agHP << endl;
            char space = ' ';
            outfile << name << space << id << space;
            for (int i = 0; i < numOfHW; i++)
            {
                outfile << hwScores[i] << space;
            }
            outfile << participationScore << space; 
            for(int i = 0; i < numOfTests; i++)
            {
                outfile << testScores[i] << space;
            }
            outfile << finalTestScore;
        }
        //-----------------------NEW STUFF ---------------------------------//
        void processEmployee()  
        {  
            float hours = 0; 
            bool error = false; 
            
            for (int i = 0; i < workPeriods; i++)
            {
                hours += hrsWorked[i];
                if ((hrsWorked[i] < 0) || (hrsWorked[i] > 16))
                error = true;
            }

            if(error)
            {
                hours = -1;
            }
            computeSalary(hours);  
            computeWithholding();  
            netSalary = Salary-withholding;  
        }  


        void printPersonalInfo(ostream& outfile)  
            {  
            // prints a multi-line report 
            // listing all the fixed personal information  
            
            outfile <<  "Name:   "<<  name << endl  
                <<  "Id:   "<<  id << endl   
                << "Hourly Wage:  " << hrlyWage << endl  
                << "Deductions:   " << deductions << endl  
                <<"-------------------------------------------------"<<endl 
                << endl;  
            }  
        
        
        
        void printRecord( ostream& outfile)  
        {  
            // prints on one line with uniform field widths  
            // describing the week's paycheque  
            outfile << setw(nameLength+2)<<  name   
                <<  setw(idLength+2) <<  id   
                << setw(10) << Salary   
                << setw(10) << withholding  
                << setw(10) << netSalary  << endl;   
        }  
        
        void writeEmployee(  ostream& outfile)  
        {
            // saves the raw data to the specified stream
            
            char space = ' ';
            outfile << name << space << id << space;
            for (int i = 0; i < workPeriods; i++)
                outfile << hrsWorked[i] << space;
            outfile << hrlyWage << space; 
            outfile << deductions; 
        } 

        void printReport( ostream& outfile)
        {     // prints a multi-line report for employee
            // describing the week's paycheque

            outfile <<  "Name:   "<<  name << endl
                    <<  "Id:   "<<  id << endl
                    << "Aggregate HW and Participation Score:  " << Salary << endl
                    << "Aggregate Test Score:   " <<  withholding << endl
                    << "Letter Grade:   " << netSalary  << endl
                    <<"-------------------------------------------------"<<endl;
        }
};
#endif