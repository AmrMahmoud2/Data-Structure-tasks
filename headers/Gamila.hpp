#ifndef MEMBER4_HPP
#define MEMBER4_HPP
#include <iostream>
namespace linked_lists
{

struct IntegerNode
{
    int data;
    IntegerNode *next = nullptr;
};

struct IntegersLL
{
    IntegerNode *front;
};
void insertFront(IntegersLL &list, int data)
{
    IntegerNode *pointer = new IntegerNode;
    pointer->next = list.front;
    list.front = pointer;
    pointer->data = data;
}
void insertBack(IntegersLL &list, int data)
{
    IntegerNode *current = list.front;
    if (list.front == nullptr)
    {

        current = new IntegerNode;
        current->data = data;
        current->next = nullptr;
        list.front = current;
    }
    else
    {
        while (current ->next != nullptr)
        {
            current = current->next;
        }
        current ->next= new IntegerNode;
        current->next ->data = data;
        current-> next -> next=nullptr;
    }
}
void printAll(IntegersLL &list)
{
    IntegerNode *current = list.front;

    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}
void removeFront(IntegersLL &list)
{
    IntegerNode *current = list.front;
    list.front = list.front->next;
    delete current;
}
void removeBack(IntegersLL &list)
{
    IntegerNode *precurrent = list.front;
    IntegerNode *current = list.front->next;
    while (current->next != nullptr)
    {
        precurrent = precurrent->next;
        current = current->next;
    }
    precurrent->next = nullptr;
    delete current;
}
int front(IntegersLL &list)
{
    return list.front->data;
}
int back(IntegersLL &list)
{
    IntegerNode *current = list.front;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current->data;
}
int size(IntegersLL &list)
{
    IntegerNode *current = list.front;

    int size = 0;
    while (current != nullptr)
    {
        current = current->next;
        ++size;
    }
    return size;
}
bool isEmpty(IntegersLL &list)
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

void filter(IntegersLL &list, int givendata)
{

    IntegerNode *precurrent = list.front;
    IntegerNode *current = precurrent->next;
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
int getAt(IntegersLL &list, int index)
{

    IntegerNode *current = list.front;
    for (int i = 1; i < index; ++i)
    {
        current = current->next;
    }
    return current->data;
}
void removeAt(IntegersLL &list, int index)
{
    IntegerNode *current = list.front->next;
    IntegerNode *precurrent = list.front;
    for (int i = 1; i < index - 1; ++i)
    {
        precurrent = current;
        current = current->next;
    }
    precurrent->next = current->next;
    delete current;
}
void clear(IntegersLL &list)
{
    while (list.front != nullptr)
    {
        IntegerNode *current = list.front;
        list.front = list.front->next;
        delete current;
    }
}
}
#endif // MEMBER4_HPP
