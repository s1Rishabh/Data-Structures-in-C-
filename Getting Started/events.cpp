#include<iostream> 
using namespace std ; 
int main()
 {  
 	freopen("/Users/rishabhsingh/Documents/PracticeCpp/input.txt","r",stdin);
	freopen("/Users/rishabhsingh/Documents/PracticeCpp/output.txt","w",stdout); 
   int st1,et1, st2,et2 ; 
   cin>>st1>>et1>>st2>>et2;  

   if(st1<st2 && et1>et2){ 
   cout<<"e2 is in e1 " ;}  
   else if ( st2<st1 && et2>et1)
   { cout<<"e1 is in e2" ; 
   }
   else if((st1<st2 && st2<et1) || (st1<et2 && et2<st2)){
      cout<<"partially overlap";          
   }
   else { 
      cout<<"no overlap" ;
   }
   return 0 ; 
} 
