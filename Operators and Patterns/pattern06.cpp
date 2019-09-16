#include<iostream> 

using namespace std ; 

 void triangle(int n ){  
 	int cst=1 , csp=n/2 ,nsp=1 ; 
 	for(int row=0 ; row<n;row++)
 	{  
 	      for(nsp=csp+1;nsp>0 ;nsp--){ 
 			cout<<"*" ; 
 	    	} 
 	      for(int nst=1;nst<=cst ; nst++) { 
 			cout<<" " ;  
 		  }
 		  for(nsp=csp+1 ; nsp>0 ;nsp--){ 
 			cout<<"*" ; 
 	    	} 
	 if(row<n/2){
	  csp--; 
	  cst+=2; 
 	 } 
 	 else { 
	 cst-=2 ; 
	 csp++ ; 
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
//r