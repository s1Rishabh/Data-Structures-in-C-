#include<iostream> 
#include<vector>

using namespace std; 
void knapsack(vector<int>& weights , vector<int>& values ,int maxwt)
{   
    
    vector<int> board(maxwt+1,0);
    for(int i=1 ; i<board.size(); i++)
    { 
        for(int j=0; j<weights.size() ; j++)
        {    
            if(i>=weights[j])
            board[i]= max(board[i-weights[j-1]]+ values[j] , board[i]);
        }
    } 
    for(int i=0;i< board.size() ; i++)
    {   
        cout<<board[i]<<" ";
    } 

}


int main()
{  
    int weights[]= {2,5,1,3,4};
    int values[]= {15,14,10,45,30}; 
    vector<int> vs(weights, weights+5);
    vector<int> vss(values, values+5); 
    knapsack(vs,vss,7);
}