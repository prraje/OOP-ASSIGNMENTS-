#include<iostream>
#include<limits>

using namespace std;

class demo
{

};
int main()
{
    string city;
	string wheeler;
	
    cout<<"Enter the name of city where you stay: "<<endl;
    cin>>city;
    
    try
     {
         if(city=="mumbai"||city=="pune"||city=="bangalore"||city=="chennai")
         {
             cout<<city<<endl;
         }
         else
         {
            throw demo();
         }
     }
     catch(demo e)
     {
         cout<<"Enter any city between mumbai ,pune, banglore and chennai "<<endl;
     }
     
     
    cout<<"Enter the type of wheeler: "<<endl;
    cin>>wheeler;
    
    
      try
     {
         if(wheeler=="4")
         {
             cout<<wheeler<<endl;
         }
         else
         {
            throw demo();
         }
     }
     catch(demo e)
     {
         cout<<"Enter 4 wheeler"<<endl;
     }

   return 0;
}
