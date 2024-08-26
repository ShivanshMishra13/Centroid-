#include "Centroid.cpp"
#include <iostream>

std::string test()
{
    std::cout << "hello" << std::endl;
    return "hello";
}
std::string test2()
{
    std::cout << "helncnfbdlo" << std::endl;
    return "hbdbdbdbdbbdello";
}
int main()
{
    //    HELP::Helper hp=HELP::Helper();
    // std::cout<<hp.isPath("hhdd","hhd")<<std::endl;
    WEB::Server server;
    // server.Get("/",-1, &test);
    //   server.Get("/index",-1,&test);
    //  server.Get("/favicon.ico",-1,&test);
    server.Get("/user/shivansh", 1, &test);
    server.Get("/user/shivansh/y", 1, &test2);

    server.Run();
}