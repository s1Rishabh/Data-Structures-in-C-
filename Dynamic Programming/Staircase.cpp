#include <iostream>
using namespace std;

int climb(int n, int res[])
{
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n];
}
int climbStairs(int n)
{
    int res[100000];
    int ans = climb(n, res);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);
}