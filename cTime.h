#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

// Lớp cTime dùng để biểu diễn và thao tác với thời gian (giờ, phút, giây)
class cTime {
private:
    int gio, phut, giay; // Các thành phần của thời gian: giờ, phút, giây

public:
    // Nạp chồng toán tử >> để nhập thời gian từ bàn phím
    friend istream& operator>>(istream &is, cTime &a);

    // Nạp chồng toán tử << để xuất thời gian ra màn hình
    friend ostream& operator<<(ostream &os, cTime a);

    // Nạp chồng toán tử hậu tố ++ (tăng 1 giây)
    cTime operator++(int);

    // Nạp chồng toán tử hậu tố -- (giảm 1 giây)
    cTime operator--(int);

    // Nạp chồng toán tử cộng thời gian với số nguyên giây
    cTime operator+(int);

    // Nạp chồng toán tử trừ thời gian với số nguyên giây
    cTime operator-(int);
};
