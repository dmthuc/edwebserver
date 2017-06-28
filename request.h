#ifndef __REQUEST_H
#define __REQUEST_H
#include <string>
using namespace std;
class Request {
public:
    explicit Request();
    Request(const Request&) = delete;
    Request(Request &&) = delete;
    Request& operator=(const Request&) = delete;
    Request& operator=(Request &&) = delete;
    void parse_request(const int connfd);
    string get_url() const;
private:
    string method;
    string protocol;
    string url;

};

void parse_request(const int connfd);
#endif

