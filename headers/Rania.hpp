#ifndef MEMBER3_HPP
#define MEMBER3_HPP
#include <iostream>
namespace linked_lists
{

struct CharNode
{
    char data;
    CharNode *next = nullptr;
};

struct CharLL
{
    CharNode *front;
};


struct DoubleNode
{
    double data;
    DoubleNode *next = nullptr;
};

struct DoubleLL
{
    DoubleNode *front;
};


void insertFront(CharLL &list, char data)
{
    CharNode *pointer = new CharNode;
    pointer->next = list.front;
    list.front = pointer;
    pointer->data = data;
}
void insertBack(CharLL &list, char data)
{
    CharNode *current = list.front;
    if (list.front == nullptr)
    {
       current = new CharNode;
       current->data = data;
       current->next = nullptr;
       list.front = current;
    }
    else
    {

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new CharNode;
        current->next ->data = data;
        current->next ->next = nullptr;
    }
}
void printAll(CharLL &list)
{
    CharNode *current = list.front;
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
        
    }
}
void removeFront(CharLL &list)
{
    CharNode *current = list.front;
    list.front = list.front->next;
    delete current;
}
void removeBack (CharLL &list)
{
    CharNode *precurrent = list.front;
    CharNode *current = list.front->next;
    while (current->next != nullptr)
    {
        precurrent = precurrent->next;
        current = current->next;
    }
    precurrent->next = nullptr;
    delete current;
}
char front(CharLL &list)
{
    return list.front->data;
    ;
}
char back(CharLL &list)
{
    CharNode *current = list.front;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current->data;
}
int size(CharLL &list)
{
    CharNode *current = list.front;

    int size = 0;
    while (current != nullptr)
    {
        current = current->next;
        ++size;
    }
    return size;
}
bool isEmpty(CharLL &list)
{
    if (list.front == nullptr)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void filter(CharLL &list, int givendata)
{

    CharNode *precurrent = list.front;
    CharNode *current = precurrent->next;
    if (list.front->data == givendata)
    {
        list.front = current;
        delete precurrent;
    }
    else
    {
        while (current->data != givendata)
        {
            precurrent = current;
            current = current->next;
        }
        precurrent->next = current->next;
        delete current;
    }
}
char getAt(CharLL &list, int index)
{
    CharNode *current = list.front;
    for (int i = 1; i < index; ++i)
    {
        current = current->next;
    }
    return current->data;
}
void removeAt(CharLL &list, int index)
{
    CharNode *current = list.front->next;
    CharNode *precurrent = list.front;
    for (int i = 1; i < index - 1; ++i)
    {
        precurrent = current;
        current = current->next;
    }
    precurrent->next = current->next;
    delete current;
}
void clear(CharLL &list)
{
   while (list.front != nullptr)
    {
       CharNode *current = list.front;
        list.front = list.front->next;
        delete current;
    }
}





void insertFront(DoubleLL &list, double data)
{

   DoubleNode *pointer = new DoubleNode;
   pointer-> next = list.front;
   list.front = pointer;
   pointer->data = data;

}
void insertBack(DoubleLL &list, double data)
{
    DoubleNode *current = list.front;
    if (list.front == nullptr)
    {
        current = new DoubleNode;
        current->data = data;
        current->next = nullptr;
        list.front = current;
    }
    else
    {

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new DoubleNode;
        current->next ->data = data;
        current->next -> next = nullptr;
    }
}
void printAll(DoubleLL &list)
{
    DoubleNode *current = list.front;
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
        
    }
}
void removeFront(DoubleLL &list)
{
    DoubleNode *current = list.front;
    list.front = list.front->next;
    delete current;
}
void removeBack (DoubleLL &list)
{
    DoubleNode *precurrent = list.front;
    DoubleNode *current = list.front->next;
    while (current->next != nullptr)
    {
        precurrent = precurrent->next;
        current = current->next;
    }
    precurrent->next = nullptr;
    delete current;
}
double front(DoubleLL &list)
{
    return list.front->data;
    
}
double back(DoubleLL &list)
{
    DoubleNode *current = list.front;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current->data;
}
int size(DoubleLL &list)
{
    DoubleNode *current = list.front;
    int size = 0;
    while (current != nullptr)
    {
        current = current->next;
        ++size;
    }
    return size;
}
bool isEmpty(DoubleLL &list)
{
    if (list.front == nullptr)
    {
        return true;
    }
    else 
    {
       return false;
    }
}

void filter(DoubleLL &list, double givendata)
{

    DoubleNode *precurrent = list.front;
    DoubleNode *current = precurrent->next;
    if (list.front->data == givendata)
    {
        list.front = current;
        delete precurrent;
    }
    else
    {
       while (current->data != givendata)
        {
            precurrent = current;
            current = current->next;
        }
        precurrent->next = current->next;
        delete current;
    }
}
double getAt(DoubleLL &list, int index)
{
    DoubleNode *current = list.front;
    for (int i = 1; i < index; ++i)
    {
        current = current->next;
    }
    return current->data;
}
void removeAt(DoubleLL &list, int index)
{
    DoubleNode *current = list.front->next;
    DoubleNode *precurrent = list.front;
    for (int i = 1; i < index; ++i)
    {
        precurrent = current;
        current = current->next;
    }
    precurrent->next = current->next;
    delete current;
}
void clear(DoubleLL &list)
{
    while (list.front != nullptr)
    {
       DoubleNode *current = list.front;
        list.front = list.front->next;
        delete current;
    }
}
}


#endif // MEMBER3_HPP
