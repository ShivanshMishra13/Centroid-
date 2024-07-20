#include "Centroid.cpp"
#include <iostream>

std::string test( )
{
    std::cout << "hello"<< std::endl;
    return "hello";
}
int main()
{
    WEB::Server server;
   // server.Get("/",-1, &test);
 //   server.Get("/index",-1,&test);
  //  server.Get("/favicon.ico",-1,&test);
    server.Get("/user/shivansh", 1,&test);
    

    server.Run();
}