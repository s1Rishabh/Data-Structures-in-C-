#include<iostream> 
#include<string> 
#include<vector>
using namespace std;


int getlongcom(string s1, string s2)
{
    vector<vector<int> > board(s1.size()+1, vector<int>(s2.size()+1,0));


    for(int i=board.size()-2 ; i >=0  ; i--)
    { 
        for(int j=board.size()-2 ; j>=0 ; j--)
        {  

                if(s1[i]==s2[j]){
                 board[i][j]= board[i+1][j+1] +1;    
                }
                else
                { 
                    board[i][j]= max(board[i+1][j] , board[i][j+1]);
                }
        }
    }  
    return board[0][0];
}


int main()
{
    int t; 
    cin>>t; 

    while(t--)
    {   
        int a,b; 
        cin>>a>>b;
        string s1,s2; 
        cin>>s1>>s2; 
        int ans= getlongcom(s1,s2); 
        cout<<ans; 
    } 
}