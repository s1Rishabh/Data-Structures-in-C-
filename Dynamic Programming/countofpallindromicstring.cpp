#include <iostream>
#include <vector>

using namespace std;


int countofpallindromicstring(string s1) 
{    
    vector<vector<int> > board(s1.size(), vector<int>(s1.size(),0)); 
      
   for(int g=0 ; g<board.size();g++) { 

        for(int i=0 ,j=g+i ; j<board[0].size(); j++ , i++)
        { 

          if(g==0)
          { 
            board[i][j]=1;
          }  
          else if(g==1)
          { 
                  board[i][j]=s1[i]==s1[j]?3:2;
          } 

          else
          {         
                      if(s1[i]==s1[j])
                      { 
                           board[i][j]= 1+board[i+1][j] +board[i][j-1]; 
                      }
                      else
                      {
                         board[i][j]=board[i][j-1] +board[i+1][j]-board[i+1][j-1]; 
                      }                   
           }
        }
    }
  return board[0][board[0].size()-1];
}


 int countPalindromicSubsequences(string S) 
 {
        int N = S.size();
        long MOD = 1e9 + 7;       
        vector<vector<int> > T(N, vector<int>(N, 0));
        
        for (int i = 0; i < N; ++i)
            T[i][i] = 1;
        
        for (int gap = 1; gap < N; ++gap)
        {
            for (int i = 0, j = i+gap; j < N; ++i, ++j) {
                //Fill in T[i][j]
                if (S[i] != S[j]) 
                {
                    T[i][j] = T[i+1][j] + T[i][j-1] - T[i+1][j-1];
                } else {
                    // Si, Si+1, ..., Sj-1, Sj
                    // Si+1, ...., Sj-1
                    T[i][j] = 2 * T[i+1][j-1];
                    
                    int l = i+1, r = j-1;
                    while(l <= r && S[l] != S[i]) l++;
                    while(l <= r && S[r] != S[i]) r--;
                    
                    if (l < r)
                    {
                        // S(i, j) = b # # b . . b # # b where # != b
                        T[i][j] -= T[l+1][r-1];   
                    }
                    
                    if (l == r) {
                        // S(i, j) = b # # b # # b where # != b
                        T[i][j] += 1;
                    }
                    
                    if (l > r) {
                        // S(i, j) = b # # # b where # != b
                        T[i][j] += 2;
                    }
                }
                T[i][j] = (T[i][j] + MOD)%MOD;
            }
        }

        for(int i=0 ; i<N ; i++){
          for(int j=0 ; j<N; j++){
            cout<<T[i][j]<<" ";
          } 
          cout<<endl;
        }
        return T[0][N-1];
    }

int main()
{
    string s;
    cin>>s;
    cout<<countPalindromicSubsequences(s);
}