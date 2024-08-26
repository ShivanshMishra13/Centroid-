#include <iostream>
#include <vector>
namespace HELP
{
struct Result
{
    std::string data[100];
};
class Helper
{
  public:
    Helper()
    {
        // Doing nothing
    }

    int bestpath(std::string str, std::string path)
    {
        std::string params = "";

        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == str[i])
            {
                params += path[i];
            }
        }
        return params.length();
    }

    std::string *getarr(std::string str)
    {
        std::string *k = new std::string[100];
        int n = 0;

        str.erase(0, 1);
        std::string temp = "";
        int i = 0;
        while (i < str.length())
        {
            if (str[i] == '/')
            {
                k[n] = temp;
                temp = "";
                n++;
            }
            else
            {
                temp += str[i];
            }
            i++;
        }
        k[n] = temp;
        return k;
    }
    std::string getparams(std::string path, std::string str)
    {
        std::string params = path;

        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == str[i])
            {
                params.erase(0, 1);
            }
        }
        return params;
    }
    std::string contains(std::string path, std::string str)
    {
        std::string params = "";

        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == str[i])
            {
                params += path[i];
            }
        }
        return params;
    }
    //split function
    std::string split(std::string str, char target)
    {
        std::string result;
        for (char s : str)
        {
            if (s == target)
            {
                return result;
            }
            else
            {
                result += s;
            }
        }
    }
    std::string Remove(std::string str, char target)
    {
        bool found = false;
        std::string res1;
        std::string res2;
        for (char s : str)
        {
            if (found)
            {
                res2 += s;
            }
            else
            {
                if (s == target)
                {
                    found = true;
                }
                else
                {
                    res1 += s;
                }
            }
        }
        return res2;
    }
    //len func
    int len(std::string str)
    {
        int length = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            length++;
        }
        return length;
    }
    std::string RemoveSpace(std::string str)
    {
        std::string rel;
        for (char s : str)
        {
            if (isspace(s))
            {
            }
            else
            {
                rel += s;
            }
        }
        return rel;
    }

    std::string getData(std::string route, int datapoints)
    {
        int noofs = 0;
        for (char s : route)
        {
            if (s == '/')
            {
                noofs++;
            }
        }
        std::string result = "";
        int junkSlashCount = (noofs - datapoints);

        int leftSlash = junkSlashCount;
        for (char s : route)
        {
            if (leftSlash == 0)
            {
                result += s;
            }
            else
            {
                if (s == '/')
                {
                    leftSlash -= 1;
                }
            }
        }

        return result;
    }
    struct Result extractUrl(std::string route)
    {
        struct HELP::Result res;
        int pos = 0;
        for (char s : route)
        {
            if (s == '/')
            {
                pos = pos + 1;
            }
            else
            {
                res.data[pos] += s;
            }
        }
        return res;
    }
};

} // namespace HELP
