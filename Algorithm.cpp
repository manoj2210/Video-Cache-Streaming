#include "Algorithm.h"
#include<fstream>


LinkedListNode* Algorithm::swap(LinkedListNode* ptr1, LinkedListNode* ptr2) 
{ 
    LinkedListNode* tmp = ptr2->link; 
    ptr2->link = ptr1; 
    ptr1->link = tmp; 
    return ptr2; 
}

void Algorithm::sortLinkedList()
{
      /* Function to sort the list */
    LinkedListNode **head=&list->Start;
    int count=list->Sizeofll(); 

    LinkedListNode **h; 
    int i, j, swapped; 
  
    for (i = 0; i <= count; i++) { 
  
        h = head; 
        swapped = 0; 
  
        for (j = 0; j < count - i - 1; j++) { 
  
            LinkedListNode *p1 = *h; 
            LinkedListNode *p2 = p1->link; 
  
            if (p1->Sumofrequests < p2->Sumofrequests) { 
  
                /* update the link after swapping */
                *h = swap(p1, p2); 
                swapped = 1; 
            } 
  
            h = &(*h)->link; 
        } 
  
        /* break if the loop ended without any swap */
        if (swapped == 0) 
            break; 
    } 
    cout<<"Sorted"<<"\n\n";
    list->Display();

    LinkedListNode* temp=list->Start;
    while(temp!=NULL)
    {
    WeightCalculator(temp);
    InsertVideosinCaches(temp);
    temp=temp->link;
    }
    PrintStack();
} 


void Algorithm::WeightCalculator(LinkedListNode * temp)
{
    if(temp!=NULL)
    {
        for (unsigned int i = 0; i < temp->NumberofUsersofthisVideo; i++)
        {
            int id = temp->Users[i].Userid;    
            int Latency=0;   

            for (unsigned j = 0; j < Numberofcacheservers; j++)
            {   
                if(Root->User[id]->link[j]->Remaingsize>=temp->Memory)
                {
                    Latency=Root->User[id]->link[j]->Lattencytoeachuser[id];
                    break;
                }
                else if(j==Numberofcacheservers-1)
                {
                    Latency=Root->User[i]->LatencyfromDataServer;
                }
            }
        }
    }
}

void Algorithm::InsertVideosinCaches(LinkedListNode *temp)
{
     
    if(temp!=NULL)
    {
        float min=temp->Users[0].Weight;
        int id=temp->Users[0].Userid;
        for (unsigned int i = 0; i < temp->NumberofUsersofthisVideo; i++)
        {
            if(min>temp->Users[i].Weight)
            {
                float tem=temp->Users[i].Weight;
                temp->Users[i].Weight=min;
                min=tem;
                id=temp->Users[i].Userid;
            }
        }

        for (unsigned int j = 0; j < Numberofcacheservers; j++)
        {   
            if(Root->User[id]->link[j]->Remaingsize>=temp->Memory)
            {
                Root->User[id]->link[j]->cacheVideos.push(Root->DataServervideos[temp->Videoid]);
                Root->User[id]->link[j]->Remaingsize=Root->User[id]->link[j]->Remaingsize-temp->Memory;
                break;
            }
        }
    }
}

void Algorithm::PrintStack()
{
    ofstream fout;
    fout.open("Outputfile.txt",ios::out);

    fout<<"CacheId\t"<<"VideoId\t"<<"VideoSize\t"<<"No. of Elements\t"<<"RemainingSize\n";
    
    for(int i=0;i<Numberofcacheservers;i++)
    {
        for (stack<Video> dump = Root->Cacheserver[i]->cacheVideos; !dump.empty(); dump.pop())
            {
                fout<<i<<"\t"<<dump.top().id<<"\t"<<dump.top().Size<<"\t\t"<<Root->Cacheserver[i]->cacheVideos.size()<<"\t\t"<<Root->Cacheserver[i]->Remaingsize<<"\n";
                cout << "id"<<dump.top().id << '\n';
                cout << "size"<<dump.top().Size<< '\n';
                cout << "(" << Root->Cacheserver[i]->cacheVideos.size() << " elements)\n";
                cout<<"rs"<<Root->Cacheserver[i]->Remaingsize<<endl;
            }
    }
    fout.close();
}
