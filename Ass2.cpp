#include<iostream>

using namespace std;

class complex
{
 float r;
 float i;

  public:
   complex()	//Default Constructor
     {
       r=0;
       i=0;
     }

 complex operator+(complex);
 complex operator*(complex);

  friend istream &operator >>(istream &input,complex &t)    //Constructor for taking user input & for creating values entered as input

   {
     cout<<"Enter the real part:";
     input>>t.r;
     cout<<"Enter the imaginary part:";
     input>>t.i;
   }


   friend ostream &operator <<(ostream &output,complex &t)  
    {

      output<<t.r<<"+"<<t.i<<"i\n";

    }
  };


 complex complex::operator+(complex c)		// + Operator Overloading

  {
   complex temp;
   temp.r=r+c.r;
   temp.i=i+c.i;

   return(temp);
 }


  complex complex::operator*(complex c)	// * Operator Overloading

   {
     complex temp2;
     temp2.r=(r*c.r)-(i*c.i);
     temp2.i=(i*c.r)+(r*c.i);

     return (temp2);
   }


   int main()

  {
    complex c1,c2,c3,c4;  
    cout<<"Default constructor value =\n";
    cout<<c1;                              
    cout<<"\nFor 1st number\n";
    cin>>c1;
    cout<<"\nFor 2nd number\n";

	cin>>c2;
	c3=c1+c2;
	c4=c1*c2;


	cout<<"\nThe first number is: ";
	cout<<c1;
	cout<<"\nThe second number is: ";
	cout<<c2;
	cout<<"\nThe addition of complex numbers is : ";
	cout<<c3;
	cout<<"\nThe multiplication of complex numbers is: ";
	cout<<c4;


     return 0;
}
