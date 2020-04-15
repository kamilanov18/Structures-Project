#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

struct TIME {
    int m;
    int h;
};

struct DATE {
    int d;
    int m;
    int y;
    TIME time;
};

struct TRAIN {
    DATE departTime;
    DATE arriveTime;

};

int main()
{
   
}