//Nghia Ho
//ID:1251576
//HW2
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "ArgumentManager.h"
#include "orderedLinkedList.h"
//orderLinkedList inherits from linkedListType class

using namespace std;
/////////////////////////////////////////////////////////////////////////
//studentInfo class is a class that take in input from the file, process it into
//student information, then add it to an orderedLinkedList.
//studentInfo class also have function that prints out specifics studentInfo
//from the list when called upon.
class studentInfo
{
public:
/////////////////////////////////////////////////////////////////////////
// Constructor initialize all value
    studentInfo()
    {
        ID_num="00000";
        firstName="";
        lastName="";
        Major="Unknown";
        GPA="0.00";
        currentCredit="0";
    }
    ~studentInfo() {};
/////////////////////////////////////////////////////////////////////////////
//Function that erase whitespace in a nonempty line
    string eraseWS(string& line)
    {
        //for loop that go through all char in a line and eliminate all whitespace
        int size = line.length();
        for(int j = 0; j<=size; j++)
        {
            for(int i = 0; i <=j; i++)
            {
                if(line[i] == ' ' && line[i+1] == ' ')
                {
                    line.erase(line.begin() + i);
                }
                else if(line[0]== ' ')
                {
                    line.erase(line.begin());
                }
                else if(line[i] == '\0' && line[i-1]== ' ')
                {
                    line.erase(line.end() - 1);
                }
            }
        }
        return line;
    }
///////////////////////////////////////////////////////////////////////////////
//Function that check whether a line is not empty
    bool checkline(string line)
    {
        //condiditon for empty line is "" and " "
        if(line==""||line==" ")
        {
            return false;
        }
        else
        {
            return true;
        }
    }
/////////////////////////////////////////////////////////////////////////////
//Function that check if line is a double
    bool checkdouble(string line)
    {
        //a number is a double if it have '.' char inside it
        for(int i=0; i<line.length(); i++)
        {
            if(line.at(i)=='.')
            {
                return true;
            }
        }
        return false;
    }
///////////////////////////////////////////////////////////////////////////////
//Function that check if a line contain a alphabet or not
    bool checkAlpha(string line)
    {
        for(int i=0; i<line.length(); i++)
        {
            if(isalpha(line.at(i)))//Using isalpha() to check line
            {
                return true;
            }
        }
        return false;
    }
////////////////////////////////////////////////////////////////////////////
//Function that reset all value in student info to default
//useful when setting up new set of info
    void resetInfo()
    {
        ID_num="00000";
        firstName="";
        lastName="";
        Major="Unknown";
        GPA="0.00";
        currentCredit="0";
    }
/////////////////////////////////////////////////////////////////////////////
//Semi-insert function that test to see if there are duplicates or not
//If there are no duplicates it will call the orderLinkedList insert function with corresponding parameter
    void INSERT()
    {
        //using searchName/searchID to find if there are a match within the list before inserting
        if(!(studentInfoList.searchName(firstName,lastName))&&!(studentInfoList.searchID(ID_num)))
        {
            studentInfoList.insert(lastName,firstName,ID_num,Major,GPA,currentCredit);

        }
    }
/////////////////////////////////////////////////////////////////////////////
//setstudentInfo function use multiple if statement to check every input line before
//inserting them into the orderedLinkedList with insert function
//My attempt to handle missing inputs
    void setstudentInfo(ifstream &ifs,string line)
    {
        resetInfo();//resetting info before starting
        getline(ifs,line);//getting new line
        line=eraseWS(line);//getting rid of whitespace
        if(checkline(line)) //checking for empty line
        {
            //checking if variable is acceptable for insert
            if(!checkAlpha(line)&&checkline(line)&&!checkdouble(line)&&stoi(line)<=99999&&stoi(line)>=0)
            {
                ID_num=line;
            }
            else //if variable is not acceptable
            {
                //firstName and lastName is always provided so unless line is empty, there is no need for conditions
                if(checkdouble(line)||stoi(line)>99999||stoi(line)<0){
                    getline(ifs,line);
                    line=eraseWS(line);
                }
                firstName=line;
                getline(ifs,line);//getting new line
                line=eraseWS(line);//erasing whitespace
                lastName=line;
                getline(ifs,line);//getting new line
                line=eraseWS(line);//erasing whitespace
                if(checkline(line))//checking empty line
                {
                    if(checkAlpha(line))//checking if variable is acceptable for insert
                    {
                        Major=line;

                        getline(ifs,line);//getting new line
                        line=eraseWS(line);//erasing whitespace
                        if(checkline(line))//checking empty line
                        {
                            //checking if variable is acceptable
                            if(!checkAlpha(line)&&checkline(line)&&checkdouble(line))
                            {
                                if(stod(line)<=4.0&&stod(line)>=0.0)
                                {
                                    GPA=line;
                                }
                                getline(ifs,line);//getting new line
                                line=eraseWS(line);//erasing whitespace
                                //checking if variable is acceptable
                                if(checkline(line)&&!checkAlpha(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)//checking empty line
                                {
                                    currentCredit=line;
                                    INSERT();//call insert function
                                    return;//return to main
                                }
                                else//if variable is not acceptable
                                {
                                    INSERT();//call insert function
                                    return;//return to main
                                }
                            }
                            else//if variable is not acceptable
                            {
                                //checking is variable is acceptable
                                if(!checkAlpha(line)&&checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
                                {
                                    currentCredit=line;
                                    INSERT();//call insert function
                                    return;//return to main
                                }
                                else//if variable is not acceptable
                                {
                                    INSERT();//call insert function
                                    return;//return main
                                }
                            }
                        }
                        else//if variable is not acceptable
                        {
                            INSERT();//call insert function
                            return;//return main
                        }
                    }
                    else//if variable is not acceptable
                    {
                        //check if variable is acceptable
                        if(!checkAlpha(line)&&checkline(line)&&checkdouble(line))
                        {
                            if(stod(line)<=4.0&&stod(line)>=0.0)
                            {
                                GPA=line;
                            }
                            getline(ifs,line);//getting new line
                            line=eraseWS(line);//erasing whitespace
                            if(checkline(line))//checking empty line
                            {
                                currentCredit=line;
                                INSERT();//call insert function
                                return;//return to main
                            }
                            else//if variable is not acceptable
                            {
                                INSERT();//call insert function
                                return;//return to main
                            }
                        }
                        else//if variable is not acceptable
                        {
                            //checking is variable is acceptable
                            if(!checkAlpha(line)&&checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
                            {
                                currentCredit=line;
                                INSERT();
                                return;//return to main
                            }
                            else//if variable is not acceptable
                            {
                                INSERT();
                                return;//return to main
                            }
                        }
                    }
                }
                else//if variable is not acceptable
                {
                    INSERT();//call insert function
                    return;//return to main
                }
            }
        }
        else//if variable is not acceptable
        {
            return;//return to main
        }
/////////////////////////////////////////////////////////////////////////
//firstName and lastName is always provided so unless line is empty, there is no need for additional conditions
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//checking empty line
        {
            firstName=line;
        }
        else//if variable is not acceptable
        {
            return;//return to main
        }
/////////////////////////////////////////////////////////////////////////
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//checking empty line
        {
            lastName=line;
        }
        else//if variable is not acceptable
        {
            return;//return to main
        }
/////////////////////////////////////////////////////////////////////////
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))
        {
            //checking is variable is acceptable
            if(checkAlpha(line))
            {
                Major=line;

                getline(ifs,line);//getting new line
                line=eraseWS(line);//erasing whitespace
                if(checkline(line))//check empty line
                {
                    //checking is variable is acceptable
                    if(!checkAlpha(line)&&checkdouble(line))
                    {
                        if(stod(line)<=4.0&&stod(line)>=0.0)
                        {
                            GPA=line;
                        }
                        getline(ifs,line);//getting new line
                        line=eraseWS(line);//erasing whitespace
                        if(checkline(line))//check empty line
                        {
                            currentCredit=line;
                            INSERT();//call insert function
                            return;//return to main
                        }
                        else//if variable is not acceptable
                        {
                            INSERT();//call insert function
                            return;//return to main
                        }
                    }
                    else//if variable is not acceptable
                    {
                        //checking is variable is acceptable
                        if(checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
                        {
                            currentCredit=line;
                            INSERT();//call insert function
                            return;//return to main
                        }
                        else//if variable is not acceptable
                        {
                            INSERT();//call insert function
                            return;//return to main
                        }
                    }
                }
                else//if variable is not acceptable
                {
                    INSERT();//call insert function
                    return;//return to main
                }
            }
            else//if variable is not acceptable
            {
                //checking is variable is acceptable
                if(checkline(line))
                {
                    if(!checkAlpha(line)&&checkdouble(line))
                    {
                        if(stod(line)<=4.0&&stod(line)>=0.0)
                        {
                            GPA=line;
                        }
                    }
                    getline(ifs,line);//getting new line
                    line=eraseWS(line);//erasing whitespace
                    if(checkline(line))//checking empty line
                    {
                        currentCredit=line;
                        INSERT();//call insert function
                        return;//return to main
                    }
                    else//if variable is not acceptable
                    {
                        INSERT();//call insert function
                        return;//return to main
                    }
                }
                else//if variable is not acceptable
                {
                    //checking is variable is acceptable
                    if(!checkAlpha(line)&&checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
                    {
                        currentCredit=line;
                        INSERT();//call insert function
                        return;//return to main
                    }
                    else//if variable is not acceptable
                    {
                        INSERT();//call insert function
                        return;//return to main
                    }
                }
            }
        }
        else//if variable is not acceptable
        {
            INSERT();//call insert function
            return;//return to main
        }

/////////////////////////////////////////////////////////////////////////                }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//checking empty line
        {
            //checking is variable is acceptable
            if(!checkAlpha(line)&&checkdouble(line))
            {
                if(stod(line)<=4.0&&stod(line)>=0.0)
                {
                    GPA=line;
                }
                getline(ifs,line);//getting new line
                line=eraseWS(line);//erasing whitespace
                if(checkline(line))//check empty line
                {
                    currentCredit=line;
                    INSERT();//if variable is not acceptable
                    return;//return to main
                }
                else//if variable is not acceptable
                {
                    INSERT();//if variable is not acceptable
                    return;//return to main
                }
            }
            else//if variable is not acceptable
            {
                //checking is variable is acceptable
                if(!checkAlpha(line)&&checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
                {
                    currentCredit=line;
                    INSERT();//if variable is not acceptable
                    return;//return to main
                }
                else//if variable is not acceptable
                {
                    INSERT();//if variable is not acceptable
                    return;//return to main
                }
            }
        }

        else//if variable is not acceptable
        {
            INSERT();//if variable is not acceptable
            return;//return to main
        }

/////////////////////////////////////////////////////////////////////////
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        //checking is variable is acceptable
        if(!checkAlpha(line)&&checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
        {
            currentCredit=line;
            INSERT();//if variable is not acceptable
        }
        else//if variable is not acceptable
        {
            INSERT();//if variable is not acceptable
            return;//return to main
        }
    }

/////////////////////////////////////////////////////////////////////////////
//Function that call print function from ordererLinkedList
    void PRINT_ROSTER(ofstream& ofs)const
    {
        studentInfoList.printRoster(ofs);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void PRINT_BY_MAJOR(ifstream &ifs,ofstream& ofs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))
        {
            Major=line;
        }
        else//if line is empty
        {
            return;
        }
        studentInfoList.printMajor(Major,ofs);
    }
//////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void PRINT_BY_GPA(ifstream &ifs,ofstream& ofs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            GPA=line;
        }
        else//if line is empty
        {
            return;
        }
        studentInfoList.printGPA(GPA,ofs);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void PRINT_STUDENT(ifstream &ifs,ofstream& ofs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            firstName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            lastName=line;
        }
        else//if line is empty
        {
            return;
        }
        studentInfoList.printStudent(firstName,lastName,ofs);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void DELETE_STUDENT(ifstream &ifs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            firstName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            lastName=line;
        }
        else//if line is empty
        {
            return;
        }
        studentInfoList.deleteStudent(firstName,lastName);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void DELETE_ID(ifstream &ifs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            ID_num=line;
        }
        else//if line is empty
        {
            return;
        }
        studentInfoList.deleteID(ID_num);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void UPDATE_GPA(ifstream &ifs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            firstName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            lastName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        //check if variable is acceptable
        if(checkline(line)&&checkdouble(line)&&stod(line)<=4.0&&stod(line)>=0.0)
        {
            GPA=line;
        }
        else//if line is empty
        {
            return;
        }
        studentInfoList.updateGPA(firstName,lastName,GPA);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void UPDATE_MAJOR(ifstream &ifs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            firstName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))
        {
            lastName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line)&&checkAlpha(line))//check empty line
        {
            Major=line;
        }
        else//if line is empty
        {
            return;
        }
        studentInfoList.updateMajor(firstName,lastName,Major);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void ADD_CLASS(ifstream &ifs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            firstName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            lastName=line;
        }
        else//if line is empty
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        //check is variable is acceptable
        if(checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
        {
            currentCredit=line;
        }
        else
        {
            return;
        }
        studentInfoList.addClass(firstName,lastName,currentCredit);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void REMOVE_CLASS(ifstream &ifs,string line)
    {
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            firstName=line;
        }
        else
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        if(checkline(line))//check empty line
        {
            lastName=line;
        }
        else
        {
            return;
        }
        getline(ifs,line);//getting new line
        line=eraseWS(line);//erasing whitespace
        //check if variable is acceptable
        if(checkline(line)&&!checkdouble(line)&&stoi(line)<=15&&stoi(line)>=0)
        {
            currentCredit=line;
        }
        else
        {
            return;
        }
        studentInfoList.removeClass(firstName,lastName,currentCredit);
    }
/////////////////////////////////////////////////////////////////////////////
//Function that process multiple line for the corresponding information.
//After getting the right information the function will call whatever corresponding
//function in orderedLinkedList
    void AVERAGE_GPA(ofstream &ofs)
    {
        studentInfoList.averageGPA(ofs);
    }


private:
    //initializing all variable/list here
    //all variable will be string so everything will fit
    //in a string linked list
    string ID_num;
    string firstName;
    string lastName;
    string Major;
    string GPA;
    string currentCredit;
    orderedLinkedList<string> studentInfoList;
};


int main(int argc, char* argv[])
{
    ifstream ifs("1.txt");
    ofstream ofs("out.txt");
   /*
    if(argc<2)
    {
        cout<<"Usage: uni_roster \"A=<file>;C=<file>\""<<endl;
    }
    ArgumentManager am(argc, argv);
    //initializing input and output stream variable with their correspond file call
    ifstream ifs((am.get("A")).c_str());
    ofstream ofs((am.get("C")).c_str());
    //initializing line and studentInfo object
*/
    string line;
    studentInfo userInfo;

    //Loop that read every line looking for program call out
    while(getline(ifs,line))
    {
        userInfo.eraseWS(line);//erasing whitespace
        if(line=="INSERT")//if line call for INSERT
        {
            userInfo.setstudentInfo(ifs,line);//call corresponding studentInfo function
        }
        if(line=="PRINT_ROSTER")//if line call for PRINT_ROSTER
        {
            userInfo.PRINT_ROSTER(ofs);//call corresponding studentInfo function
        }
        if(line=="PRINT_BY_MAJOR")//if line call for PRINT_BY_MAJOR
        {
            userInfo.PRINT_BY_MAJOR(ifs,ofs,line);//call corresponding studentInfo function
        }
        if(line=="PRINT_BY_GPA")//if line call for PRINT_BY_GPA
        {
            userInfo.PRINT_BY_GPA(ifs,ofs,line);//call corresponding studentInfo function
        }
        if(line=="PRINT_STUDENT")//if line call for PRINT_STUDENT
        {
            userInfo.PRINT_STUDENT(ifs,ofs,line);//call corresponding studentInfo function
        }
        if(line=="DELETE_STUDENT")//if line call for DELETE_STUDENT
        {
            userInfo.DELETE_STUDENT(ifs,line);//call corresponding studentInfo function
        }
        if(line=="DELETE_ID")//if line call for DELETE_D
        {
            userInfo.DELETE_ID(ifs,line);//call corresponding studentInfo function
        }
        if(line=="UPDATE_GPA")//if line call for UPDATE_GPA
        {
            userInfo.UPDATE_GPA(ifs,line);//call corresponding studentInfo function
        }
        if(line=="UPDATE_MAJOR")//if line call for UPDATE_MAJOR
        {
            userInfo.UPDATE_MAJOR(ifs,line);//call corresponding studentInfo function
        }
        if(line=="ADD_CLASS")//if line call for ADD_CLASS
        {
            userInfo.ADD_CLASS(ifs,line);//call corresponding studentInfo function
        }
        if(line=="REMOVE_CLASS")//if line call for REMOVE_CLASS
        {
            userInfo.REMOVE_CLASS(ifs,line);//call corresponding studentInfo function
        }
        if(line=="GPA")//if line call for GPA
        {
            userInfo.AVERAGE_GPA(ofs);//call corresponding studentInfo function
        }
    }

    return 0;
}



