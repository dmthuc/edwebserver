#ifndef __REQUEST_H
#define __REQUEST_H

class Request {
public:
    explicit Request();
    Request(const Request&) = delete;
    Request(Request &&) = delete;
    Request& operator=(const Request&) = delete;
    Request& operator=(Request &&) = delete;
    void parse_request(const int connfd);


};

void parse_request(const int connfd);
#endif

