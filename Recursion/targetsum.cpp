#include<iostream> 
#include<string>
#include<vector>
using namespace std; 


void targetsum(vector<int>& vs,int target , int idx,string psf)
{  
 if(idx==vs.size())
 { 
 return ;
 }  
 if(target==0)
 { 
 cout<<psf<<endl;
  return; 
 }  
for(int i=0 ; i<vs.size() ; i++)
{ 
	if(vs[i]<=target)
	{
	targetsum(vs,target-vs[i], idx+1, psf+to_string(vs[i])); 
	}   
}  
}



vector<vector<int> >* targetsum(vector<int> vs, int ep, int sum,int target)
{  
 if(ep==vs.size())
 { 		
 	 vector<vector<int> >* baseres; 
 	if(sum==0){
 			vector<int> bv; 
			(*baseres).push_back(bv); 	
 	 } 
 	 return baseres; 
 } 

 vector<vector<int> >* cal1=targetsum(vs,ep+1,sum, target); 
 vector<vector<int> >* cal2= targetsum(vs, ep+1 , sum-vs[ep],target);
 vector<vector<int> >* res; 
 for(int i=0 ; i<(*cal1).size(); i++)
 { 
	(*res).push_back((*cal1)[i]); 
 } 

 for(int i=0 ; i<(*cal2).size(); i++){ 
 	(*cal2)[i].push_back(vs[ep]);
 	(*res).push_back((*cal2)[i]);
 } 
 return res; 
}



int main(){ 
freopen("/Users/rishabhsingh/Documents/Sublime c++/input.txt","r",stdin);
freopen("/Users/rishabhsingh/Documents/Sublime c++/output.txt","w",stdout);

int arr[]= {2,3,5,6,7}; 

vector<int> vs(arr, arr+5);  

vector<vector<int> >* target= targetsum(vs,0,0,7); 

		for(int i=0 ;i<target->size();i++)
		{ 
					cout<<"[" ;		
				for(int j=0 ; j<(*target)[i].size();j++){ 

					cout<<(*target)[i][j]<< ",";  
			} 
			cout<<"]"<<endl;
		}  

}