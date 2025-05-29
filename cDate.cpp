#pragma once
#include "cDate.h"
#include <cmath>

// Toán tử nhập >> cho lớp cDate: nhập ngày, tháng, năm từ bàn phím
istream& operator>>(istream &is, cDate &a) {
    cout << "Nhap ngay: ";
    is >> a.day;
    cout << "Nhap thang: ";
    is >> a.month;
    cout << "Nhap nam: ";
    is >> a.year;
    return is;
}

// Toán tử xuất << cho lớp cDate: in ngày/tháng/năm dưới dạng dd-mm-yyyy
ostream& operator<<(ostream &os, cDate a) {
    os << setfill('0') << setw(2) << a.day << "-"
       << setfill('0') << setw(2) << a.month << "-"
       << setfill('0') << setw(4) << a.year;
    return os;
}

// Toán tử ++ hậu tố: trả về ngày kế tiếp của đối tượng hiện tại
cDate cDate::operator++(int b) {
    cDate a = *this; // Sao chép ngày hiện tại

    int maxDay = 0;
    // Xác định số ngày tối đa của tháng hiện tại
    switch (a.month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: maxDay = 31; break;
        case 4: case 6: case 9: case 11: maxDay = 30; break;
        case 2:
            // Kiểm tra năm nhuận
            if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0))
                maxDay = 29;
            else maxDay = 28;
            break;
    }

    a.day++; // Tăng ngày
    if (a.day > maxDay) {
        a.day = 1;
        a.month++;
        if (a.month > 12) {
            a.month = 1;
            a.year++;
        }
    }

    return a;
}

// Toán tử -- hậu tố: trả về ngày trước đó của đối tượng hiện tại
cDate cDate::operator--(int b) {
    cDate a = *this;
    a.day--;

    // Nếu ngày nhỏ hơn 1 thì lùi về tháng trước
    if (a.day < 1) {
        a.month--;

        switch (a.month) {
            case 0: // Nếu đang là tháng 1, thì chuyển về tháng 12 năm trước
                a.month = 12;
                a.day = 31;
                a.year--;
                break;
            case 1: case 3: case 5: case 7: case 8: case 10:
                a.day = 31;
                break;
            case 4: case 6: case 9: case 11:
                a.day = 30;
                break;
            case 2:
                if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0))
                    a.day = 29;
                else
                    a.day = 28;
                break;
        }
    }

    return a;
}

// Toán tử +: cộng thêm số ngày b vào ngày hiện tại
cDate cDate::operator+(int b) {
    cDate a = *this;
    a.day += b;

    while (true) {
        int maxDay = 0;
        switch (a.month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: maxDay = 31; break;
            case 4: case 6: case 9: case 11: maxDay = 30; break;
            case 2:
                if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0))
                    maxDay = 29;
                else maxDay = 28;
                break;
        }

        if (a.day <= maxDay) break;

        a.day -= maxDay;
        a.month++;
        if (a.month > 12) {
            a.month -= 12;
            a.year++;
        }
    }

    return a;
}

// Toán tử -: trừ b ngày khỏi ngày hiện tại
cDate cDate::operator-(int b) {
    cDate a = *this;
    a.day -= b;

    while (a.day <= 0) {
        a.month--;

        switch (a.month) {
            case 0: // Qua năm trước
                a.month = 12;
                a.day = 31 - abs(a.day); // Lùi từ cuối tháng 12
                a.year--;
                break;
            case 1: case 3: case 5: case 7: case 8: case 10:
                a.day = 31 - abs(a.day);
                break;
            case 4: case 6: case 9: case 11:
                a.day = 30 - abs(a.day);
                break;
            case 2:
                if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0))
                    a.day = 29 - abs(a.day);
                else
                    a.day = 28 - abs(a.day);
                break;
        }
    }

    return a;
}

// Hàm numDate: chuyển ngày/tháng/năm thành tổng số ngày tính từ 01/01/0001
int cDate::numDate(cDate a) {
    int countDay = 0;
    int s1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Ngày các tháng thường

    // Nếu là năm nhuận thì tháng 2 có 29 ngày
    if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) {
        s1[1] = 29;
    }

    // Cộng ngày của các tháng trước đó trong năm
    for (int i = 0; i < a.month - 1; i++) {
        countDay += s1[i];
    }

    // Cộng số ngày của tháng hiện tại
    countDay += a.day;

    // Cộng số ngày của toàn bộ các năm trước
    for (int y = 1; y < a.year; y++) {
        countDay += (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 366 : 365;
    }

    return countDay;
}

// Toán tử - giữa hai đối tượng cDate: trả về số ngày chênh lệch giữa chúng
int cDate::operator-(cDate b) {
    int kq = abs(numDate(*this)) - abs(numDate(b));
    return abs(kq); // Trả về giá trị tuyệt đối (không quan tâm ngày nào lớn hơn)
}
