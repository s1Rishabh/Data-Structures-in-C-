#include<iostream> 

using namespace std ; 

 void triangle(int n ){    
 	
     int val=1 ,space=2*n-4;
 	for(int row=1 ; row<=n;row++)
 	{     
		for(int i=1;i<=row;i++){ 
 		 	cout<<i ; 
 		}
 		for(int i=space ;i>=0 ; i--)
 		{ 
 		 cout<<" ";
 		}
 		val=row==n?val-1:val ;
		for(int i=val ; i>0 ; i--){ 
 			cout<<i ;
 		} 
 		val++; 
 		space-=2;  
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