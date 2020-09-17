#include "DataServer.cpp"

class Algorithm:public DataServer
{

public:
    void sortLinkedList();
    void WeightCalculator(LinkedListNode*);            //Weight=Time/NumberofVideos
    void InsertVideosinCaches(LinkedListNode*);
    LinkedListNode* swap(LinkedListNode* ptr1, LinkedListNode* ptr2) ;
    void PrintStack();

};