#include <iostream>
#include <vector>
using namespace std;

void countaibjck(string s)
{
    int counta = 0; //ending at a of nature a^i;
    int countb = 0; //ending at a of nature b^j;
    int countc = 0; //ending at a of nature c^k;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == 'a')
        {

            counta = 2 * counta + 1;
        }
        else if (s[i] == 'b')
        {
            countb = 2 * countb + counta;
        }
        else
        {
            countc = 2 * countc + countb;
        } 
        cout << countb;
    }
}

int main()
{
    countaibjck("abcabc"); 
}