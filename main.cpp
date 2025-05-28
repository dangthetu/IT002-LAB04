#include "cTime.h"

int main(){
cTime a,a1,a2,a3,a4;
int i;
cin>>a;
a1=a;
a2=a;
a3=a;
cout<<a;
cout<<"\nNhap so giay muon cong/tru them ";
cin>>i;
a4=a++;
a3--;
cout<<a4<<endl;
cout<<a3<<endl;
a1=a1+i;
a2=a2-i;
cout<<"cong"<<a1<<endl;
cout<<"tru"<<a2;
}
