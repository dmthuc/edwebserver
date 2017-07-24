#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "web_directory.h"
#include "File_description_exception.h"
using namespace std;
Web_directory::Web_directory(string _root_directory)
    :root_directory(_root_directory)
{

}

int Web_directory::serve_resource(const int connfd, const string file_name) const
{
    // open file name
    if( connfd < 0)
        throw File_description_exception();    
    string path=root_directory+file_name;
    ifstream in(path);
    if (!in) cerr << "no file\n";
    for( string line; getline(in,line);)
    {   
        cout<<line;
        if (-1 == write(connfd,line.c_str(), line.length()))
            throw File_description_exception();    
        if (-1 == write(connfd,"\r\n", 2))
            throw File_description_exception();    
    }
    
    // copy content of file name to conndf
}

Web_directory& Web_directory::get_singleton(string _root_directory)
{
    static Web_directory singleton(_root_directory);
    return singleton;
}

string Web_directory::get_root_directory() const
{
    return root_directory;
}

void Web_directory::set_root_directory(string _root_directory)
{
    root_directory = _root_directory;
}

