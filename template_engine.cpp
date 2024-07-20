#include <iostream>

namespace ENGINE
{
class Template
{
    public:
    Template()
    {
        //doing nothing
    }
    std::string Test(std::string str,char letter[],std::string arr[])
    {
        static int counter=0;
        static int lettercounter=0;
        
        std::string result;
        for (char s:str)
        {
            if (s == letter[lettercounter])
            {
                
                result += arr[counter];
                counter++;
                lettercounter++;
            }
            else
            {
                result += s;
            }
        }
        return result;
    }
};

} // namespace ENGINE