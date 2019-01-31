#ifndef MEMBER2_HPP
#define MEMBER2_HPP
#include <cstdlib>

namespace stack
{
    //int array stack
    struct IntegersStackArray
    {
        int buffer[ 100 ];
        int top = -1;
    };

    void push( IntegersStackArray &stack , int data )
    {
        ++stack.top;
        stack.buffer[stack.top] = data;
    }

    int pop( IntegersStackArray &stack )
    {
        int lifo = stack.buffer[stack.top];
        --stack.top;
        return lifo;
    }

    int front( IntegersStackArray &stack )
    {
        return stack.buffer[stack.top];
    }

    bool isEmpty( IntegersStackArray &stack )
    {
        return (stack.top == -1);
    }

    int size( IntegersStackArray &stack )
    {
        return ( stack.top + 1 );
    }

    void clear( IntegersStackArray &stack )
    {
        stack.top = -1;
    }

    //char L.L. stack
    struct CharNodeStack
    {
        char data;
        CharNodeStack *next = nullptr;
    };

    struct CharStackLL
    {
        CharNodeStack *front = nullptr;
    };

    void push( CharStackLL &stack , char data )
    {
        CharNodeStack *newNode = new CharNodeStack;

        newNode->data = data;
        newNode->next = stack.front;

        stack.front = newNode;
    }


    char pop( CharStackLL &stack )
    {
        if( stack.front )
        {
            char lifo = stack.front->data;
            CharNodeStack *oldFront = stack.front;
            stack.front = stack.front->next;
            delete oldFront;
            return lifo;
        }
        else
        {
            exit( 1 );
        }
    }

    char front( CharStackLL &stack )
    {  
        return ( stack.front->data );
    }

    bool isEmpty( CharStackLL &stack )
    {
        return stack.front == nullptr;
    }

    char size( CharStackLL &stack )
    {
        int count = 0;
        CharNodeStack *current = stack.front;
        while ( current != nullptr )
        {
            current = current->next;
            count++;
        }
        return count;
    }

    void clear( CharStackLL &stack )
    {
        stack.front = nullptr;
    }
}

namespace queue
{
    //L.L queue
    struct CharNode
    {
        double data;
        CharNode *next;
    };

    struct CharQueueLL
    {
        CharNode *front = nullptr;
        CharNode *back = nullptr;
    };

    bool isEmpty( CharQueueLL queue )
    {
        return (queue.back == nullptr);
    }

    void enqueue( CharQueueLL &queue , double newSample )
    {
        if( isEmpty( queue ))
        {
            queue.back = new CharNode{ newSample , nullptr };
            queue.front = queue.back;
        }
        else
        {
            queue.back = new CharNode{ newSample , queue.back };
        }
    }

    double dequeue( CharQueueLL &queue  )
    {
        if ( isEmpty( queue) != true )
        {
            double fifo = queue.front->data;
            CharNode *oldBack = queue.front;
            queue.front = queue.front->next;
            delete oldBack;
            return fifo;
        }
        else
            exit( 1 );
    }

    double size( CharQueueLL &queue )
    {
        int count = 0;
        CharNode *current = queue.front;
        while ( current != nullptr ) 
        {
            current = current->next;
            count;
        }
        return count;
    }

    double front( CharQueueLL &queue )
    {
        return ( queue.front->data );
    }

    void clear( CharQueueLL &queue )
    {
        queue.back = nullptr;
        queue.front = nullptr;
    }
}

#endif // MEMBER2_HPP
