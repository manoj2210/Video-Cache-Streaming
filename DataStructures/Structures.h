struct Video
{
    int Size;
    struct Video *video;
};

typedef struct Video Video;

struct NodeCache{
    NodeCache **link;     
    int data;                   /*Structure for Cache*/
    int Size;                  /*Video pointer with memory allocation*/
    Video *Cachevideos;
    //Queue
    int Remaingsize; 
};
typedef struct NodeCache NodeCache;

typedef struct {               /*Structure for End User*/
    
    NodeCache **link;           /*Video pointer only*/
    int data;
    Video *Uservideos;
    int *Numberofrequests;
    int *Lattencyfromeachserver;    /*From root as well (Num of cache +1)*/

}NodeUser;

typedef struct  {            /*Structure for DataServer*/

    NodeUser **User;            /*Double pointer indicates Dynamic Allocation of User pointers*/
    NodeCache **Cacheserver; /*Double pointer indicates Dynamic Allocation of CacheServer pointers*/   
    Video *DataServervideos;


}NodeDataServer;
