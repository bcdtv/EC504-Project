#include <deque>
#include <vector>

class Deque
{
private:
        std::deque<int>* nodes;
public:
        // create an empty Deque
        Deque();

        // construct a Deque from an input vector
        Deque(std::vector<int> numbers);

        // push a number onto the front
        void push_front(int value);

        // push a number onto the back
        void push_back(int value);

        // pop a number from the front
        int pop_front();

        // pop a number from the back
        int pop_back();

        // extract the minimum element
        int extractMin();

        // get if the Deque is empty
        bool isEmpty();

        // get the next number greater than value (does not pop)
        int successor(int value);

        // get the next number less than value (does not pop)
        int predecessor(int value);

        // get all the nodes in a vector
        std::vector<int> getNodes();

        // destructor
        ~Deque();
};
