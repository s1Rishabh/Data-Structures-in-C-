#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<int> vii;




 
void largest(){  
int a,b,c ; 
cin>>a ; 
cin>>b ;
cin>>c ; 

if(a>=b&& a>=c) 
{  
	cout<<a; 
} 
else if(b>=c && b>=a){ 
	cout<<b ;
}
else {
	cout<<c ; 
 }
}  


int main()
{

	freopen("/Users/rishabhsingh/Documents/PracticeCpp/input.txt","r",stdin);
	freopen("/Users/rishabhsingh/Documents/PracticeCpp/output.txt","w",stdout);   
	// hello() ; 
	largest() ; 
	// simple() ; 

    return 0;
}