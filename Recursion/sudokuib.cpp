#include<iostream> 
#include<string>
#include<vector>
using namespace std;  


bool can_place(vector<vector<char> >& board ,int r , int c ,char res){ 
	for(int i=0 ; i<board.size() ; i++){ 
		if(board[r][i]==res){ 
			return false;
		}
	}
	for(int j=0  ;j<board.size() ; j++){ 
		if(board[j][c]==res) { 
			return false; 
		}
	}
	int smrc=(r/3)*3; 
	int smcc=(c/3)*3;
	for(int i=smrc ; i<smrc+3; i++){ 

		for(int j=smcc; j<smcc+3; j++){ 

			if(board[i][j]==res){ 
				return false; 
			}
		}
	}	

	return true;
}


void sudoku_slave(vector<vector<char> >& board ,int bno ,vector<vector<char> >& board2)
{  
	if(bno==board.size()*board.size())
	{ 	
		board2=board;

		return; 
	}
   int r=bno/board.size(); 
   int c=bno%board.size();

   if(board[r][c]==' ')
   {  
   	for(int i=1; i<=9; i++)
   	{ 
   	  if(can_place(board,r,c,i+'0')) {
   	  board[r][c]= (i +'0'); 
   	  sudoku_slave(board,bno+1,board2);
   	  board[r][c]= ' ' ;	
   	  }
   	}
   }
   else
   { 
   sudoku_slave(board,bno+1,board2); 
   } 

}

void sudoku(vector<vector<char> >& board)
{ 
  vector<vector<char> > board2(board.size(),vector<char>(board.size(), ' '));   
  sudoku_slave(board,0 ,board2);

  for(int i=0 ; i<board.size() ; i++)
  { 
  		for(int j=0 ;j<board.size(); j++)
  		{ 

  			board[i][j]=board2[i][j];
  		}
  }  

  for(int i=0 ; i<board.size() ; i++)
  { 
  		for(int j=0 ;j<board.size(); j++)
  		{ 
		 	cout<<board[i][j]<<" ";
  		}
  		cout<<endl;
  }

}

int main(){ 
freopen("/Users/rishabhsingh/Documents/Sublime c++/input.txt","r",stdin);
freopen("/Users/rishabhsingh/Documents/Sublime c++/output.txt","w",stdout);
	
	char arr[9][9] = { { '3', ' ', '6', '5', ' ', '8', '4', ' ', ' ' }, { '5', '2', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, { ' ', '8', '7', ' ', ' ', ' ', ' ', '3', '1' },{ ' ', ' ', '3', ' ', '1', ' ', ' ', '8', ' ' },
 				{ '9', ' ', ' ', '8', '6', '3', ' ', ' ', '5' }, { ' ', '5', ' ', ' ', '9', ' ', '6', ' ', ' '}, { '1', '3', ' ', ' ' , ' ', ' ', '2', '5', ' ' },
				{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', '7', '4' }, { ' ', ' ', '5', '2', ' ', '6', '3', ' ', ' ' } };   


		vector<vector<char> > board ;
        for(int i=0 ; i<9 ; i++)
        { 
            vector<char > row ; 
            for(int j=0 ; j<9 ; j++){ 
                row.push_back(arr[i][j]); 
            }
            board.push_back(row); 
        } 
        
         for(int i=0 ; i<board.size() ; i++)
  { 
      for(int j=0 ;j<board.size(); j++)
      { 
      cout<<board[i][j]<<" ";
      }
      cout<<endl;
  }
		// sudoku(board);
  
}