#include "DaThuc.h"

int main() {
    DaThuc p1, p2,s,m,p;
    cout << "Nhap da thuc thu nhat:\n";
    cin>>p1;
    cout << "Nhap da thuc thu hai:\n";
    cin>>p2;

    cout << "Da thuc 1: \n";
    cout<<p1;
    cout << "Da thuc 2: \n";
    cout<<p2;

    s = p1 + p2;
    m = p1 - p2;
    p = p1 * p2;

    cout << "\nTong: "; cout<<s;
    cout << "Hieu: "; cout<<m;
    cout << "Tich: "; cout<<p;

    double x;
    cout << "\nNhap gia tri x de tinh P1: ";
    cin >> x;
    cout << "P1(" << x << ") = " << p1.giaTri(x) << endl;
    return 0;
}
