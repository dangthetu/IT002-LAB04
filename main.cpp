#include <iostream>
#include "CVector.h"

int main() {
    CVector v1, v2;

    std::cout << "Nhap vector thu nhat:\n";
    v1.nhap();

    std::cout << "Nhap vector thu hai:\n";
    v2.nhap();

    std::cout << "Vector 1: ";
    v1.xuat();

    std::cout << "Vector 2: ";
    v2.xuat();

    try {
        CVector tong = v1 + v2;
        std::cout << "Tong hai vector: ";
        tong.xuat();

        std::cout << "Do dai vector 1: " << v1.doDai() << "\n";
        std::cout << "Tich vo huong: " << v1.tichVoHuong(v2) << "\n";
    } catch (std::exception& e) {
        std::cerr << "Loi: " << e.what() << "\n";
    }

    return 0;
}
