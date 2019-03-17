#include "DataServer.h"
#include<iostream>
using namespace std;

DataServer::DataServer(int Numberofvideos,int Numberofusers,int Numberofcacheservers)
{
    this->Numberofvideos=Numberofvideos;                    
    this->Numberofusers=Numberofusers;                      /*Inputs*/
    this->Numberofcacheservers=Numberofcacheservers;

    Root = new  NodeDataServer;                 

    Root->DataServervideos=new Video [Numberofvideos];



    Root->User=new NodeUser *[Numberofusers];               /*Allocation for Users*/
    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        Root->User[i]=new NodeUser;                         /*Allocation for Each user*/
        Root->User[i]->link=new NodeCache *[Numberofcacheservers];  /*Allocation for each links*/
    }

    
    Root->Cacheserver=new NodeCache *[Numberofcacheservers];
    for(unsigned int i = 0; i < Numberofcacheservers; i++)
    {
        Root->Cacheserver[i]=new NodeCache;
        Root->Cacheserver[i]->link=new NodeCache *[Numberofcacheservers];
    }

}
void DataServer::createTreeStructure()
{
    cout<<Numberofusers<<Numberofcacheservers;
    
    for(unsigned int i=0;i< Numberofusers;i++)
    {
        for(unsigned int j=0;j< Numberofcacheservers;j++)
        {
            Root->User[i]->link[j]=Root->Cacheserver[j];
        }
    }
    for(unsigned int i=0;i< Numberofcacheservers;i++)
    {
        for(unsigned int j=0;j< Numberofcacheservers;j++)
        {
            if(i!=j)
                Root->Cacheserver[i]->link[j]=Root->Cacheserver[j];     /*If condition because to avoid selfreferencial datatype (segfault)*/
        }
    }
}
void DataServer::temp()
{
    cout<<endl<<"Enter input for Users\n";
    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        cin>>Root->User[i]->data;
    }
    cout<<endl<<"Enter input for Cache\n";
    for(unsigned int i = 0; i < Numberofcacheservers; i++)
    {
        cin>>Root->Cacheserver[i]->data;
    }
    cout<<endl<<"Output for Users\n";
    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        cout<<Root->User[i]->data<<endl;
    }
    cout<<endl<<"Output for Cache\n";
    for(unsigned int i = 0; i < Numberofcacheservers; i++)
    {
        cout<<Root->Cacheserver[i]->data<<endl;
    }
    cout<<endl<<"Output for Cache through Users\n";
    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        for(unsigned int j = 0; j < Numberofcacheservers; j++)
        {
        cout<<Root->User[i]->data<<"\t"<<Root->User[i]->link[j]->data<<endl;
        }   
    }
    cout<<"Output for Cache through cache\n";
    for(unsigned int i = 0; i < Numberofcacheservers; i++)
    {
        for(unsigned int j = 0; j < Numberofcacheservers; j++)
        {
            if(i!=j)
            cout<<Root->Cacheserver[i]->data<<"\t"<<Root->Cacheserver[i]->link[j]->data<<endl;
        }   
    }
}

