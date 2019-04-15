#include <iostream>
#include"Structures.h"
using namespace std;

class LinkedList{

public:
    LinkedListNode * Start;
    LinkedListNode *ptr;

    LinkedList(int Videoid,int Memory,UserRequests *Users);   

    void insertNode(int Videoid,int Memory,UserRequests *Users);
    void Display(); 
    // void CalculateWeight();
};