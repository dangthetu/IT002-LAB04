#pragma once
#include <iostream>
#include <math.h>
using namespace std;

// Lớp SoPhuc dùng để biểu diễn và thực hiện các phép toán với số phức
class SoPhuc {
private:
    double iThuc;  // Phần thực của số phức
    double iAo;    // Phần ảo của số phức

public:
    // Hàm khởi tạo với giá trị mặc định là 0 cho cả phần thực và phần ảo
    SoPhuc(int a = 0, int b = 0);

    // Nạp chồng toán tử >> để nhập số phức từ luồng vào
    friend istream& operator>>(istream &is, SoPhuc &a);

    // Nạp chồng toán tử << để xuất số phức ra luồng
    friend ostream& operator<<(ostream &os, SoPhuc a);

    // Nạp chồng toán tử cộng hai số phức
    SoPhuc operator+(SoPhuc);

    // Nạp chồng toán tử trừ hai số phức
    SoPhuc operator-(SoPhuc);

    // Nạp chồng toán tử nhân hai số phức
    SoPhuc operator*(SoPhuc);

    // Nạp chồng toán tử chia hai số phức
    SoPhuc operator/(SoPhuc);

    // Nạp chồng toán tử so sánh bằng giữa hai số phức
    bool operator==(SoPhuc);

    // Nạp chồng toán tử so sánh khác nhau giữa hai số phức
    bool operator!=(SoPhuc);
};
