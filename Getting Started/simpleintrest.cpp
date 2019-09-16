#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<int> vii;


void simple(){ 
 int p ,r,t ;  
 cin>>p>>r>>t ; 
 int ans= 0 ; 

 ans=p*r*t/100 ; 
 cout<<"Simple Intrest is => "<<ans; 

}  
int main()
{

	freopen("/Users/rishabhsingh/Documents/PracticeCpp/input.txt","r",stdin);
	freopen("/Users/rishabhsingh/Documents/PracticeCpp/output.txt","w",stdout);   
	// hello() ; 
	// largest() ; 
	 simple() ; 
     return 0;
}