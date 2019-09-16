#include <iostream>
#include <string>

using namespace std;

void path(string s, string arr[], int len, int n, string p)
{
    string sp = p;
    int i;
    if (len == 0)
    {
        cout << sp.substr(0, sp.length() - 1) << ")";
        return;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (arr[i].length() <= s.length() && arr[i] == s.substr(0, arr[i].length()))
            { 
                cout<<arr[i]<< " "; 
                cout<<arr[i].length();  
                cout<<endl;
                path(s.substr(arr[i].length()), arr, len - arr[i].length(), n, p + arr[i] + " ");
            }
        }
    }
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        string arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        string s;
        string p = "(";
        cin >> s;
        sort(arr, arr + n);
        path(s, arr, s.length(), n, p);
        cout << "\n";
    }
    return 0;
}