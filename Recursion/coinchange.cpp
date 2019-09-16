#include <iostream>
using namespace std;


void getsum(int arr[], int n, int c, string asf,int j )
{
    if (c == 0)
    {
        cout << asf << endl;
        return ;
    }

    for (int i =j; i<n; i++)
    {
        if (arr[i] <= c)
        {
            getsum(arr, n, c - arr[i], asf + to_string(arr[i]),i+1);
        }
    } 
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int c;
        cin >> c;
        getsum(arr, n, c, "",0);
    }
    return 0;
}