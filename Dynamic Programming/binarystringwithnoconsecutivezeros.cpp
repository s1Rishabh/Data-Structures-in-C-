#include <iostream>
#include <vector>
using namespace std;

int find(int n)
{       int ones=1;
        int zeros=1 ;
        int newzeros = 0;
        int newones = 0;
        for(int i=2;  i<=n ; i++){ 
            newzeros=ones;
            newones=ones +zeros;
            ones=newones;
            zeros = newzeros;
        } 
        return newzeros+newones; 
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = find(n);
        cout << ans;
    }
}