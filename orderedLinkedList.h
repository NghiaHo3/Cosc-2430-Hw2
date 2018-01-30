#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>
#include <string>
#include "linkedListType.h"



template <class Type>
//orderLinkedList inherits from linkedListType
class orderedLinkedList: public linkedListType<Type>
{
public:
    //Function that search the list for a given item
    bool search(const Type& searchItem) const;
    //Function to insert newItem in the list.
    void insert(const Type& newItem,const Type& newItem2,const Type& newItem3,
                const Type& newItem4,const Type& newItem5,const Type& newItem6);
    //Function to insert newItem at the beginning of the list.
    void insertFirst(const Type& newItem,const Type& newItem2,const Type& newItem3,
                    const Type& newItem4,const Type& newItem5,const Type& newItem6);
    //Function to insert newItem at the end of the list.
    void insertLast(const Type& newItem,const Type& newItem2,const Type& newItem3,
                    const Type& newItem4,const Type& newItem5,const Type& newItem6);
    //Function to delete deleteItem from the list.
    void deleteNode(const Type& deleteItem);
    //Function to print out roster
    void printRoster(ofstream& ofs) const;
    //Function to print out all the student with corresponding major
    void printMajor(const Type& studentMajor,ofstream& ofs)const;
    //Function to print out all the student with the corresponding GPA or higher
    void printGPA(const Type& GPAverage,ofstream& ofs)const;
    //Function to print out the corresponding student
    void printStudent(const Type& firstName,const Type& lastName,ofstream& ofs)const;
    //Function to delete the corresponding student
    void deleteStudent(const Type& firstName,const Type& lastName);
    //Function to delete the student with the corresponding student ID
    void deleteID(const Type& studentID);
    //Function to update the corresponding student GPA
    void updateGPA(const Type& firstName,const Type& lastName, const Type& GPA);
    //Function to update the corresponding student major
    void updateMajor(const Type& firstName,const Type& lastName, const Type& Major);
    //Function to add class to the corresponding student
    void addClass(const Type& firstName,const Type& lastName,const Type& currentCredit);
    //Function to remove class from the corresponding student
    void removeClass(const Type& firstName,const Type& lastName,const Type& currentCredit);
    //Function to find the average GPA of all student in the List
    void averageGPA(ofstream& ofs)const;
    //Function that search the list for a given name
    bool searchName(const Type& firstName,const Type& lastName)const;
    //Function that search the list for a given ID
    bool searchID(const Type& studentID)const;

};
/////////////////////////////////////////////////////////////////////////
//Function to find an item in the list
template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list
    current=this->first; //start the search at the first node
    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    if (found)
        found = (current->info == searchItem); //test for equality
    return found;
}//end search
/////////////////////////////////////////////////////////////////////////
//Insert function that add items to the list
//In this case it add all given student info to a new node
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem,const Type& newItem2,const Type& newItem3,
                                     const Type& newItem4,const Type& newItem5,const Type& newItem6)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode; //pointer to create a node
    bool found;
    newNode = new nodeType<Type>; //create the node
    //store newItem in the node
    newNode->info = newItem;//lastName
    newNode->info2=newItem2;//firstName
    newNode->info3=newItem3;//studentID
    newNode->info4=newItem4;//Major
    newNode->info5=newItem5;//GPA
    newNode->info6=newItem6;//currentCredit
    newNode->link = NULL; //set the link field of the node
    //to NULL
    if (this->first == NULL) //Case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;
        while (current != NULL && !found) //search the list
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == this->first) //Case 2
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL)
                this->last = newNode;
            this->count++;
        }
    }//end else
}//end insert

/////////////////////////////////////////////////////////////////////////
//Function that insert item first

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem,const Type& newItem2,const Type& newItem3,
                                        const Type& newItem4,const Type& newItem5,const Type& newItem6)
{
    insert(newItem,newItem2,newItem3,newItem4,newItem5,newItem6);
}//end insertFirst
/////////////////////////////////////////////////////////////////////////
//Function that insert item last
template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem,const Type& newItem2,const Type& newItem3,
                                        const Type& newItem4,const Type& newItem5,const Type& newItem6)
{
    insert(newItem,newItem2,newItem3,newItem4,newItem5,newItem6);
}//end insertLast
/////////////////////////////////////////////////////////////////////////
//Function that delete an item in the list
template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    if (this->first == NULL) //Case 1
        std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = this->first;
        found = false;
        while (current != NULL && !found) //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == NULL) //Case 4
            std::cout << "The item to be deleted is not in the list."
                      << std::endl;
        else if (current->info == deleteItem) //the item to be
//deleted is in the list
        {
            if (this->first == current) //Case 2
            {
                this->first = (this->first)->link;
                if (this->first == NULL)
                    this->last = NULL;
                delete current;
            }
            else //Case 3
            {
                trailCurrent->link = current->link;
                if (current == this->last)
                    this->last = trailCurrent;
                delete current;
            }
            this->count--;
        }
        else //Case 4
            std::cout << "The item to be deleted is not in the "<< "list." << std::endl;
    }
}//end deleteNode
/////////////////////////////////////////////////////////////////////////
//Function that print out all firstName/lastName/studentID in the list
template <class Type>
void orderedLinkedList<Type>:: printRoster(ofstream& ofs) const
{
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first;//set current point to the first node
    while (current != NULL) //while more data to print
    {
        std::cout << current->info2<<" "<<current->info<<", "<<current->info3<<std::endl;
        ofs << current->info2<<" "<<current->info<<", "<<current->info3<<endl;
        current = current->link;
        ofs<<endl;
        cout<<endl;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that print out all firstName/lastName/studentID in the list
//with the same major as the one given
template <class Type>
void orderedLinkedList<Type>:: printMajor(const Type& studentMajor,ofstream& ofs) const
{
    int counter=0;//counter here so that it won't print out a new line if no student have same major
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        if(studentMajor==(current->info4))
        {
            std::cout <<current->info2<<" "<<current->info<<", "<< current->info3<<"\n";
            ofs <<current->info2<<" "<<current->info<<", "<< current->info3<<endl;
            counter++;
        }
        current=current->link;

    }
    if(counter>0){
        ofs<<endl;
        cout<<endl;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that print out all firstName/lastName/studentID in the list
//with the same GPA or higher than given GPA
template <class Type>
void orderedLinkedList<Type>:: printGPA( const Type& GPAverage,ofstream& ofs) const
{
    int counter=0;
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        if(stod(GPAverage)<=stod((current->info5)))
        {
            std::cout <<current->info2<<" "<<current->info<<", "<< current->info3<<std::endl;
            ofs <<current->info2<<" "<<current->info<<", "<< current->info3<<endl;
            counter++;
        }
        current=current->link;
    }
    if(counter>0){
        ofs<<endl;
        cout<<endl;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that print out all firstName/lastName/studentID in the list
//with the same name as the one given
template <class Type>
void orderedLinkedList<Type>:: printStudent(const Type& firstName,const Type& lastName,ofstream& ofs)const
{
    int counter=0;
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        if(firstName==(current->info2)&&lastName==(current->info))
        {
            std::cout <<current->info2<<" "<<current->info<<", "<< current->info3<<std::endl;
            std::cout<<"Major: "<<current->info4<<std::endl;
            std::cout<<"GPA: "<<fixed<<setprecision(2)<<stod(current->info5)<<std::endl;
            std::cout<<"Credits Enrolled: "<<current->info6<<std::endl;

            ofs<<current->info2<<" "<<current->info<<", "<< current->info3<<std::endl;
            ofs<<"Major: "<<current->info4<<std::endl;
            ofs<<"GPA: "<<fixed<<setprecision(2)<<stod(current->info5)<<std::endl;
            ofs<<"Credits Enrolled: "<<current->info6<<std::endl;
            counter++;
        }
        current=current->link;
    }
    if(counter>0){
        ofs<<endl;
        cout<<endl;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that delete a student with the same firstName and lastName as the ones given
template <class Type>
void orderedLinkedList<Type>::deleteStudent(const Type& firstName,const Type& lastName)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    if (this->first == NULL) //Case 1
        std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = this->first;
        found = false;
        while (current != NULL && !found) //search the list
            if ((current->info2 >= firstName)&&(current->info >=lastName))
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == NULL) //Case 4
            std::cout << "The item to be deleted is not in the list."<< std::endl;
        else if ((current->info2 == firstName)&&(current->info==lastName)) //the item to be
//deleted is in the list
        {
            if (this->first == current) //Case 2
            {
                this->first = (this->first)->link;
                if (this->first == NULL)
                    this->last = NULL;
                delete current;
            }
            else //Case 3
            {
                trailCurrent->link = current->link;
                if (current == this->last)
                    this->last = trailCurrent;
                delete current;
            }
            this->count--;
        }
        else //Case 4
            std::cout << "The item to be deleted is not in the "<< "list." << std::endl;
    }
}//end delete
/////////////////////////////////////////////////////////////////////////
//Function that delete a student with the same ID number as the one given
template <class Type>
void orderedLinkedList<Type>::deleteID(const Type& ID_num)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    if (this->first == NULL) //Case 1
        std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = this->first;
        found = false;
        while (current != NULL && !found) //search the list
            if (current->info3 == ID_num)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == NULL) //Case 4
            std::cout << "The item to be deleted is not in the list."<< std::endl;
        else if (current->info3 == ID_num) //the item to be
//deleted is in the list
        {
            if (this->first == current) //Case 2
            {
                this->first = (this->first)->link;
                if (this->first == NULL)
                    this->last = NULL;
                delete current;
            }
            else //Case 3
            {
                trailCurrent->link = current->link;
                if (current == this->last)
                    this->last = trailCurrent;
                delete current;
            }
            this->count--;
        }
        else //Case 4
            std::cout << "The item to be deleted is not in the "<< "list." << std::endl;
    }
}//end delete
/////////////////////////////////////////////////////////////////////////
//Function that update the gpa of a student with the same firstName and lastName as the one given
template <class Type>
void orderedLinkedList<Type>:: updateGPA(const Type& firstName,const Type& lastName, const Type& GPA)
{

    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        if(firstName==(current->info2)&&lastName==(current->info))
        {
            (current->info5)=GPA;
        }
        current = current->link;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that update the major of a student with the same firstName and lastName as the one given
template <class Type>
void orderedLinkedList<Type>:: updateMajor(const Type& firstName,const Type& lastName, const Type& Major)
{

    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        if(firstName==(current->info2)&&lastName==(current->info))
        {
            (current->info4)=Major;
        }
        current = current->link;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that add class to a student with the same firstName and lastName as the one given
template <class Type>
void orderedLinkedList<Type>:: addClass(const Type& firstName,const Type& lastName,const Type& currentCredit)
{
    int temp;
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        if(firstName==(current->info2)&&lastName==(current->info))
        {
            temp=stoi(current->info6)+stoi(currentCredit);
            if(temp<=15&&temp>=0){
            current->info6=to_string(temp);
            }
        }
        current = current->link;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that remove class from a student with the same firstName and lastName as the one given
template <class Type>
void orderedLinkedList<Type>:: removeClass(const Type& firstName,const Type& lastName,const Type& currentCredit)
{
    int temp;
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        if(firstName==(current->info2)&&lastName==(current->info))
        {
            temp=stoi(current->info6)-stoi(currentCredit);
            if(temp<=15&&temp>=0){
            current->info6=to_string(temp);
            }
        }
        current = current->link;
    }
}
/////////////////////////////////////////////////////////////////////////
//Function that calculate the average GPA within the list
template <class Type>
void orderedLinkedList<Type>:: averageGPA(ofstream& ofs)const
{
    double gpaTotal=0.0;
    double gpaAverage=0.0;
    nodeType<Type> *current; //pointer to traverse the list
    current = this->first; //set current point to the first node
    if(current==NULL){
        return;
    }
    while (current != NULL) //while more data to print
    {
        gpaTotal+=stod(current->info5);
        current = current->link;
    }
    gpaAverage=gpaTotal/this->count;
    std::cout <<"GPA mean: "<<fixed<<setprecision(2)<<gpaAverage<<endl;
    ofs <<"GPA mean: "<<fixed<<setprecision(2)<<gpaAverage<<endl;
    ofs<<endl;
    cout<<endl;
}
template <class Type>
bool orderedLinkedList<Type>::searchName(const Type& firstName,const Type& lastName) const
//Function that search the list for a given name
{
    string fullName=firstName+lastName;
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list
    current=this->first; //start the search at the first node
    while (current != NULL && !found)
        if (fullName<=(current->info2)+(current->info))
            found = true;
        else
            current = current->link;
    if (found)
        found = (fullName==(current->info2)+(current->info)); //test for equality
    return found;
}//end search
/////////////////////////////////////////////////////////////////////////
//Function that search the list for a given ID
template <class Type>
bool orderedLinkedList<Type>::searchID(const Type& studentID) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list
    current=this->first; //start the search at the first node
    while (current != NULL && !found)
        if (current->info3 >= studentID)
            found = true;
        else
            current = current->link;
    if (found)
        found = (current->info3 == studentID); //test for equality
    return found;
}//end search
#endif // ORDEREDLINKEDLIST_H
