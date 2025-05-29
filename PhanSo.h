#pragma once
#include <iostream>
using namespace std;

// Lớp PhanSo dùng để biểu diễn và thực hiện các phép toán trên phân số
class PhanSo {
private:
    double tuSo;   // Tử số
    double mauSo;  // Mẫu số
    // Hàm tính ước chung lớn nhất (GCD) bằng thuật toán Euclid
    int gcd(int , int );
    // Hàm rút gọn phân số về dạng tối giản
    void rutGon();

public:
    // Hàm khởi tạo có tham số mặc định: phân số = 0/1
    PhanSo(double tuSo = 0, double mauSo = 1);

    // Nạp chồng toán tử >> để nhập phân số từ bàn phím
    friend istream& operator>>(istream &is, PhanSo &a);

    // Nạp chồng toán tử << để xuất phân số ra màn hình
    friend ostream& operator<<(ostream &os, PhanSo a);

    // Nạp chồng toán tử cộng hai phân số
    PhanSo operator+(PhanSo);

    // Nạp chồng toán tử trừ hai phân số
    PhanSo operator-(PhanSo);

    // Nạp chồng toán tử nhân hai phân số
    PhanSo operator*(PhanSo);

    // Nạp chồng toán tử chia hai phân số
    PhanSo operator/(PhanSo);

    // Nạp chồng toán tử cộng với số nguyên
    PhanSo operator+(int);

    // Nạp chồng toán tử trừ với số nguyên
    PhanSo operator-(int);

    // Nạp chồng toán tử nhân với số nguyên
    PhanSo operator*(int);

    // Nạp chồng toán tử chia với số nguyên
    PhanSo operator/(int);
};
