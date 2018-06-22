#ifndef __REQUEST_H
#define __REQUEST_H
#include <string>
#include "method.h"

using namespace std;

class Request {
public:
    explicit Request() = default;
    Request(const Request&) = delete;
    Request(Request &&) = delete;
    Request& operator=(const Request&) = delete;
    Request& operator=(Request &&) = delete;
    int parse_request(const int connfd);
    string get_url() const;
    HTTP_METHOD get_method() const;
private:
    HTTP_METHOD method;
    string protocol;
    string url;

};

#endif

