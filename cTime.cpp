#pragma once
#include "cTime.h"

// Toán tử nhập >> cho lớp cTime
istream& operator>>(istream &is, cTime &a) {
    cout << "Nhap gio: ";
    is >> a.gio;
    cout << "Nhap phut: ";
    is >> a.phut;
    cout << "Nhap giay: ";
    is >> a.giay;
    return is;
}

// Toán tử xuất << cho lớp cTime, in định dạng chuẩn HH:MM:SS
ostream& operator<<(ostream &os, cTime a) {
    os << setfill('0') << setw(2) << a.gio << ":"
       << setfill('0') << setw(2) << a.phut << ":"
       << setfill('0') << setw(2) << a.giay;
    return os;
}

// Toán tử hậu tố ++ (tăng thêm 1 giây)
cTime cTime::operator++(int a) {
    cTime kq = *this;  // sao chép đối tượng hiện tại
    kq.giay++;

    // Nếu giây vượt 59, chuyển sang phút
    if (kq.giay > 59) {
        kq.giay -= 60;
        kq.phut++;
    }

    // Nếu phút vượt 59, chuyển sang giờ
    if (kq.phut > 59) {
        kq.phut = 0;
        kq.gio++;
    }

    // Nếu giờ vượt 23, quay lại 0
    if (kq.gio > 23) {
        kq.gio = 0;
    }

    return kq;
}

// Toán tử hậu tố -- (giảm đi 1 giây)
cTime cTime::operator--(int a) {
    cTime kq = *this;  // sao chép đối tượng hiện tại
    kq.giay--;

    // Nếu giây < 0, trừ 1 phút và cộng thêm 60 giây
    if (kq.giay < 0) {
        kq.giay += 60;
        kq.phut--;
    }

    // Nếu phút < 0, trừ 1 giờ và cộng thêm 60 phút
    if (kq.phut < 0) {
        kq.phut = 59;
        kq.gio--;
    }

    // Nếu giờ < 0, quay lại 23
    if (kq.gio < 0) {
        kq.gio = 23;
    }

    return kq;
}

// Toán tử + cộng thêm số giây
cTime cTime::operator+(int a) {
    cTime kq;
    kq.gio = this->gio;
    kq.phut = this->phut;
    kq.giay = this->giay + a;

    // Chuẩn hóa thời gian khi tổng giây vượt quá 59
    while (kq.giay >= 60) {
        kq.giay -= 60;
        kq.phut++;

        if (kq.phut >= 60) {
            kq.phut = 0;
            kq.gio++;
            if (kq.gio >= 24) {
                kq.gio = 0;
            }
        }
    }

    return kq;
}

// Toán tử - trừ đi số giây
cTime cTime::operator-(int a) {
    cTime kq;
    kq.gio = this->gio;
    kq.phut = this->phut;
    kq.giay = this->giay - a;

    // Chuẩn hóa thời gian khi giây < 0
    while (kq.giay < 0) {
        kq.giay += 60;
        kq.phut--;

        if (kq.phut < 0) {
            kq.phut += 60;
            kq.gio--;
            if (kq.gio < 0) {
                kq.gio += 24;
            }
        }
    }

    return kq;
}
