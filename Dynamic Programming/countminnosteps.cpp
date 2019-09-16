#include <iostream>
#include <vector>
using namespace std;

int countminnoofstep(vector<int> &cost)
{
    vector<int> storage(cost.size(), -1);
    storage[0] = 1;
    int mymin = INT_MAX;
    for (int s = 1; s < cost.size(); s++)
    {
        for (int js = 1; js < cost[s]; js++)
        {
            int i = s - js;

            if (i >= 0 && storage[i] != -1)
            {
                mymin = min(mymin, storage[i]);
            }
            else
            {
                break;
            }
        }
        if (mymin != INT_MAX)
        {
            storage[s] = mymin + 1;
        }
        else
        {
            storage[s] = -1;
        }
    } 

    for(int i=0 ; i<storage.size(); i++){
        cout<<storage[i]<<" ";
    }
    cout<<endl;
    return storage[storage.size() - 1];
}

int main()
{
    int arr[] = {0, 2, 3, 2, 0, 2, 0, 2, 4};

    vector<int> vs(arr, arr + 9);

    cout << countminnoofstep(vs);
}