/* Ed web server*/
#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "web_directory.h"
#include "response.h"
#include "request.h"
#include "File_description_exception.h"

using namespace std;
const int Max_line = 100;
const int Port = 1313;
const int Backlog = 10;
void sig_handler(int sig_num)
{
   cerr<<"receive signal number:"<<sig_num<<endl;
   exit(0);
}

int main()
{
    /*set up signal handler*/
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &sig_handler;
    sigaction (SIGQUIT, &sa, NULL); 
    /*finish set up signal handler*/
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        cerr<<"socket fail"<<endl; 
        exit(1);
    }
    char buff[Max_line] ={0};
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(Port);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(0 != bind(listenfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)))
    {
        cerr<<"bind failed"<<endl;
        exit(1);
    }    
    if(0 != listen(listenfd, Backlog)) {
        cerr<<"listen err"<<endl;
        exit(1);
    }
    Web_directory& web_directory = Web_directory::get_singleton("./www/");
    cout<<"Ed webserver start at port:"<<Port<<endl;
    while(true) {
        int connfd = accept(listenfd, nullptr,nullptr);
        if (connfd > 0)
        {
        #if 0
            int rval = fork();
            switch (rval) {
                case :
            }
        #endif
            cout<<" accept new connection"<<endl;
            Request client_request{};
            try{
                client_request.parse_request(connfd);
                Response::send_response(connfd, &client_request);
            } catch (File_description_exception) {
                cerr<<"handle request error,file desciption error"<<endl;
            }
            close(connfd);
        } 
    }
}

