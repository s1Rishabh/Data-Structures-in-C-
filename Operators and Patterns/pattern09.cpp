#include<iostream> 

using namespace std ; 

 void triangle(int arr[],int n ,int max){ 
    for(int i=0 ;i<max;i++){ 
     	for(int j=0; j<n ; j++){

     		if(i<max-arr[j]){ 
     		cout<<" "; 
     		}
     		else{ 
     		cout<<"*"; 
     		}
     	}
     	cout<<endl;  

     }
   
   }   
  

int main() {

freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/input.txt","r",stdin);
freopen("/Users/rishabhsingh/Documents/Sublime c++/Basic C++ 8 Lectures/output.txt","w",stdout);   
 int n ; 
 cin>>n; 
 int arr[n]; 
 for(int i=0 ; i<n ; i++){
   cin>>arr[i];  
 }
 int max=0 ; 
 for(int i=0 ; i<n ; i++){ 
 	if(max<arr[i]){ 
 	   max=arr[i];
 	}
 } 
 triangle(arr,n ,max) ; 
 return 0 ;
} 