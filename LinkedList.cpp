#include"LinkedList.h"

LinkedList::LinkedList(int Videoid,int Memory,UserRequests *Users,int Numberofrequests,int Total)
{
    Start = new LinkedListNode;

    Start->Memory=Memory;
    Start->Videoid=Videoid;
    Start->Users = Users;
    Start->Sumofrequests=Numberofrequests;
    Start->NumberofUsersofthisVideo=Total;
    Start->link=NULL;
    ptr=Start;
}

void LinkedList::insertNode(int Videoid,int Memory,UserRequests *Users,int Numberofrequests,int Total)
{

    LinkedListNode *temp = new LinkedListNode;

    temp->Memory=Memory;
    temp->Videoid=Videoid;
    temp->Users = Users;
    temp->Sumofrequests=Numberofrequests;
    temp->NumberofUsersofthisVideo=Total;
    temp->link=NULL;
    ptr->link=temp;
    ptr=ptr->link;
}
int LinkedList::Sizeofll()
{
    LinkedListNode *temp;

    temp=Start;
    int count=0;
    while(temp!=NULL)
    {
        count+=1;
        temp=temp->link;
    }
    return count;
}
void LinkedList::Display()
{
    LinkedListNode *temp;

    temp=Start;

    while(temp!=NULL)
    {
        cout<<"Memory"<<temp->Memory<<endl;
        cout<<"VideoID"<<temp->Videoid<<endl;
        cout<<"Total Number of Users"<<temp->NumberofUsersofthisVideo<<endl;
        cout<<"Sum of requests"<<temp->Sumofrequests<<endl;
        cout<<"UserID"<<temp->Users[0].Userid<<endl;
        cout<<"NumberofRequest"<<temp->Users[0].NumberofRequests<<endl;
        
        temp=temp->link;
    }
} 
