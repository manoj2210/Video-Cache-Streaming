#include "Readfromfile.h"
void Read_from_File ::  readData()
{
    int i,j;

    ifstream fin;
    
    fin.open("datafile2.txt",ios :: in);
    
    fin>>no_videos;
    
    fin>>no_endUsers;
    
    fin>>no_caches;
    
    lattency_user_from_cache= new int*[no_endUsers];
    for(int i=0;i<no_endUsers;i++)
    {
        lattency_user_from_cache[i]=new int[no_caches];
    }
    
    for(i=0;i<no_endUsers;i++)
    
        for(j=0;j<no_caches;j++)
    
            fin>>lattency_user_from_cache[i][j];
    
    mem_for_each_cache = new int[no_caches];
    
    for(i=0;i<no_caches;i++)
        fin>>mem_for_each_cache[i];

    mem_for_each_video = new int[no_videos];
    
    for(i=0;i<no_videos;i++)
    
        fin>>mem_for_each_video[i];
    
    
    lattency_user_from_dataserver= new int[no_endUsers];
    
    for(i=0;i<no_endUsers;i++)
    
        fin>>lattency_user_from_dataserver[i];
    
    fin>>requests;


    request_details= new int*[requests];
    
    for(int i=0;i<requests;i++)
        request_details[i]=new int[3];
    
    for(i=0;i<requests;i++)
        for(j=0;j<3;j++)
            fin>>request_details[i][j];
    
    fin.close();
}