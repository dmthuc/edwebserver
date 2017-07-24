#ifndef __RESPONSE_H
#define __RESPONSE_H
#include <string>
using namespace std;
class Request;
namespace Response{
    const string Index_file = "index.html";
    void send_close_connection(const int connfd);
    void send_response(const int connfd, Request * request);
    string find_url_extension(string url);
}
#endif

