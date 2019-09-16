#include<iostream> 

using namespace std ; 

 void triangle(int n ){ 
 	
	for(int row=1 ; row<=n; row++){ 


		for(int col=1 ; col<=n ; col++)
		{    
			if(row==col || (n-row+1)==col){ 
				cout<<"*"  ; 
			}

			else{ 
				cout<<" " ;
			}
		                                   
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