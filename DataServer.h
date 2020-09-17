#include"LinkedList.cpp"
#include"Readfromfile.cpp"

class DataServer {                          /*Class contains the tree construction*/

private:
    Read_from_File Input;

protected:    
    NodeDataServer *Root;            /* Data Server Node*/
    int Numberofvideos;             /*Number of inputs*/
    int Numberofusers;
    int Numberofcacheservers;

    LinkedList *list;


public:
    DataServer ();
    void createTreeStructure();         /*Allocates Memory*/
    void temp();
    void sortLattencyUser();
    void constructLinkedList();
};


// Things to be done
// 1)Change the Node Data member pointing to videos from specific cache servers or Data Server
//      So Each Node has **video which displays the videos (has the instance in case of Cache servers)
// 2)First Get input from the user through ui on inputs
        // Next get the lattencies for all types of servers
        // Next the video request for each end user through ui
        // Next get the size of each Cache Server
// 3)Then check whether each cache which is nearer to the End user can occupy all the Videos
        // Input the videos onto the cache as queue
        // If not
            // Space for Few videos is not available in the nearest cache,check in the nearby caches
//whether is there any empty space and store the time for all the caches available in a list
            // If there is no space dequeue and compare the last video's time and the video to be inserted
            // If there exits some videos common to all the caches then Calculate the time 
// by removing the duplicates and storing it in the cache nearby the user who has requested it more
// number of times
            // Compare all the times and store them in the correct cache

// If time permits introduce ads and make the queue as priority queues