#include<iostream>
#include<vector>
using namespace std;

   

   void exitPoint(vector<vector<int> >& arr) 
    { 

    	int row=0;
    	int col=0; 
    	int d=0; 
    	 //south 

    	while(row<arr.size() && col<arr.size()-1)
    	{
    	if(arr[row][col]==1 && row<arr.size() && col<arr.size() && d==0)
    	{ 	
    		row++; 
    		d=2; 
    	}
    	//east
    	if(arr[row][col]==1 && row<arr.size() && col<arr.size() && d==2)
    	{ 	
    		col--; 
    		d=-1; 
    	}
    	//north
    	if(arr[row][col]==1 && row<arr.size() && col<arr.size() && d==-1)
    	{ 	
    		row--; 
    		d=-2; 
    	}
    	//west
    	if(arr[row][col]==1 && row<arr.size() && col<arr.size() && d==-2)
    	{ 	
    		col++; 
    		d=0; 
    	} 
    	else
    	{ 
    	 //south
    	if(arr[row][col]==0 && row<arr.size() && col<arr.size() &&d==0)
    	{ 	
    		col++; 
    	}
    	//east
    	if(arr[row][col]==0 && row<arr.size() && col<arr.size() && d==2)
    	{ 	
    		row++; 
    	}
    	//north
    	if(arr[row][col]==0 && row<arr.size() && col<arr.size() && d==-1)
    	{ 	
    		col--;
    	}
    	//west
    	if(arr[row][col]==0 && row<arr.size() && col<arr.size() && d==-2)
    	{ 	
    		row--; 
    	} 
   		}
   	} 
	cout<<row<<", "<<col<<" ";
}

   
    int main() {
        int r;
        cin>>r;
        int c;
      	cin >> c;
        vector<vector<int> > arr(r,vector<int>(r,0)); 
        for (int i = 0; i < r; i++) 
        {
            for (int j = 0; j < c; j++) {
                cin>>arr[i][j];
            }

        }
        exitPoint(arr);
    }