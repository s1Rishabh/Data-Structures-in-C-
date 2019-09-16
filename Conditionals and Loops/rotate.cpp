#include<iostream> 
using namespace std ; 

void rotate(int n , int r)
{  int temp=n ; 
   int i=0; 
   while(temp!=0){ 
   	temp=temp/10 ; 
   	i++; 
   } 
   r=r%i ; 
   r=r<0?r+i:r ;  
   int div=1, m=1 ;  
   for(int j=1 ; j<=i ; j++){ 
   	  if(j<=r){ 
   	  	div=div*10 ; 
   	  } 
   	  else{ 
   	  	m=m*10 ; 
   	  }
   }  
    int ans=n/div; 
    int mod=n%div;    
    int fans=0; 
    fans=mod*m+ans;    
    cout<<fans<<endl; 
}

 int main()
 {  
 	 freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/input.txt","r",stdin);
   freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/output.txt","w",stdout);   
   int n, r ; 
   cin>>n>>r ; 
  rotate(n,r) ; 
 }
