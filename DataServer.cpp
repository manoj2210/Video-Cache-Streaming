#include "DataServer.h"
#include<iostream>
using namespace std;

DataServer::DataServer()
{
    Input.readData();

    this->Numberofvideos=Input.no_videos;                    
    this->Numberofusers=Input.no_endUsers;                      /*Inputs*/
    this->Numberofcacheservers=Input.no_caches;

    Root = new  NodeDataServer;                 

    Root->DataServervideos=new Video[Numberofvideos];

    Root->User=new NodeUser *[Numberofusers];               /*Allocation for Users*/
    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        Root->User[i]=new NodeUser;                         /*Allocation for Each user*/
        Root->User[i]->link=new NodeCache *[Numberofcacheservers];  /*Allocation for each links*/
        Root->User[i]->Numberofrequests=new int[Numberofvideos];
        for(unsigned int j=0;j<Numberofvideos;j++)
        {
            Root->User[i]->Numberofrequests[j]=0;
        }
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
    // cout<<Numberofusers<<Numberofcacheservers;
    
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

    for(unsigned int i=0;i<Numberofcacheservers;i++)
    {
        Root->Cacheserver[i]->Lattencytoeachuser=new int[Numberofusers];
    }

}
void DataServer::temp()
{
    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        Root->User[i]->data=i;
    }
    for(unsigned int i = 0; i < Numberofcacheservers; i++)
    {
        Root->Cacheserver[i]->data=i;
    }
    for(unsigned int i=0;i<Numberofusers;i++)
    {
        for(unsigned int j=0;j<Numberofcacheservers;j++)
        {
            Root->Cacheserver[j]->Lattencytoeachuser[i]=Input.lattency_user_from_cache[i][j];
        }
    }
    for(unsigned int j=0;j<Numberofusers;j++)
    {
        Root->User[j]->LatencyfromDataServer=Input.lattency_user_from_dataserver[j];
    }
    for(unsigned int j=0;j<Numberofcacheservers;j++)
    {
        Root->Cacheserver[j]->Size=Input.mem_for_each_cache[j];
        Root->Cacheserver[j]->Remaingsize=Root->Cacheserver[j]->Size;
    }
    for(unsigned int i = 0; i < Numberofvideos; i++)
    {
        Root->DataServervideos[i].id=i;
        Root->DataServervideos[i].Size=Input.mem_for_each_video[i];
    }

    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        for(unsigned int j=0;j<Numberofvideos;j++)
        {
            for(unsigned int k=0;k<Input.requests;k++)
            {
                if(i==Input.request_details[k][0])
                {
                    if(j==Input.request_details[k][1])
                    {
                        Root->User[i]->Numberofrequests[j]=Input.request_details[k][2];
                    }       
                }
            }
        }
    }

    sortLattencyUser();

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
    cout<<"Output for Cache Latencies\n";
    for(unsigned int i=0;i<Numberofcacheservers;i++)
    {
        cout<<"Cache"<<" "<<i+1<<endl;
        for(unsigned int j=0;j<Numberofusers;j++)
        {
            cout<<Root->Cacheserver[i]->Lattencytoeachuser[j]<<endl;
        }
    }

    cout<<"LatencyfromDtaServer"<<endl;

    for(unsigned int j=0;j<Numberofcacheservers;j++)
    {
        cout<<Root->User[j]->LatencyfromDataServer<<endl;
    }
    
    cout<<"Enter the input for Cache size"<<endl;
    for(unsigned int j=0;j<Numberofcacheservers;j++)
    {
        cout<<Root->Cacheserver[j]->Size<<endl;
    }
    
    cout<<"Video details\n";
    for(unsigned int i = 0; i < Numberofvideos; i++)
    {
        cout<<"Name\n";
        cout<<Root->DataServervideos[i].id<<endl;
        cout<<"Size\n";
        cout<<Root->DataServervideos[i].Size<<endl;   
    }
    cout<<"Requests"<<endl;
    for(unsigned int i = 0; i < Numberofusers; i++)
    {
        for(unsigned int j=0;j<Numberofvideos;j++)
        {
            cout<<i<<" "<<j<<" ";
            cout<<Root->User[i]->Numberofrequests[j]<<endl;
        }
    }
}


void DataServer::sortLattencyUser()
{
    for(unsigned int i=0;i<Numberofusers;i++)
    {
        for(unsigned int j=0;j<Numberofcacheservers;j++)
        {
            for(unsigned int k=j+1;k<Numberofcacheservers;k++)
            {
                if(Root->User[i]->link[j]->Lattencytoeachuser[i]>Root->User[i]->link[k]->Lattencytoeachuser[i])
                {
                    NodeCache *temp=Root->User[i]->link[j];
                    Root->User[i]->link[j]=Root->User[i]->link[k];
                    Root->User[i]->link[k]=temp;
                }
            }
        }
    }
}

void DataServer::constructLinkedList()
{
    int temp[Numberofvideos];

    for(unsigned int i=0;i<Numberofvideos;i++)
    {
        temp[i]=0;
    }

    for(unsigned int i=0;i<Input.requests;i++)
    {
        temp[Input.request_details[i][1]]+=1;
    }

    cout<<"temp"<<endl;
    for(unsigned int i=0;i<Numberofvideos;i++)
    {
        cout<<temp[i]<<endl;
    }
    int flag=0;

    for(unsigned int i=0;i<Numberofvideos;i++)
    {
        if(temp[i]!=0)
        {

        if(!flag)
        {
            UserRequests *user=new UserRequests[temp[i]];
            int sum=0;
            for(int j=0;j<temp[i];j++)
            {
                for(int k=0;k<Input.requests;k++)
                {
                    if(Input.request_details[k][1]==i)
                    {
                        sum+=Input.request_details[k][2];
                        user[j].NumberofRequests=Input.request_details[k][2];
                        user[j].Userid=Input.request_details[k][0];
                        Input.request_details[k][1]=-1;
                        break;
                    }
                }
            }        
            flag=1;
            list=new LinkedList(i,Root->DataServervideos[i].Size,user,sum,temp[i]);
        }
        else
        {
            UserRequests *user=new UserRequests[temp[i]];
            int sum=0;
            for(int j=0;j<temp[i];j++)
            {
                for(int k=0;k<Input.requests;k++)
                {
                    if(Input.request_details[k][1]==i)
                    {
                        sum+=Input.request_details[k][2];
                        user[j].NumberofRequests=Input.request_details[k][2];
                        user[j].Userid=Input.request_details[k][0];
                        Input.request_details[k][1]=-1;
                        break;
                    }
                }
            }        
            list->insertNode(i,Root->DataServervideos[i].Size,user,sum,temp[i]);
        }    
    }
    }

    cout<<"\n\n\n linkedlist\n";
    list->Display();

}


