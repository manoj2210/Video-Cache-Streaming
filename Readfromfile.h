#include <fstream>
#include <iostream>
using namespace std;

class Read_from_File
{
    private:
        int no_videos;
        int no_caches;
        int no_endUsers;
        int **lattency_user_from_cache;
        int *lattency_user_from_dataserver;
        int *mem_for_each_cache;
        int *mem_for_each_video;
        int **requests_by_videoId_times;
        int requests;       //total no of requests placed by the users
        int **request_details;
    public:
        void readData();
    friend class DataServer;
};