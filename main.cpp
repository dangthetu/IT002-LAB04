#pragma once
#include "cDate.h"

int main(){
cDate a,a1,a2,a3;
int b,d;
cout<<"nhap"<<endl;
cin>>a;
a1=a;
a2=a;
a3=a;
cout<<"cong cong\n";
cout<<a++;
cout<<"\ntru tru\n";
cout<<a1--;
cout<<"\nnhap so de cong/tru\n";
cin>>b;
a2=a2+b;
a3=a3-b;
cout<<a2<<endl<<a3<<endl;
d=a-a3;
cout<<d;
return 0;
}
