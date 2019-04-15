
#include<string>
#include<stack>

struct Video
{
    int Size;
    std::string videoName;
    int id;
};

typedef struct Video Video;

struct NodeCache{
    NodeCache **link;     
    int data;                   /*Structure for Cache*/
    int Size;                  /*Video pointer with memory allocation*/
    // Video *cacheVideos;
    int *Lattencytoeachuser; 
    std::stack <Video> cacheVideos;
    int Remaingsize; 

};
typedef struct NodeCache NodeCache;

typedef struct {               /*Structure for End User*/
    NodeCache **link;           /*Video pointer only*/
    int data;
    int *Numberofrequests; 
    int LatencyfromDataServer;
    /*From root as well (Num of cache +1)*/
}NodeUser;

typedef struct  {            /*Structure for DataServer*/
    NodeUser **User;            /*Double pointer indicates Dynamic Allocation of User pointers*/
    NodeCache **Cacheserver; /*Double pointer indicates Dynamic Allocation of CacheServer pointers*/   
    Video *DataServervideos;


}NodeDataServer;

struct Userrequests{
    int NumberofRequests;
    int Userid;
    float Weight;
};

typedef struct Userrequests UserRequests;

struct LinkedListNode{ 
    
    int Videoid;
    int Memory;
    UserRequests *Users;
    struct LinkedListNode *link; 
    int NumberofUsersofthisVideo;

}; 

typedef struct LinkedListNode LinkedListNode;