#include<iostream>

using namespace std;

class Shape	//base class
 {
    public:
      double a,b;

        void get_data ()	//Accepting Values
        {
            cin>>a>>b;
        }
        virtual void display_area () = 0;
 };
 
class Triangle:public Shape	// calculating & Displaying area

 {
    public:

      void display_area ()

    {
        cout<<"Area of ▲ "<<0.5*a*b<<endl;
    }
 };
 
  class Rectangle:public Shape 	// calculating & Displaying area

	{
    	public: 

           void display_area ()
   	{
          cout<<"Area of ━ "<<a*b<<endl;
        }
    };
 
   int main()			
    {   

    	Triangle t;
    	Shape *st = &t;
    	cout<<"Enter base and height of ▲ : ";
    	st->get_data();
    	st->display_area();
     
    	Rectangle r;
    	Shape *sr = &r;
    	cout<<"Enter length and breadth of ━: ";
    	sr->get_data();
    	sr->display_area();


    return 0;   
}
