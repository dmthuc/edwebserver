#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include "request.h"
#include "File_description_exception.h"
using namespace std;

int Request::parse_request(const int connfd)
{
    if( connfd < 0)
        throw File_description_exception();
    const int Max_line = 200;
    int n = 0;
    char recvline[Max_line+1] = {0};
    n = read(connfd,recvline,Max_line);
    if(-1 == n) {
        throw File_description_exception();
    }
    recvline[n] = 0;
    cout<<recvline<<endl;
    istringstream(recvline)>>method>>url>>protocol;
    cout<<"parse request with result"<<method<<endl<<"url: "<<endl<<url<<"protocol: "<<protocol<<endl;
    while(strstr( recvline,"\r\n\r\n") == NULL){
        n = read(connfd,recvline,Max_line);
        if(-1 == n) {
            throw File_description_exception();
        }
    }
    return 0;

}

string Request::get_url() const
{
    return url;
}

