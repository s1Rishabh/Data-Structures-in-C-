#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> mazepath(int sr, int sc, int dr, int dc)
{
	if (sr > dr || sc > dc)
	{
		vector<string> v;
		return v;
	}

	if (sr == dr && sc == dc)
	{

		vector<string> vs;
		vs.push_back("");
		return vs;
	}
	vector<string> hor = mazepath(sr + 1, sc, dr, dc);
	vector<string> ver = mazepath(sr, sc + 1, dr, dc);
	vector<string> mr;
	for (int i = 0; i < hor.size(); i++)
	{
		hor[i] = "H" + hor[i];
		mr.push_back(hor[i]);
	}

	for (int i = 0; i < ver.size(); i++)
	{
		ver[i] = "V" + ver[i];
		mr.push_back(ver[i]);
	}

	return mr;
}

void mazepath(int cr, int cc, int er, int ec, string asf)
{
	if (cr > er || cc > ec)
	{
		return;
	}

	if (cr == er && cc == ec)
	{
		cout << asf << endl;
		return;
	}
	mazepath(cr + 1, cc, er, ec, asf + "H");
	mazepath(cr, cc + 1, er, ec, asf + "V");
}
int main()
{
	vector<string> vs = mazepath(0, 0, 3, 3);

	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}
	cout<<endl;
	mazepath(0, 0, 3, 3, "");
}