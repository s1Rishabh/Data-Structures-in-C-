#include <iostream>
#include <vector>

using namespace std;




int countofpallindromicsubstring(string s1) 
{    
  vector<vector<bool> > board(s1.size(), vector<bool>(s1.size(),false));  
   for(int i=0 ; i<board.size();i++)
   { 
       for(int j=0 ,k=j+i ; k<board[0].size(); j++ , k++)
        { 
          if(i==0)
          { 
            board[j][k]=true;
          }  
          else if(i==1)
          { 
              board[j][k]=s1[j]==s1[k]?true:false;
          } 

          else
          {         
                      if(s1[j]==s1[k] && board[j+1][k-1]==true)
                      { 
                           board[j][k]= true;
                      }
                      else
                      {
                         board[j][k]=false;

                      }                   
           }
        }
    }
    long int ans = 0;
        for(auto vec : board)
            for(auto ele : vec)
                ans += ele;
        return ans;
} 

int main()
{
    string s;
    cin>>s;
    cout<<countofpallindromicsubstring(s);
}