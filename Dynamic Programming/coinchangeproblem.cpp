#include <iostream>
#include <vector>

using namespace std;

int coinchange(vector<int> &arr, int amount)
{
    vector<int> storage(amount + 1, 0);
    storage[0] = 1;
    int sum = 0;
    for (int i = 1; i < storage.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {   
            if(i-arr[j]>=0)
            {
            sum += storage[i-arr[j]];
            }
            storage[i] = sum;
        }
        sum=0;
    }

    for(int i=0 ; i<storage.size(); i++){ 
        cout<<storage[i]<<" "; 
    }
    return storage[storage.size()-1];
} 


int coinchange_permdp(vector<int> arr ,int target)
{   
    vector<int> storage(target+1,0); 
    storage[0]=1;  
    for(int s=1;s<storage.size(); s++) 
    { 
          for(int i=0; i<arr.size(); i++)
          { 
              int val= s-arr[i];  
              if(val>=0)
              {     
                 storage[s]+=storage[val];   
              }
          } 
   } 
  
  for(int i=0 ; i<storage.size(); i++){ 
    cout<<storage[i]<<" ";
  }  
  return storage[storage.size()-1];
} 


int main()
{ 
    int arr[]= {1,2,5} ;
    vector<int> vs(arr, arr+3); 
    coinchange(vs,11);
    cout<<endl;
    coinchange_permdp(vs,11);
}