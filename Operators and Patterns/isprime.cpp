#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<int> vii;

void isprime(int n)
{ 
   int div=2 ; 
   while(div<sqrt(n){ 
	if(n%div==0){ 

		cout<<"Not prime"<<endl ; 
		return;
	}
	div++;
} 
int main()
{	freopen("/Users/rishabhsingh/Documents/PracticeCpp/input.txt","r",stdin);
	freopen("/Users/rishabhsingh/Documents/PracticeCpp/output.txt","w",stdout);   
	 int n ; 
	 cin>>n ;
	 isprime(n) ;

    return 0;
}