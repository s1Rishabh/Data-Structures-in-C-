#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int fibonacci(int n, int qb[])
{
    if(n==0 || n==1){ 
        return n;
    }

    if (qb[n] != 0)
    {
        return qb[n];
    }
    int fib = fibonacci(n - 1, qb);
    int fib1 = fibonacci(n - 2, qb);
    int sum = fib + fib1;
    qb[n] = sum;
    return sum;
}

long long int fibab(long long int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

int main()
{
    long long int n;
    cin >> n;

    int qb[100];
    cout << fibonacci(n, qb)<<endl; 
    cout<<fibab(n);
}