#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H
#include <iostream>


//inititalize struct nodeTYPE to take in 6 info
template <class Type>
struct nodeType
{
    Type info;
    Type info2;
    Type info3;
    Type info4;
    Type info5;
    Type info6;
    nodeType<Type> *link;
};


template <class Type>
class linkedListIterator
{
public:
    //Default constructor
    linkedListIterator();
    //Constructor with a parameter.
    linkedListIterator(nodeType<Type> *ptr);
    //Function to overload the dereferencing operator *.
    Type operator*();
    //Overload the preincrement operator.
    linkedListIterator<Type> operator++();
    //Overload the equality operator.
    bool operator==(const linkedListIterator<Type>& right) const;
    //Overload the not equal to operator.
    bool operator!=(const linkedListIterator<Type>& right) const;
private:
    nodeType<Type> *current;
//pointer to point to the current
//node in the linked list
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}
template <class Type>
linkedListIterator<Type>::
linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}
template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}
template <class Type>
bool linkedListIterator<Type>::operator==
(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}
template <class Type>
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}



#endif // LINKEDLISTITERATOR_H
