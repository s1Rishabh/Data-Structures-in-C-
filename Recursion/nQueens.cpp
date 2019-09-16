#include<iostream> 
#include<string>
#include<vector>
using namespace std;  



bool can_place_queen(vector<vector<bool> >& board ,int i , int j)
{  
	for(int ii=i+1; ii<board.size();  ii++)
	{ 
		if(board[ii][j]){ 
			return false; 
		}
	}


 	for(int ii=i-1; ii>=0;  ii--)
	{ 
		if(board[ii][j])
		{ 
			return false; 
		}
	}

	for(int ij=j+1; ij<board.size();  ij++)
	{ 
		if(board[i][ij]){ 
			return false; 
		}
	}


 	for(int ij=j-1; ij>=0;  ij--)
	{ 
		if(board[i][ij])
		{ 
			return false; 
		}
	} 

	for(int ii=i-1, jj=j+1 ; ii>=0 && jj<board.size(); ii-- ,jj++){ 

		if(board[ii][jj]){ 
			return false;
		}
	}


	for(int ii=i-1, jj=j-1 ; ii>=0 && jj>=0; ii-- ,jj--){ 
		if(board[ii][jj])
		{ 
			return false;
		}
	}
	for(int ii=i+1, jj=j-1 ; ii<board.size() && jj>=0; ii++,jj--)
	{ 

		if(board[ii][jj]){ 
			return false;
		}
	}

	for(int ii=i+1, jj=j+1 ; ii<board.size() && jj<board.size(); ii++,jj++){ 

		if(board[ii][jj]){ 
			return false;
		}
	} 
	return true;
} 


bool isboardsafe(vector<vector<bool> >& board)
{ 
		for(int i =0 ;i <board.size(); i++){ 
				for(int j=0 ; j<board.size(); j++)
				{ 
					if(board[i][j]==true && can_place_queen(board,i,j))
					{
						return true; 
					}	
		} 
	} 
	return false;
}

int counter=0;
void Nqueens(vector<vector<bool> >& board,int vidx,string psf ,int ps)
{   
	if(vidx==board.size()){ 

		if(isboardsafe(board)){ 
			cout<<psf<<endl ;
			counter++;
		}
		return;
	}

	for(int i=ps+1 ;i<board.size()* board.size(); i++)
	{ 
	 int row= i/board.size(); 
	 int col= i%board.size(); 
	 if(board[row][col]==false && can_place_queen(board , row, col)){ 
	 	board[row][col]=true; 
	 	Nqueens(board,vidx+1,psf+to_string(row)+to_string(col)+" " ,i); 
	 	board[row][col]=false;
	 }  
	}

}
int main()
{ 
int arr[4][4] =		 {                  {0,0,0,0} ,
 		 			   				  {0,0,0,0} , 
 		 			   				  {0,0,0,0} ,
 		                              {0,0,0,0}
 		            };
		  vector< vector<bool> > board ; 
            for(int i =0 ; i<4 ; i++){ 
                vector<bool> row;
                for(int j=0 ; j<4 ; j++){
                    row.push_back(arr[i][j]); 
                }
                board.push_back(row); 
            } 

         Nqueens(board,0,"",-1);
         cout<<counter;
    
}