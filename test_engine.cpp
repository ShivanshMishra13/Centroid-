#include<iostream>
#include "template_engine.cpp"

int main(){
   ENGINE::Template temp;
   
   std::string result;
   std::string input="my name is $ oh yeah $";
   char g[]={'$','$'};
   std::string arr[]={"John ","Dollar"};
   
   result=temp.Test(input,g,arr);
   std::cout<<result;
   
}