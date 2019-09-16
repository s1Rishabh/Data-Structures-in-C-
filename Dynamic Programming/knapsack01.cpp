#include<iostream> 
#include<vector>

using namespace std; 
void knapsack(vector<int>& weights , vector<int>& values ,int maxwt)
{   
    vector<vector<int> > board(weights.size()+1, vector<int>(maxwt+1,0)); 


    for(int i=1 ; i<board.size(); i++)
    { 

        for(int j=1; j<board[0].size() ; j++)
        {   
            if(j-weights[i-1]>=0 && board[i-1][j- weights[i-1]] + values[i-1]>= board[i-1][j])
            { 
              board[i][j]=board[i-1][j- wei hts[i-1]] + values[i-1];
            }
            else{ 
              board[i][j]= board[i-1][j];
            } 
        }
    } 

    for(int i=0;i< board.size() ; i++)
    { 
        for(int j=0 ; j<board[0].size(); j++)
        {  
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
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