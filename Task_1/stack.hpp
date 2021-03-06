//                      Created by Denys Horban
//
//                    Task #1 for algorithmization
//  Create stack based on array/linked list and implement next functions:
//
//  create – create stack with number of elements;
//  push – add element to stack;
//  pop – get element from stack;
//  capacity – get amount of elements in stack;
//  size – maximum amount of elements;
//  resize – increase/decrease size of stack;
//  
//  It wasn't specified so I created class Stack for Integers based on array.
//
//  Stack uses dynamically allocated memory from heap, so only limitation for
//  Stack size is your memory. Stack size was limited to 250.000(around 1Mb, if int size = 4bytes) in order to
//  prevent from using excessive memory.

#ifndef _STACK_H_
#define _STACK_H_

class Stack
{
    public:
        
        Stack(int size);
        ~Stack() { delete[] data_array_; }

        //  Operations with Stack
        bool push(int data);
        int& pop();
        void resize(int size);

        //  Info methods
        int capacity() const { return top_; }
        int size() const { return size_; }

        //  Limits for Stack size
        enum Limits
        {
            MIN = 1,
            MAX = 250000
        };

    private:

        int* data_array_;               //  pointer to dynamically allocated array
        int size_;                      //  max size of Stack
        int top_;                       //  index for next free position in Stack
};


#endif