#include<iostream>
// #include"DataServer.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // DataServer A(1,2,2);
    // A.createTreeStructure();
    // A.temp();
    // return 0;

    UserRequests *user=new UserRequests;
    user->NumberofRequests=1000;
    user->Userid=100;

    LinkedList list(1,2,user);
    list.insertNode(5,6,user);
    list.Display();

}
