#include <cstring>
#include <unistd.h>
#include "response.h"
#include "request.h"
#include "web_directory.h"
#include "File_description_exception.h"
#if 0
void Response::send_OK_header(const int connfd)
{
    char buff[200] = {0};
    strcpy(buff,"HTTP/1.1 200 OK\r\nDate: Mon, 27 Jul 2017 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win32)\r\n");
    write(connfd,buff, strlen(buff));
    memset(buff,0, sizeof(buff));
    strcpy(buff,"Connection: keep-alive\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n");
    write(connfd,buff, strlen(buff));
}
#endif
void Response::send_close_connection(const int connfd)
{
    char buff[200] = {0};
    strcpy(buff,"HTTP/1.1 200 OK\r\nDate: Mon, 27 Jul 2017 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win31)\r\n");
    if( -1 == write(connfd,buff, strlen(buff)))
        throw  File_description_exception();
    memset(buff,0, sizeof(buff));
    strcpy(buff,"Connection: Closed\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n");
    if ( -1 == write(connfd,buff, strlen(buff)))
        throw  File_description_exception();
}
void Response::send_response(const int connfd, Request * request)
{
    Web_directory& web_directory = Web_directory::get_singleton("./www/");
    char buff[200] = {0};
    strcpy(buff,"HTTP/1.1 200 OK\r\nDate: Mon, 27 Jul 2017 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win32)\r\n");
    if ( -1 == write(connfd,buff, strlen(buff)))
        throw  File_description_exception();
    memset(buff,0, sizeof(buff));
    string file= request->get_url().substr(1);
    string extension = find_url_extension(file);
    cout<<"the exension is "<<extension<<endl;
    if( extension == "css") {
        strcpy(buff,"Connection: keep-alive\r\nContent-Type: text/css; charset=iso-8859-1\r\n\r\n");
    } else if ( extension == "js") {
        strcpy(buff,"Connection: keep-alive\r\nContent-Type: text/javascript; charset=iso-8859-1\r\n\r\n");
    } else {
        strcpy(buff,"Connection: keep-alive\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n");
    }
    if (-1 == write(connfd,buff, strlen(buff)))
        throw  File_description_exception();
    if( file == string{""}) file = Index_file;
    web_directory.serve_resource(connfd, file);
    cout<<"finish send repsonse"<<endl;

}

string Response::find_url_extension(string url)
{
    string::size_type idx;
    idx = url.rfind('.');
    if (idx != string::npos) {
        return url.substr(idx+1);
    } else {
        return "";
    }
}

