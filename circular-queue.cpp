#include "circular-queue.h"
#include <iostream>

using namespace std;

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    capacity_ = 16;
    items_ = new QueueItem[capacity_];

}

CircularQueue::CircularQueue(unsigned int capacity)
{
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    capacity_ = capacity;
    items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue()
{
    delete [] items_;
    items_ = NULL;
}

bool CircularQueue::empty() const
{
    return size_ == 0;
}

bool CircularQueue::full() const
{
    return size_ == capacity_;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if(full())
    {
        return false;
    }
    size_++;
    items_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue()
{
    if(empty())
    {
        return EMPTY_QUEUE;
    }
    size_--;
    int tempHead = head_;
    head_ = (head_ + 1) % capacity_;
    return items_[tempHead];
}

CircularQueue::QueueItem CircularQueue::peek() const
{
    if(empty())
    {
        return EMPTY_QUEUE;
    }
    return items_[head_];
}

void CircularQueue::print() const
{
    if(!empty())
    {
        if(head_ < tail_)
        {
            for(int indexA = head_; indexA < tail_; indexA++)
            {
                cout << "[" << items_[indexA] << "] ";
            }
        }
        else
        {
            for(int indexB = head_; indexB < capacity_; indexB++)
            {
                cout << "[" << items_[indexB] << "] ";
            }
            for(int indexC = 0; indexC < tail_; indexC++)
            {
                cout << "[" << items_[indexC] << "] ";
            }
        }
    }
}
