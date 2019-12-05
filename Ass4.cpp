#include<iostream>
#include<limits>
using namespace std;
template <class T>
T selection()
{
    T arr[50];
    T temp;
    int n,j;
    
    cout<<"Enter No of Elements you want in an array : "<<endl;
    cin>>n;
    cout<<"Enter Elements in an array :"<<endl;
    
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int  midindex=i;
       for(j=i+1;j<n;j++)
       {
           if(arr[j]<arr[midindex])
           midindex=j;
       }
       temp=arr[i];
       arr[i]=arr[midindex];
       arr[midindex]=temp;

    }
    
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

}

int main()
 {
	cout<<"Integer Sorting :"<<endl;
	selection<int>();

	cout<<"Float Sorting :"<<endl;
	selection<float>();
	
	
    return 0;
 }

