#include <iostream>
#include <vector>

using namespace std;

int coinchange(vector<int> &arr, int amount)
{
    int max = amount + 1;
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {

        cout << dp[i] << " ";
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int coinchange_dp(vector<int> arr, int target)
{
    vector<int> storage(target + 1, target + 1);
    storage[0] = 0;
    for (int s = 1; s < storage.size(); s++)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            {
                int val = s - arr[i];
                if (val >= 0)
                {
                    storage[s] = min(storage[val] + 1, storage[s]);
                }
            }
        }
    }
    for (int i = 0; i < storage.size(); i++)
    {
        cout << storage[i] << " ";
    }
    return storage[storage.size() - 1];
}

int main()
{
    int arr[] = {1, 2, 5};
    vector<int> vs(arr, arr + 3);
    cout << coinchange(vs, 11);
    cout << endl;
    coinchange_dp(vs, 11);
}