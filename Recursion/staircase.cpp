#include <iostream>
#include <vector>
using namespace std;

int c = 0;
int staircase(int n, string asf)
{
    if (n < 0)
    {

        return 0;
    }

    if (n == 0)
    {
        cout << asf << endl;
        return 1;
    }
    int a = staircase(n - 1, asf + to_string(1));
    int b = staircase(n - 2, asf + to_string(2));
    int c = staircase(n - 3, asf + to_string(3));
    int sum = a + b + c;

    return sum;
}

int co = 0;
vector<string> stair(int n)
{

    if (n == 0)
    {
        vector<string> ch;
        ch.push_back("");
        return ch;
    }

    if (n < 0)
    {
        vector<string> ch;
        return ch;
    }
    co++;
    vector<string> myans;
    vector<string> rr1 = stair(n - 1);
    vector<string> rr2 = stair(n - 2);
    vector<string> rr3 = stair(n - 3);

    for (int i = 0; i < rr1.size(); i++)
    {
        myans.push_back(to_string(1) + rr1[i]);
    }

    for (int i = 0; i < rr2.size(); i++)
    {
        myans.push_back(to_string(2) + rr2[i]);
    }

    for (int i = 0; i < rr3.size(); i++)
    {
        myans.push_back(to_string(3) + rr3[i]);
    }
    return myans;
}
int main()
{
    // vector<string> ans = stair(5);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans.at(i) << endl;
    // }

    cout << staircase(25, "");
}