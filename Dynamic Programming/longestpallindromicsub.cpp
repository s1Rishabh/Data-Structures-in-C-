#include <iostream>
#include <vector>

using namespace std;


int longestpallin(string s)
{  
    vector<vector<int> > board(s.size(), vector<int>(s.size(),0)); 

    for(int g=0 ; g<board.size() ; g++)
    {  
        for(int i=0 , j=g+i ; j<board[0].size(); i++,j++)
        { 

            if(g==0)
            { 
                board[i][j]=1;  
            }

            else 
            { 
                if(s[j]==s[i])
                {
                  board[i][j]= 2+board[i+1][j-1];   
                }
                else{
                    board[i][j]= max(board[i][j-1] , board[i+1][j]);
                }
            }
        }
    }
    return board[0][s.size()-1];
}

int main()
{
    string s;
    cin>>s;
    cout<<longestpallin(s);
}