#include<iostream> 
using namespace std ; 

void gcd(int n1, int n2)
{
   while(n1%n2!=0)
   {  int rem=n1%n2;
      n1=n2;    
      n2=rem;  
   }  
   cout<<n2<<endl; 
}

 int main()
 {  
 	freopen("/Users/rishabhsingh/Documents/PracticeCpp/input.txt","r",stdin);
	freopen("/Users/rishabhsingh/Documents/PracticeCpp/output.txt","w",stdout); 
   int n1, n2 ; 
   cin>>n1>>n2; 
   gcd(n1,n2) ; 
 }
