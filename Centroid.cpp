#include "Socket.h"
#include "helper.cpp"
#include <iostream>
#include <conio.h>
#include <map>

namespace WEB
{
class Server
{
    HELP::Helper helper;
    using fn = std::string();
    fn *Getarr[1000];
    std::map<std::string, int> Getmap;
    std::map<int, int> Getdata;
    NETWORK::Socket server;

  public:
    Server()
    {
    }

    void Run()
    {
        std::cout << "Server running on 127.0.0.1:8080" << std::endl;

        Serve();
    }
    void Serve()
    {
        while (true)
        {
            int connection = server.Accept();
            std::string msg = server.Read(connection);
          
            std::string route = GetRoute(msg);

            

            bool response = SendData(route, connection);

            if (response)
            {
                std::cout << "succesfull" << std::endl;
            }
            else
            {
                std::cout << "unsuccesfull" << std::endl;
            }
        }
    }

    bool SendData(std::string route, int connection)
    {
        for (const auto &x : Getmap)
        {
           
            if (x.first == route)
            {
              int datanum=Getdata[x.second];
              std::string temp=helper.getData(route,datanum);
              struct HELP::Result gh=helper.extractUrl(temp);
              
              
                std::string res = Getarr[x.second]();
                server.Send(connection, "HTTP/1.0 200 OK\n");
                server.Send(connection, "Content-Type: text/html\n");
                server.Send(connection, "\n");
                server.Send(connection, res);

                server.Close(connection);
                return true;
            }
        }

        
        server.Send(connection, "HTTP/1.0 200 OK\n");
        server.Send(connection, "Content-Type: text/html\n");
        server.Send(connection, "\n");
        server.Send(connection, "<h1>path not found 404</h1>");
        server.Close(connection);

        return false;
    }

    void Get(std::string route, int datanum,std::string (*func)())
    {
        static int count = 0;
        Getarr[count] = func;
        Getdata[count]=datanum;
        Getmap[route] = count;

        count++;
    }

    std::string GetRoute(std::string str)
    {
        std::string r = helper.split(str, 'H');
        std::string route = helper.Remove(r, 'T');
        std::string url = helper.RemoveSpace(route);
        std::cout << url << std::endl;
        return url;
    }
};

} // namespace Web
