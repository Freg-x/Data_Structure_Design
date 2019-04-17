

#include <iostream>
#include <cstdlib>
#include "linked list.h"

using namespace std;




int main() {LinkedList s1,s2,s3;
    s1.InputData();s2.InputData();
    s3=Merge(s1, s2);
    s3.Display();
    system("Pause");
    return 0;
}
