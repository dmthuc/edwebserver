#include <cstring>
#include <unistd.h>
#include "response.h"
void Response::send_OK_header(const int connfd)
{
    char buff[200] = {0};
    strcpy(buff,"HTTP/1.1 200 OK\r\nDate: Mon, 27 Jul 2017 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win32)\r\n");
    write(connfd,buff, strlen(buff));
    memset(buff,0, sizeof(buff));
    strcpy(buff,"Connection: keep-alive\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n");
    write(connfd,buff, strlen(buff));
}
void Response::send_close_connection(const int connfd)
{
    char buff[200] = {0};
    strcpy(buff,"HTTP/1.1 200 OK\r\nDate: Mon, 27 Jul 2017 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win32)\r\n");
    write(connfd,buff, strlen(buff));
    memset(buff,0, sizeof(buff));
    strcpy(buff,"Connection: Closed\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n");
    write(connfd,buff, strlen(buff));
}
