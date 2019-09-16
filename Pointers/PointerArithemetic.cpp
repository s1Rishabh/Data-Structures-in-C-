#include <iostream>

using namespace std;

int main()
{
    //  int arr[4]={1,2,3,4};
    //  cout<<(&arr+1-&arr)<<endl ;
    //  cout<<*arr<<" "<<*arr+1 ;

    int i = 10;
    short int j = 20;
    long long int k = 30;
    cout << sizeof(i) << endl;
    cout << sizeof(j) << endl;
    cout << sizeof(k) << endl;

    cout << endl;

    int *p1 = &i;
    short int *p2 = &j;
    long long int *p3 = &k;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    cout << endl;

    p1++;
    p2++;
    p3++;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    int *p11 = p1 + 1;
    short int *p22 = p2 + 1;
    long long int *p33 = p3 + 1;
    cout << endl;
    cout << *p11 << endl;
    cout << *p22 << endl;
    cout << *p33 << endl;

    cout << endl;
    cout << ((char *)(p11) - (char *)(p1)) << endl;
    cout << p22 - p2 << endl;
    cout << p33 - p3 << endl;

    return 0;
}
