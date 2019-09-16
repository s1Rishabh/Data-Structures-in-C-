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

//sumit bhaiya () 

void primetilln(int n ){ 




}
int main()
{	freopen("/Users/rishabhsingh/Documents/PracticeCpp/input.txt","r",stdin);
	freopen("/Users/rishabhsingh/Documents/PracticeCpp/output.txt","w",stdout);   
	 int n ; 
	 cin>>n ;
	 primetilln(n) ;

    return 0;
}