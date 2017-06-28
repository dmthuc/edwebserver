#ifndef __RESPONSE_H
#define __RESPONSE_H
#include <string>
using namespace std;
class Request;
namespace Response{
void send_OK_header(const int connfd);
void send_OK_header2(const int connfd);
void send_close_connection(const int connfd);
void send_response(const int connfd, Request * request);
string find_url_extension(string url);
}
#endif

