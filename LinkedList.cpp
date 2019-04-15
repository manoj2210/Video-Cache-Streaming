#include"LinkedList.h"

LinkedList::LinkedList(int Videoid,int Memory,UserRequests *Users)
{
    Start = new LinkedListNode;

    Start->Memory=Memory;
    Start->Videoid=Videoid;
    Start->Users = Users;
    Start->link=NULL;

    ptr=Start;
}

void LinkedList::insertNode(int Videoid,int Memory,UserRequests *Users)
{

    LinkedListNode *temp = new LinkedListNode;

    temp->Memory=Memory;
    temp->Videoid=Videoid;
    temp->Users = Users;
    temp->link=NULL;

    ptr->link=temp;
    ptr=ptr->link;
}
void LinkedList::Display()
{
    LinkedListNode *temp;

    temp=Start;

    while(temp!=NULL)
    {
        cout<<"Memory"<<temp->Memory<<endl;
        cout<<"VideoID"<<temp->Videoid<<endl;
        cout<<"UserID"<<temp->Users->Userid<<endl;
        cout<<"NumberofRequest"<<temp->Users->NumberofRequests<<endl;
        temp=temp->link;
    }
} 
