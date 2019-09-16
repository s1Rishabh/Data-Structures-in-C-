#include <iostream>

using namespace std;

// static int k=10 ;  //it creates k
// int k=20 ;  //it creates k'

// int x=10 ;

int y=30 ;
int *fun()
{
    //  int x=10 ;   local variable h funtion m hi maar gyaa!
    // int x=10 ;
    static int x = 20;
    return &x; //address of local variable x has been returned ;
}

// void nfun()
// {

//     int y = 20;
//     y++;
//     cout << y << endl;
// }
// void sfun()
// {
//     // static int y = 20; //decleares in other places
//     y++;
//     cout << y << endl;
// }
int main()
{

    // int *p = fun();
    // cout << p << endl;
    // cout << *p << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     sfun();
    // }
    int x=30 ;
    	int y=20;

     if((&y-&x)> 0) {
     	cout<<"bottom up";
     }
     else{
     	cout<<"topdown";
     }
}