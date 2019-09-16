#include<iostream> 

using namespace std ; 

 void triangle(int n ){ 
	int count=1 ; 
	for(int i=1 ; i<=n; i++){ 

		for(int j=1 ; j<=i ; j++){ 
		  cout<<count<<"\t " ; 
		  count++ ; 	
		}
		cout<<endl ; 
	} 

}
int main() {

freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/input.txt","r",stdin);
freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/output.txt","w",stdout);   

int n ; 
cin>>n ;
triangle(n) ; 
return 0 ;
}
// reviewed
