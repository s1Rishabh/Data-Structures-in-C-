#include<iostream> 
#include<string>
#include<vector>
using namespace std; 

string codes[] = {".", "abc", "def", "gh", "jkl", "mno", "pqrs", "tuv", "wx", "yz"}; 

vector<string> code(codes,codes+10); 

int c=0;
int nokiakeypad(string s,string ans)
{   
if(s.size()==0){
c++; 
cout<<ans<<endl;
return -1;
}

int idx=s[0]-'0'; 
string get=codes[idx];
string sub=s.substr(1); 

for(int i=0 ; i<get.size(); i++)
{  		
	nokiakeypad(sub,ans+"-");
	nokiakeypad(sub,ans+get[i]);
}

return c; 
} 
int main()
{   
	cout<<nokiakeypad("19" ,"");
}