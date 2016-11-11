#include <iostream>
#include <vector>

#include "BinaryHeap.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(70);
    v.push_back(60);
    v.push_back(80);
    BinaryHeap b(v);
    b.display();
    cout << "The min is: " << b.min << endl;

    cout << "Extracting...." << b.extract() << endl;
    b.display();
    cout << "The min is: " << b.min << endl;    

    b.insert(90);
    b.display();
    cout << "The min is: " << b.min << endl;    

    cout << "Extracting...." << b.extract() << endl;
    b.display();
    cout << "The min is: " << b.min << endl;    

    b.remove(70);
    b.display();
    cout << "The min is: " << b.min << endl;    


    b.insert(20);
    b.display();
    cout << "The min is: " << b.min << endl;    

    return 0;
}