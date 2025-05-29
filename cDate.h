#pragma once // Tránh việc khai báo lặp lại file header

#include <iostream>  // Thư viện dùng cho nhập xuất
#include <iomanip>   // Thư viện dùng để định dạng đầu ra
using namespace std;

// Lớp cDate dùng để biểu diễn và thao tác với ngày tháng năm
class cDate {
private:
    int day, month, year; // Thuộc tính ngày, tháng, năm

public:
    // Nạp chồng toán tử nhập >> để nhập ngày tháng năm từ bàn phím
    friend istream& operator>>(istream &is, cDate &a);

    // Nạp chồng toán tử xuất << để hiển thị ngày tháng năm ra màn hình
    friend ostream& operator<<(ostream &os, cDate);

    // Nạp chồng toán tử ++ hậu tố: tăng ngày hiện tại lên 1 ngày
    cDate operator++(int);

    // Nạp chồng toán tử -- hậu tố: giảm ngày hiện tại đi 1 ngày
    cDate operator--(int);

    // Nạp chồng toán tử +: trả về ngày mới sau khi cộng thêm số ngày
    cDate operator+(int);

    // Nạp chồng toán tử -: trả về ngày mới sau khi trừ đi số ngày
    cDate operator-(int);

    // Trả về số ngày giữa ngày hiện tại và ngày truyền vào
    int numDate(cDate);

    // Nạp chồng toán tử -: trả về số ngày chênh lệch giữa hai ngày
    int operator-(cDate);
};
