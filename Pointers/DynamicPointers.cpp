#include <iostream>

using namespace std;


int* takeinput(int s1){ 
    int *arr = new int[s1]; 
    // int arr[s1]; //stack creation
    for(int i=0 ; i<s1 ; i++){
        cin>>arr[i];
    }
    return arr;
} 

int main()
{ 
    int* p=takeinput(10); 
    for(int i=0 ; i<10 ; i++){
        cout<<p[i]<<endl;
    }
    return 0;
}
