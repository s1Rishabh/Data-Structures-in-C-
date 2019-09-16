#include<iostream> 
#include<vector>
using namespace std; 

int mymax;
 void longest_increasing_Subsequences(vector<int>& vs)
 {   
  vector<int> strg(vs.size(),0); 
  strg[0]=1;  
    int omax=INT_MIN;
    for(int i=1; i<strg.size(); i++)
    {     
      mymax=INT_MIN;
        for(int j=i-1 ; j>=0; j--)
        {   
            if(vs[i]>vs[j])
            {    
              if(strg[j]>mymax)
              { 
                mymax=strg[j];
              }
            }
         }  
       strg[i]= mymax +1;

       if(strg[i]>omax){ 
          omax=strg[i];
       }
    }  
    
    for(int i=0 ; i<strg.size(); i++){ 
      cout<<strg[i]<< " ";
    }  

 }