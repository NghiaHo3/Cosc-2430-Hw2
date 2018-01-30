#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include "linkedListIterator.h"
#include <iostream>
#include <cassert>

template <class Type>
class linkedListType
{
public:
    //Overload the assignment operator.
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    //Initialize the list to an empty state.
    void initializeList();
    //Function to determine whether the list is empty.
    bool isEmptyList() const;
    //Function to output the data contained in each node.
    void print() const;
    //Function to return the number of nodes in the list.
    int length() const;
    //Function to delete all the nodes from the list.
    void destroyList();
    //Function to return the first element of the list.
    Type front() const;
    //Function to return the last element of the list.
    Type back() const;
    //Function to determine whether searchItem is in the list.
    virtual bool search(const Type& searchItem) const = 0;
    //Function to insert newItem at the beginning of the list.
    virtual void insertFirst(const Type& newItem,const Type& newItem2,const Type& newItem3,
                            const Type& newItem4,const Type& newItem5,const Type& newItem6) = 0;
    //Function to insert newItem at the end of the list.
    virtual void insertLast(const Type& newItem,const Type& newItem2,const Type& newItem3,
                            const Type& newItem4,const Type& newItem5,const Type& newItem6) = 0;
    //Function to delete deleteItem from the list.
    virtual void deleteNode(const Type& deleteItem) = 0;
    //Function to return an iterator at the beginning of the
    //linked list.
    linkedListIterator<Type> begin();
    //Function to return an iterator one element past the
    //last element of the linked list.
    linkedListIterator<Type> end();
    //default constructor
    linkedListType();
    //copy constructor
    linkedListType(const linkedListType<Type>& otherList);
    //destructor
    //Deletes all the nodes from the list.
    ~linkedListType();

protected:
    int count; //variable to store the number of list elements
//
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last; //pointer to the last node of the list
private:
    //Function to make a copy of otherList.
    void copyList(const linkedListType<Type>& otherList);

};

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
}

template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp; //pointer to deallocate the memory
//occupied by the node
    while (first != NULL) //while there are nodes in the list
    {
        temp = first; //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp; //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
//been set to NULL by the while loop
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList(); //if the list has any nodes, delete them
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; //pointer to traverse the list
    current = first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        std::cout << current->info<<"\n";
        current = current->link;
    }
}//end print

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);
    return first->info; //return the info of the first node
}//end front

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);
    return last->info; //return the info of the last node
}//end back

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}

template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list
    if (first != NULL) //if the list is nonempty, make it empty
        destroyList();
    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the
//list to be copied
        count = otherList.count;
//copy the first node
        first = new nodeType<Type>; //create the node
        first->info = current->info; //copy the info
        first->link = NULL; //set the link field of the node to NULL
        last = first; //make last point to the first node
        current = current->link; //make current point to the next
// node
//copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>; //create a node
            newNode->info = current->info; //copy the info
            newNode->link = NULL; //set the link of newNode to NULL

            last->link = newNode; //attach newNode after last
            last = newNode; //make last point to the actual last
//node
            current = current->link; //make current point to the
//next node
        }//end while
    }//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType
(const linkedListType<Type>& otherList)
{
    first = NULL;
    copyList(otherList);
}//end copy constructor

//overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    return *this;
}

#endif // LINKEDLISTTYPE_H
