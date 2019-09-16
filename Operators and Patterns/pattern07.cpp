#include<iostream> 

using namespace std ; 

 void triangle(int n ){  
 	int stars=1 , space=n/2 ,count=1;  
 	for(int row=1 ; row<=n;row++)
 	{  
     	for(int i=1; i<=space; i++){ 
 			cout<<" "; 
 	   } 
 	   for(int i=count; i<=stars; i++){	
 	    cout<<i;  	
 	   }  

 	   for(int i=stars ;i>count ;i--){ 
 	   	cout<<i-1;
 	   }


	 if(row<=n/2){
	  space--;  
	  stars+=2;
	  count++ ;
    
 	 } 
 	 else { 
	 stars-=2 ; 
	 space++ ; 
	 count-- ; 

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