#ifndef __WEB_DIRECTORY_H
#define __WEB_DIRECTORY_H
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Web_directory {
private:
    string root_directory;
public:
    explicit Web_directory(string root_directory);
    Web_directory(const Web_directory& web) = delete;
    Web_directory(Web_directory&& web) = delete;
    Web_directory& operator =(const Web_directory&) = delete;
    Web_directory& operator =(Web_directory &&) = delete;
    int serve_resource(const int connfd, const string file_name) const;
    static Web_directory& get_singleton(string _root_directory = "./");
    string get_root_directory() const;
    void set_root_directory(string root_directory);
};

#endif
