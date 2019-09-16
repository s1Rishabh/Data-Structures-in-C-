#include <iostream>
#include <string>
#include <vector>
using namespace std;

//normal print
void subsequences(string s, string asf)
{
	if (s.size() == 0)
	{
		cout << asf << endl;
		return;
	}
	char ch = s[0];
	string sub = s.substr(1);
	subsequences(sub, asf);
	subsequences(sub, asf + ch);
}

//return with vector
vector<string> *subsequences(string s, int ep)
{
	if (ep == -1)
	{
		vector<string> *estr = new vector<string>();
		estr->push_back("");
		return estr;
	}

	char ch = s[ep];
	vector<string> *rr = subsequences(s, ep - 1);
	vector<string> *mr = new vector<string>();

	for (int i = 0; i < rr->size(); i++)
	{
		mr->push_back((*rr)[i] + "-");
		mr->push_back((*rr)[i] + ch);
	}

	return mr;
}

int main()
{
	string s = "abc"; 
	subsequences(s,"");
	vector<string> *vs = subsequences(s, s.size() - 1);
	for (vector<string>::iterator rst = vs->begin(); rst != vs->end(); rst++)
	{
		cout << *rst << endl;
	}
}