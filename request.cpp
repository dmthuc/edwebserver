#include <unistd.h>
#include <iostream>
#include "request.h"
using namespace std;


Request::Request()
{

}

void Request::parse_request(const int connfd)
{
    const int Max_line = 200;
    int n = 0;
    char recvline[Max_line+1] = {0};
    while((n = read(connfd,recvline,Max_line)) > 0) {
        recvline[n] = 0;
        cout<<recvline<<endl;
    }

}

void parse_request(const int connfd)
{
    const int Max_line = 200;
    int n = 0;
    char recvline[Max_line+1] = {0};
    while((n = read(connfd,recvline,Max_line)) > 0) {
        recvline[n] = 0;
        cout<<recvline<<endl;
    }
    cout<<"finish read"<<endl;
}

