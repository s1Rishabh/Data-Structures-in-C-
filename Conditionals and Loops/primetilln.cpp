#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<int> vii;

void primetilln(int n){ 

		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= i; j++) {
				if (i == j)
				 {cout<<i<<endl 	;
				  } 
				 if (i % j == 0) {
			   	 break;
				}
			}
		}
	}

int main()
{	 freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/input.txt","r",stdin);
	 freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/output.txt","w",stdout);   
	 int n ; 
	 cin>>n ;
	 primetilln(n) ;

    return 0;
}