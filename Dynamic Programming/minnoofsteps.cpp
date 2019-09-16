#include <iostream>
#include <vector>
using namespace std;

int minnofsteps(vector<int> path)
{
    vector<int> storage(path.size(), 0);

    storage[0] = 1; //path of 0th to 0

    for (int s = 1; s < path.size(); s++)
    {

        for (int js = 1; js <= path[s]; js++)
        {
            int i = s - js;
            if (i >= 0)
            {
                storage[s] += storage[i];
            }
            else
            {
                break;
            }
        }
    }
    return storage[path.size() - 1];
}

int minCostClimbingStairs(int cost[], int n)
{
    int f1 = cost[0], f2 = cost[1];
    for (int i = 2; i < n; i++)
    {
        int f_current = cost[i] + min(f1, f2);
        f1 = f2;
        f2 = f_current;
    }
    return min(f1, f2);
}

int main()
{
    int cost[] = {10,15,20};
    int n = sizeof(cost) / sizeof(int);
    vector<int> arr(cost, cost + n);

    cout << minCostClimbingStairs(cost, n);
    cout << endl
         << " " << minnofsteps(arr);
}