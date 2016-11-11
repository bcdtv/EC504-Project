#ifndef V_EB_H
#define V_EB_H

#include <vector>

class vEB
{
private:
    vector<int> raw_data;

public:
    int getMin();
    int getMax();
    bool isMember(int);
    int getSuccessor(int);

}


#endif // V_EB_H
