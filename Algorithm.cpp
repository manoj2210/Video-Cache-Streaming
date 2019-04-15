#include"Algorithm.h"

void Algorithm::WeightCalculator(LinkedListNode* temp)
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
                    Latency=Root->User[id]->link[j]->Lattencytoeachuser[i];
                    break;
                }
                else if(j=Numberofcacheservers-1)
                {
                    Latency=Root->User[i]->LatencyfromDataServer;
                }
            }
            temp->Users[i].Weight=(float)(Latency/temp->Users[i].NumberofRequests);
        }
    }
        
}

void Algorithm::InsertVideosinCaches(LinkedListNode *temp)
{
    if(temp!=NULL)
    {
        float min=temp->Users[0].Weight;
        int id;
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

        for (unsigned j = 0; j < Numberofcacheservers; j++)
        {   
            if(Root->User[id]->link[j]->Remaingsize>=temp->Memory)
            {
                Root->User[id]->link[j]->cacheVideos.push(Root->DataServervideos[temp->Videoid]);
                Root->User[id]->link[j]->Remaingsize-=temp->Memory;
                break;
            }
        }
    }

}


