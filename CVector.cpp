// CVector.cpp
#include "CVector.h"
#include <iostream>
#include <cmath>
#include <stdexcept>  // Dùng cho xử lý ngoại lệ (exception)

// Hàm khởi tạo mặc định - tạo vector rỗng
CVector::CVector() {}

// Hàm khởi tạo với số chiều và giá trị mặc định cho từng phần tử
CVector::CVector(int Chieu, double TonTai) {
    data = std::vector<double>(Chieu, TonTai);  // Khởi tạo vector với số chiều và giá trị mặc định
}

// Hàm nhập dữ liệu cho vector từ bàn phím
void CVector::nhap() {
    int n;
    std::cout << "Nhap so chieu cua vector: ";
    std::cin >> n;
    data.resize(n);  // Cập nhật lại kích thước vector
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap gia tri tai chieu thu " << i + 1 << ": ";
        std::cin >> data[i];  // Nhập từng thành phần
    }
}

// Hàm xuất vector ra màn hình
void CVector::xuat() const {
    std::cout << "(";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i != data.size() - 1) std::cout << ", ";  // Thêm dấu phẩy giữa các phần tử
    }
    std::cout << ")\n";
}

// Hàm trả về số chiều của vector
int CVector::layChieu() const {
    return data.size();  // Trả về kích thước của vector
}

// Hàm tính độ dài (norm) của vector
double CVector::doDai() const {
    double tong = 0;
    for (double x : data) {
        tong += x * x;  // Tính tổng bình phương các phần tử
    }
    return std::sqrt(tong);  // Trả về căn bậc hai của tổng
}

// Hàm tính tích vô hướng giữa 2 vector
double CVector::tichVoHuong(const CVector& other) const {
    if (data.size() != other.data.size())
        throw std::length_error("Hai vector khong cung so chieu");  // Báo lỗi nếu không cùng chiều

    double tong = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        tong += data[i] * other.data[i];  // Nhân tương ứng các phần tử và cộng dồn
    }
    return tong;
}

// Toán tử cộng hai vector
CVector CVector::operator+(const CVector& other) const {
    if (data.size() != other.data.size())
        throw std::length_error("Hai vector khong cung so chieu");

    CVector result(data.size());  // Tạo vector kết quả với cùng số chiều
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + other.data[i];  // Cộng từng thành phần tương ứng
    }
    return result;
}

// Toán tử trừ hai vector
CVector CVector::operator-(const CVector& other) const {
    if (data.size() != other.data.size())
        throw std::length_error("Hai vector khong cung so chieu");

    CVector result(data.size());  // Tạo vector kết quả với cùng số chiều
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] - other.data[i];  // Trừ từng thành phần tương ứng
    }
    return result;
}

// Toán tử so sánh bằng hai vector
bool CVector::operator==(const CVector& other) const {
    return data == other.data;  // So sánh hai vector bằng cách so từng phần tử
}
