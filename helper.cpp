#include <iostream>

namespace HELP
{
    struct Result{
    std::string data[100];
    
};
class Helper
{
  public:
  
  

    Helper()
    {
        // Doing nothing
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
        int junkSlashCount =(noofs - datapoints);

        int leftSlash = junkSlashCount;
        for (char s : route)
        {
            if (leftSlash == 0)
            {
                result += s;
            }
            else
            {
                if(s=='/'){
                    
                leftSlash -= 1;
                
                }
            }
        }

        
        return result;
    }
   struct Result extractUrl(std::string route){
       struct HELP::Result res;
       int pos=0;
       for(char s:route){
           
           if(s=='/'){
               pos=pos+1;
           }else{
               res.data[pos]+=s;
               
           }
           
           
       }
       return res;
       
   }
};

} // namespace HELP



 