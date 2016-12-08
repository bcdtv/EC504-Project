#include "deque.h"
#include <cstdlib>
#include <limits>

// create an empty Deque
Deque::Deque()
{
        nodes = new std::vector<int>();
}

// construct a Deque from an input vector
Deque::Deque(std::vector<int> numbers)
{
        nodes = new std::vector<int>();

        *nodes = numbers;
}

// push a number onto the front
void Deque::push_front(int value)
{
        nodes->insert(nodes->begin(), value);
}

// push a number onto the back
void Deque::push_back(int value)
{
        nodes->push_back(value);
}

// pop a number from the front
int Deque::pop_front()
{
        if(nodes->size() == 0)
                throw -1;

        int result = (*nodes)[0];

        nodes->erase(nodes->begin());

        return result;
}

// pop a number from the back
int Deque::pop_back()
{
        if(nodes->size() == 0)
                throw -1;

        int result = (*nodes)[nodes->size() - 1];

        nodes->pop_back();

        return result;
}

// extract the minimum element
int Deque::extractMin()
{
        int min = std::numeric_limits<int>::min();
        int minIndex = 0;
        // not necessarily sorted, linear search
        for(int i = 0; i < nodes->size(); i++)
        {
                if((*nodes)[i] < min)
                {
                        min = (*nodes)[i];
                        minIndex = 0;
                }
        }

        nodes->erase(nodes->begin() + minIndex);

        return min;
}

// get if the Deque is empty
bool Deque::isEmpty()
{
        return nodes->size() == 0;
}

// get the next number greater than value (does not pop)
int Deque::successor(int value)
{
        int successor = value;
        int minDiff = std::numeric_limits<int>::max();

        for(int i = 0; i < nodes->size(); i++)
        {
                if((*nodes)[i] > value)
                {
                        int diff = (*nodes)[i] - value;

                        if(diff < minDiff)
                        {
                                minDiff = diff;
                                successor = (*nodes)[i];
                        }
                }
        }

        if(successor == value)
                throw -1;

        return successor;
}

// get the next number less than value (does not pop)
int Deque::predecessor(int value)
{
        int predecessor = value;
        int minDiff = std::numeric_limits<int>::max();

        for(int i = 0; i < nodes->size(); i++)
        {
                if((*nodes)[i] < value)
                {
                        int diff = value - (*nodes)[i];

                        if(diff < minDiff)
                        {
                                minDiff = diff;
                                predecessor = (*nodes)[i];
                        }
                }
        }

        if(predecessor == value)
                throw -1;

        return predecessor;
}

// get all the nodes in a vector
std::vector<int> Deque::getNodes()
{
        return *nodes;
}

// destructor
Deque::~Deque()
{
        delete(nodes);
}
