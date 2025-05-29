#pragma once  // Tránh việc include lặp lại file header

#include <iostream>  // Dùng cho nhập xuất
#include <cmath>     // Dùng cho hàm pow (lũy thừa)
#define MAX 50       // Định nghĩa bậc tối đa của đa thức là 49 (0 đến 49)

using namespace std;

// Lớp DaThuc dùng để biểu diễn và xử lý các đa thức một biến
class DaThuc {
private:
    int bac;                  // Thuộc tính lưu bậc của đa thức (bậc cao nhất có hệ số khác 0)
    double heso[MAX];         // Mảng hệ số: heso[i] là hệ số của x^i

public:
    // Nạp chồng toán tử >> để nhập bậc và hệ số của đa thức từ bàn phím
    friend istream& operator>>(istream &is, DaThuc &);

    // Nạp chồng toán tử << để in đa thức ra màn hình dưới dạng dễ đọc
    friend ostream& operator<<(ostream &os, DaThuc);

    // Hàm tính giá trị của đa thức tại một giá trị x cho trước
    double giaTri(double x) const;

    // Nạp chồng toán tử cộng hai đa thức
    DaThuc operator+(DaThuc);

    // Nạp chồng toán tử trừ hai đa thức
    DaThuc operator-(DaThuc);

    // Nạp chồng toán tử nhân hai đa thức
    DaThuc operator*(DaThuc);
};
