 #include<iostream> 
#include<vector>

using namespace std; 
 

 void rodcutting(int n)
 {
  int price[] = {2,1,1}; 

  vector<int> val(n+1);
  int i,j;
 for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
         val[i] = max_val; 
   } 

   for(int i=0 ; i<val.size(); i++){
       cout<<val[i]<<" ";
   }
 }


   int main()
{  
    int x,y,z; 
    cin>>x>>y>>z;

    int weights[]= {x,y,z};
    int n= sizeof(weights)/sizeof(int);
    for(int i=0 ; i<n; i++){
      cout<<weights[i]<<" ";
    } 
    cout<<weights[2];
    // int values[]= {15,14,10,45,30}; 
    // vector<int> vs(weights, weights+5);
    // vector<int> vss(values, values+5); 
    // knapsack(vs,vss,7); 
    // rodcutting(4);
}