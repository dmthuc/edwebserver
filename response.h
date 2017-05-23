#ifndef __RESPONSE_H
#define __RESPONSE_H
namespace Response{
void send_OK_header(const int connfd);
void send_close_connection(const int connfd);
}
#endif

