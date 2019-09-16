#include<iostream> 
#include<string>
#include<vector>
using namespace std;  

void ffr(int sr ,int sc, int er ,int ec ,int arr[][6],string res)
{   

	if(sr>er || sc>ec)
	{ 
			return ; 
	} 
	if(sr==er && sc==ec){ 
		cout<<res<<endl;
		return; 
	} 
	arr[sr][sc]=2;
	if(sc+1<=ec && arr[sr][sc+1]==0){
	ffr(sr,sc+1 ,er,ec,arr,res+"R");
	arr[sr][sc+1]=0;
	}
	 
	if(sr<=er && arr[sr+1][sc]==0){
	ffr(sr+1,sc,er,ec,arr,res+"D");
	arr[sr+1][sc]=0;
	}
	if(sr-1>=0 && arr[sr-1][sc]==0){
	ffr(sr-1,sc ,er,ec,arr,res+"U");
	arr[sr-1][sc]=0;
	}
	if(sc-1>=0 &&arr[sr][sc-1]==0){
	ffr(sr,sc-1,er,ec,arr,res+"L");
	arr[sr][sc-1]=0;
	} 
	arr[sr][sc]=0;
}
int main()
{  
	
int arr[6][6]={
					   {0,1,0,0,0,0}, 
					   {0,1,0,1,1,0},
					   {0,1,0,1,1,0},
					   {0,0,0,0,0,0},
					   {0,1,0,1,1,0},
					   {0,1,0,0,0,0},
		};
   ffr(0,0,5,5,arr,"");
}