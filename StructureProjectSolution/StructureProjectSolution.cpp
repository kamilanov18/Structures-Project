#include "pch.h"
#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    ofstream web;
    web.open("web.html");
    int a = 1000;
    web << "<html><body><p style=" << "'color:red'" << ">" << a << "<p><body>";
}