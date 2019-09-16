#include <iostream>
#include <string>

using namespace std;

string s1;
string s2;
string s3;

int gnas(string s, int map[])
{
    int ans = 0;

    int p = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans += map[s[i] - 'a'] * p;
        p *= 10;
    }

    return ans;
}

int c = 0;
void crypto(string qs, int map[], bool dusf[])
{
    if (qs.size() == 0)
    {
        int nfs1 = gnas(s1, map);
        int nfs2 = gnas(s2, map);
        int nfs3 = gnas(s3, map);

        if (nfs1 + nfs2 == nfs3)
        {
            c++;
            cout << "------------" << c << "---------------" << endl;
            cout << " " << nfs1 << endl;
            cout << "+" << nfs2 << endl;
            cout << "--------" << endl;
            cout << nfs3 << endl;
            cout << "------------" << c << "---------------" << endl;
        }

        return;
    }

    char ch = qs[0];
    string roq = qs.substr(1);

    for (int d = 0; d <= 9; d++)
    {
        if (dusf[d] == false)
        {
            dusf[d] = true;
            map[ch - 'a'] = d;
            crypto(roq, map, dusf);
            dusf[d] = false;
            map[ch - 'a'] = -1;
        }
    }
}

string gus()
{
    string s = "";
    bool used[26] = {false};

    for (int i = 0; i < s1.size(); i++)
    {
        if (used[s1[i] - 'a'] == false)
        {
            used[s1[i] - 'a'] = true;
            s += s1[i];
        }
    }

    for (int i = 0; i < s2.size(); i++)
    {
        if (used[s2[i] - 'a'] == false)
        {
            used[s2[i] - 'a'] = true;
            s += s2[i];
        }
    }

    for (int i = 0; i < s3.size(); i++)
    {
        if (used[s3[i] - 'a'] == false)
        {
            used[s3[i] - 'a'] = true;
            s += s3[i];
        }
    }

    return s;
}

int main(int rgc, char **argv)
{
    s1 = "send";
    s2 = "more";
    s3 = "money";

    string qs = gus();
    int amap[26] = {-1};
    bool dusf[10] = {false};
    crypto(qs, amap, dusf);
}
