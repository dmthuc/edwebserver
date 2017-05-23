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
#include "web_directory.h"
#include "response.h"
#include "request.h"

using namespace std;
const string index_file = "index.html";
const int Max_line = 100;
const int Port = 1313;
const int Backlog = 10;
int main()
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
        cerr<<"socket fail"<<endl; 
    char buff[Max_line] ={0};
    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(Port);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(0 != bind(listenfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)))
        cerr<<"bind failed"<<endl;
    
    if(0 != listen(listenfd, Backlog))
        cerr<<"listen err"<<endl;
    Web_directory& web_directory = Web_directory::get_singleton("./www/");
    cout<<"Ed webserver start at port:"<<Port<<endl;
    while(true) {
        int connfd = accept(listenfd, nullptr,nullptr);
        cout<<" accept new connection"<<endl;
        Request client_request();
        //client_request.parse_request(connfd);
        //parse_request(connfd);
        Response::send_OK_header(connfd); 
        web_directory.serve_resource(connfd,"index.html");
        sleep(5);
        Response::send_close_connection(connfd);
        close(connfd);
    }
    //Set up socket server

    //Finish setup socket

    //Loop


}

