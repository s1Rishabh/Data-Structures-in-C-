#include <iostream>
#include <vector>
#include <string>
using namespace std;

void queen(vector<bool> &board, int cq, string asf, int tq, int tb)
{
    if (cq > tq)
    {
        cout << asf << endl;
        return;
    }
    for (int b = 0; b < board.size(); b++)
    {
        if (board[b] == false)
        {
            board[b] = true;
            queen(board, cq + 1, asf + " b "+to_string(b) + "q" + to_string(cq),tq, tb);
            board[b] = false;
        }
    }
} 


void printprembitmask(int cq,int boxbm,string asf, int tq, int tb ) {  
 	if(cq>tq){ 
 		cout<<asf<<endl;
 		return;
 	}
	for(int i=0; i<tb;  i++){ 		  
		if((boxbm&(1<<i))==0) 
		{   boxbm =boxbm^(1<<i);
			printprembitmask(cq+1,boxbm ,asf+"b"+to_string(i)+"q"+to_string(i) +" ",tq,tb); 
			boxbm =boxbm^(1<<i);
		}
	}
} 

 void printcomb(int cq,bool boxes[],string asf, int tq, int tb ,int lqpiwb) { 
 
 	if(cq>tq){ 
 		cout<<asf<<endl;
 		return;
 	}
	for(int i=lqpiwb+1; i<tb;  i++){ 
		if(boxes[i]==false){  
			boxes[i]=true; 
			printcomb(cq+1,boxes ,asf+"b"+to_string(i)+"q"+to_string(i) +" ",tq,tb,cq);	
			boxes[i]=false;   
		}
	}
}  

void printcomb1(int cq, int cb, string asf, int tq, int tb){ 

 if(cb>tb)
 { 
 	if(cq==tq)
 	{ 
 		cout<<asf<<endl; 
 	}
 	return; 
 }
 
 printcomb1(cq+1,cb+1,asf+"b"+to_string(cb)+"q"+to_string(cq)+" ",tq,tb);	
 printcomb1(cq,cb+1,asf,tq,tb);
}     
int main()
{
    vector<bool> board(4, false);
    queen(board, 0, "", 2, 4);
}
