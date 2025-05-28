#pragma once
#include "PhanSo.h"
#include <cmath>

// Hàm khởi tạo phân số với tử số a và mẫu số b
PhanSo::PhanSo(double a, double b) {
    tuSo = a;
    mauSo = b;
}

// Hàm tính ước chung lớn nhất (GCD) bằng thuật toán Euclid
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Hàm rút gọn phân số về dạng tối giản
void PhanSo::rutGon() {
    int ucln = gcd(tuSo, mauSo); // Tìm ước chung lớn nhất
    tuSo /= ucln;
    mauSo /= ucln;

    // Đảm bảo mẫu số dương
    if (mauSo < 0) {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

// Nạp chồng toán tử >> để nhập phân số từ bàn phím
istream& operator>>(istream &is, PhanSo &a) {
    cout << "Nhap tu so: ";
    is >> a.tuSo;
    cout << "Nhap mau so: ";
    is >> a.mauSo;
    return is;
}

// Nạp chồng toán tử << để xuất phân số ra màn hình
ostream& operator<<(ostream &os, PhanSo a) {
    if (a.mauSo >= 0) {
        os << a.tuSo << "/" << a.mauSo;
    } else {
        // Nếu mẫu âm, đảo dấu tử để phân số vẫn đúng
        os << a.tuSo * (-1) << "/" << abs(a.mauSo);
    }
    return os;
}

// Nạp chồng toán tử cộng hai phân số
PhanSo PhanSo::operator+(PhanSo a) {
    PhanSo kq;
    kq.tuSo = tuSo * a.mauSo + a.tuSo * mauSo; // Quy đồng mẫu và cộng tử
    kq.mauSo = mauSo * a.mauSo;
    kq.rutGon(); // Rút gọn kết quả
    return kq;
}

// Nạp chồng toán tử trừ hai phân số
PhanSo PhanSo::operator-(PhanSo a) {
    PhanSo kq;
    kq.tuSo = tuSo * a.mauSo - a.tuSo * mauSo;
    kq.mauSo = mauSo * a.mauSo;
    kq.rutGon();
    return kq;
}

// Nạp chồng toán tử nhân hai phân số
PhanSo PhanSo::operator*(PhanSo a) {
    PhanSo kq;
    kq.tuSo = tuSo * a.tuSo;
    kq.mauSo = mauSo * a.mauSo;
    kq.rutGon();
    return kq;
}

// Nạp chồng toán tử chia hai phân số
PhanSo PhanSo::operator/(PhanSo a) {
    PhanSo kq;
    kq.tuSo = tuSo * a.mauSo;
    kq.mauSo = mauSo * a.tuSo;
    kq.rutGon();
    return kq;
}

// Nạp chồng toán tử cộng phân số với số nguyên
PhanSo PhanSo::operator+(int a) {
    PhanSo kq;
    kq.tuSo = tuSo + mauSo * a; // a = a/1 -> quy đồng rồi cộng
    kq.mauSo = mauSo;
    kq.rutGon();
    return kq;
}

// Nạp chồng toán tử trừ phân số với số nguyên
PhanSo PhanSo::operator-(int a) {
    PhanSo kq;
    kq.tuSo = tuSo - mauSo * a;
    kq.mauSo = mauSo;
    kq.rutGon();
    return kq;
}

// Nạp chồng toán tử nhân phân số với số nguyên
PhanSo PhanSo::operator*(int a) {
    PhanSo kq;
    kq.tuSo = tuSo * a;
    kq.mauSo = mauSo;
    kq.rutGon();
    return kq;
}

// Nạp chồng toán tử chia phân số với số nguyên
PhanSo PhanSo::operator/(int a) {
    PhanSo kq;
    kq.tuSo = tuSo;
    kq.mauSo = mauSo * a;
    kq.rutGon();
    return kq;
}
