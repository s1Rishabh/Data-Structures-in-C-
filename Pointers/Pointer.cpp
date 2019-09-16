#include <iostream>

using namespace std;

int main()
{
    // int i = 10;
    // int *p = &i; //address;
    // int **q = &p;
    // cout << p << endl;
    // cout << *p << endl;
    // cout << q << endl;
    // cout << *q << endl;
    // cout << *q << endl;

    //Pointer demo 

    int arr[4]={1,2,3,4}; 

	 int* p1=arr; 
	 int* p2=&arr[0];
	 int (*p3)[4]=&arr ; 

	 cout<<p1<<endl;
	 cout<<p2<<endl;
	 cout<<p3<<endl;
	 p1++;
	 p2++;
	 p3++;
	 cout<<p1<<endl; 
	 cout<<p2<<endl; 
	 cout<<p3<<endl;  


    //PointerArithemetic

	 cout<<(&arr+1-&arr)<<endl ;
	 cout<<*arr<<" "<<*arr+1 ;


    return 0;
}
