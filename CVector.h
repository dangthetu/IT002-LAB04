#ifndef CVECTOR_H
#define CVECTOR_H

#include <vector>  // Sử dụng để lưu trữ các thành phần của vector

// Lớp CVector biểu diễn vector trong toán học với số chiều bất kỳ
class CVector {
private:
    std::vector<double> data;  // Mảng lưu các thành phần của vector

public:
    // Hàm khởi tạo mặc định - tạo vector rỗng
    CVector();

    // Hàm khởi tạo với số chiều và giá trị mặc định cho từng phần tử
    CVector(int Chieu, double TonTai = 0); // Chieu: số chiều, TonTai: giá trị mặc định

    // Nhập các phần tử của vector từ bàn phím
    void nhap();

    // Xuất vector ra màn hình
    void xuat() const;

    // Trả về số chiều của vector
    int layChieu() const;

    // Tính độ dài (norm) của vector
    double doDai() const;

    // Tính tích vô hướng (dot product) với vector khác
    double tichVoHuong(const CVector& other) const;

    // Toán tử cộng hai vector
    CVector operator+(const CVector& other) const;

    // Toán tử trừ hai vector
    CVector operator-(const CVector& other) const;

    // So sánh hai vector có bằng nhau hay không
    bool operator==(const CVector& other) const;
};

#endif
