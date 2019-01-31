#ifndef MEMBER1_HPP
#define MEMBER1_HPP
#include <cstdlib>
//using namespace of stack 
namespace stack
{
///////////////// STACK based on arrays //////////////////
struct CharStack
{
    char data[100];
    int top = -1;
};
//push new element to stack
void push(CharStack &stack, char data)
{
    ++stack.top;
    stack.data[stack.top] = data;
}
//pop last input from stack
char pop(CharStack &stack)
{
    char lifo = stack.data[stack.top];
    --stack.top;
    return lifo;
}
//retutn size of stack
char size(CharStack &stack)
{
    return (stack.top + 1);
}
//return the last input to stack
char front(CharStack &stack)
{
    return stack.data[stack.top];
}
//check if stack is empty ?!
bool isEmpty(CharStack &stack)
{
    return (stack.top == -1);
}
//clear the stack
void clear(CharStack &stack)
{
    stack.top = -1;
}

///////////////////// STACK based LL //////////////////

struct IntegersStackNode
{
    int data;
    IntegersStackNode *next = nullptr;
};
struct IntegersLL
{
    IntegersStackNode *front = nullptr;
};
//push new element to stack
void push(IntegersLL &stack, int data)
{
    IntegersStackNode *newNode = new IntegersStackNode;

    newNode->data = data;
    newNode->next = stack.front;

    stack.front = newNode;
}
//pop last input from stack
int pop(IntegersLL &stack)
{
    if (stack.front != nullptr)
    {
        int lifo = stack.front->data;
        IntegersStackNode *OldFront = stack.front;
        stack.front = stack.front->next;
        delete OldFront;
        return lifo;
    }
    else
         exit(1);
}
//retutn size of stack
int size(IntegersLL &stack)
{
    int i = 0;
    IntegersStackNode *current = stack.front;
    while (current != nullptr)
    {
        current = current->next;
        i++;
    }
    return i;
}
//return the last input to stack
int front(IntegersLL &stack)
{
    return (stack.front->data);
}
//check if stack is empty ?!
bool isEmpty(IntegersLL &stack)
{
    return (stack.front == nullptr);
}
//clear the stack
void clear(IntegersLL &stack)
{
    stack.front = nullptr;
}
}
//////////////////// QUEUE //////////////
namespace queue
{
////////////// QUEUE based LL ////////////
struct DoublesQueueNode
{
    double data;
    DoublesQueueNode *next;
};
struct DoublesLL
{
    DoublesQueueNode *front = nullptr;
    DoublesQueueNode *back = nullptr;
};
//check if queue is empty ?!
bool isEmpty(DoublesLL queue)
{
    return (queue.back == nullptr);
}
//push new element to queue
void enqueue(DoublesLL &queue, double data)
{
    if (isEmpty(queue) != true)
    {
        queue.back = new DoublesQueueNode{data, nullptr};
        queue.front = queue.back;
    }
    else
    {
        queue.back = new DoublesQueueNode{data, queue.back};
    }
}
//dequeue last input from queue
double dequeue(DoublesLL &queue)
{
    if (isEmpty(queue) != true)
    {
        double fifo = queue.front->data;
        DoublesQueueNode *OldBack = queue.front;
        queue.front = queue.front->next;
        delete OldBack;
        return fifo;
    }
    else
        exit(1);
}
//retutn size of queue
double size(DoublesLL &queue)
{
    int i = 0;
    DoublesQueueNode *current = queue.front;
    while (current != nullptr)
    {
        current = current->next;
        ++i;
    }
    return i;
}
//return the first input to queue
double front(DoublesLL &queue)
{
    return (queue.front->data);
}
//clear the queue
void clear(DoublesLL &queue)
{
    queue.back = nullptr;
    queue.front = nullptr;
}

//////////////////// QUEUE based on Array ///////////////////
struct CharQueue
{
    char data[100];
    int front = -1;
    int back = -1;
};
//check if queue is empty ?!
bool isEmpty(CharQueue queue)
{
    return (queue.back == -1);
}
//push new element to queue in smart way!
void enqueue(CharQueue &queue, char data)
{
    if (queue.back == -1 && queue.front == -1)
    {
        ++queue.back;
        ++queue.front;
        queue.data[queue.back] = data;
    }
    else
    {
        ++queue.back;
        queue.data[queue.back] = data;
    }
}
//dequeue last input from queue
char dequeue(CharQueue &queue)
{
    char fifo = queue.data[queue.front];
    ++queue.front;
    return fifo;
}
//retutn size of queue`
char size(CharQueue &queue)
{
    return (queue.back + 1);
}
//return the last input to queue
char front(CharQueue &queue)
{
    return (queue.data[queue.front]);
}
//clear the queue
void clear(CharQueue &queue)
{
    queue.back = -1;
    queue.front = -1;
}
}

#endif // MEMBER1_HPP
