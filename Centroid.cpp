#include "Socket.h"
#include "helper.cpp"
#include <iostream>
#include <conio.h>
#include <map>
#include <vector>
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
        int t = 0;
        int spath;
        std::string fpath = "";
        for (const auto &x : Getmap)
        {
            int k = helper.bestpath(x.first, route);
            if (k > t)
            {
                t = k;
                fpath = x.first;
                spath = x.second;
            }
            else
            {
            }
        }

        for (const auto &x : Getmap)
        {
            if (t > 0)
            {
                std::string h = helper.getparams(route, fpath);
                std::string *xh = helper.getarr(h);
                std::cout << xh[0] + "-params" << std::endl;
                std::cout << helper.getparams(route, fpath) + "util" << std::endl;

                //      std::cout<<kh[0]+"yo this is my output" <<std::endl;
                int datanum = Getdata[spath];
                std::string temp = helper.getData(route, datanum);
                struct HELP::Result gh = helper.extractUrl(temp);

                std::string res = Getarr[spath]();
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

    void Get(std::string route, int datanum, std::string (*func)())
    {
        static int count = 0;
        Getarr[count] = func;
        Getdata[count] = datanum;
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

} // namespace WEB
