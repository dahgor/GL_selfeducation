//  Realization of Stack class
//  Compile with stack.hpp

#include "stack.hpp"

Stack::Stack(int size)
{
    if (size <= 0)
    {
        throw "Stack size cannot be <= 0\n";
    }
    
    size_ = size;
    top_ = 0;
    data_array_ = new int[size_];
}

bool Stack::push(int data)
{
    //  Checking if there's free space left in Stack
    if (top_ < size_)
    {
        data_array_[top_] = data;
        ++top_;
        return true;
    }

    return false;
}

int& Stack::pop()
{
    //  Checking if Stack isn't empty
    if (top_ > 0)
    {
        return data_array_[--top_];
    }
    
    throw "There's no data left in Stack\n";
}

void Stack::resize(int new_size)
{
    //  Checks size param
    if (new_size <= 0)
    {
        throw "Stack size cannot be <= 0\n";
    }
    else if (new_size == size_)
    {
        return;
    }

    //  Creates new array with new_size
    int* new_data_array = new int[new_size];

    //  Copy old items to the new array
    if (new_size > size_ || new_size >= top_)
    {
        for (int i = 0; i < top_; i++)
        {
            new_data_array[i] = data_array_[i];
        }
    }
    else
    {
        for (int i = 0; i < new_size; i++)
        {
            new_data_array[i] = data_array_[i];
        }
        
        top_ = new_size;
    }
    
    //  Replacing old array by new one
    delete[] data_array_;
    data_array_ = new_data_array;

    size_ = new_size;
}

