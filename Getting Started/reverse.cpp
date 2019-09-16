#include<iostream> 
using namespace std ; 

void reverse(int n)
{  int a=0 ,ans=0 ; 
   while(n>0)
   {   a=n%10 ; 
      ans=ans*10+a ; 
      n=n/10 ; 
   }  
   cout<<ans<<endl ; 
}

 int main()
 {  
 	freopen("/Users/rishabhsingh/Documents/PracticeCpp/input.txt","r",stdin);
	freopen("/Users/rishabhsingh/Documents/PracticeCpp/output.txt","w",stdout); 
   int n ; 
   cin>>n; 
   reverse(n) ; 
 }
