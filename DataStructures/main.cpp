#include<iostream>
#include"DataServer.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    DataServer A(4,5,5);
    A.createTreeStructure();
    A.temp();
    return 0;
}
