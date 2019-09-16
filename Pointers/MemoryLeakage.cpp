#include <iostream>

using namespace std;

int main()
{  
    int *p1=new  int ;  //single garbage
    int *p2=new int() ;  //o value 
    int *p3= new int(5);  //5 garbage vale 
    int *p4= new int[5];  //array allocation


delete p1 ;
delete p2 ;
delete p3 ;
delete[] p4 ; //always remember
cout<<p1<<" "<<*p1<<endl;
cout<<p2<<" "<< *p2<<endl;
cout<<p3<<" "<<*p3<<endl; 

delete p1 ;
delete p2 ;
delete p3 ;
delete[]p4 ;
for(int i=0 ; i< 4; i++){ 
	cout<<*(p4+i)<<" "<<*(i+p4)<<p4[i]<<" "<<i[p4];
}
return 0 ; 
    return 0;
}
