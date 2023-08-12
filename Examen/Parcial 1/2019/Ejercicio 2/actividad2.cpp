
#include <iostream>
#include <stdlib.h>
using namespace std;

class doble {
    public:
    doble(double n): d(n){}
    operator double(){return d;}
    private:
    double d;
};
