#include "dynamic-stack.h"
#include <iostream>

using namespace std;

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    size_ = 0;
    capacity_ = init_capacity_ = 16;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    if(capacity == 0)
    {
        init_capacity_ = 16;
    }
    else
    {
        init_capacity_ = capacity;
    }
    size_ = 0;
    capacity_ = init_capacity_;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
    delete [] items_;
    items_ = NULL;
}

bool DynamicStack::empty() const
{
    return size_ == 0;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if(size_ == capacity_)
    {
       capacity_ *= 2;
       StackItem* newStack = new StackItem[capacity_];

       for(int index = 0; index < size_; index++)
       {
           newStack[index] = items_[index];
       }
       delete [] items_;
       items_ = newStack;
    }
    items_[size_] = value;
    size_++;
}

DynamicStack::StackItem DynamicStack::pop()
{
    if(empty())
    {
        return EMPTY_STACK;
    }
    size_--;
    if(size_ <= (capacity_/4) && init_capacity_ <= (capacity_/2))
    {
        capacity_ /= 2;

        StackItem* newStack = new StackItem[capacity_];

        for(int index = 0; index < size_; index++)
        {
            newStack[index] = items_[index];
        }
        delete [] items_;
        items_ = newStack;
    }
    return items_[size_];
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if(empty())
    {
        return EMPTY_STACK;
    }
    return items_[size_ - 1];
}

void DynamicStack::print() const
{
    for(int index = size_ - 1; index >= 0; index++)
    {
        cout << items_[index];
    }
}
