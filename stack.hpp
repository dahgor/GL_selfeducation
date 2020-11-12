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
//  It wasn't specified so I created class Stack for Integers based on array

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
        int capacity() const { return top_ - 1; }
        int size() const { return size_; }



    private:

        int* data_array_;               //  pointer to dynamically allocated array
        int size_;                      //  max size of Stack
        int top_;                       //  index for next free position in Stack
}


#endif