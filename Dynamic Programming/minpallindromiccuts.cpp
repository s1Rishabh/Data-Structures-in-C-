#include <iostream>
#include <vector>

using namespace std;

int fun(string s)
{
  vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), 0));
  vector<int> cut(s.size(), s.size() - 1);

  for (int j = 0; j < s.size(); j++)
  {
    for (int i = 0; i <= j; i++)
    {
      if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
      {
        dp[i][j] = true;
        if (i == 0)
          cut[j] = 0; //no cut needed
        else
          cut[j] = min(cut[j], cut[i - 1] + 1);
      }
    }
  }
  for (int i = 0; i < cut.size(); i++)
  {
    cout << cut[i] << " ";
  }
  return cut[s.size() - 1];
}

int main()
{
  string s;
  cin >> s;
  cout << fun(s);
}