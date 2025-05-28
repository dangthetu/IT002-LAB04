#include "SoPhuc.h"

// Hàm khởi tạo: gán giá trị phần thực và phần ảo
SoPhuc::SoPhuc(int a, int b) {
    iThuc = a;
    iAo = b;
}

// Nạp chồng toán tử >> để nhập số phức từ bàn phím
istream& operator>>(istream &is, SoPhuc &a) {
    cout << "Nhap phan thuc: ";
    is >> a.iThuc;
    cout << "Nhap phan ao: ";
    is >> a.iAo;
    return is;
}

// Nạp chồng toán tử << để xuất số phức ra màn hình
ostream& operator<<(ostream &os, SoPhuc a) {
    if (a.iAo >= 0) {
        os << a.iThuc << " + " << a.iAo << "i";  // dạng a + bi
    } else {
        os << a.iThuc << " - " << abs(a.iAo) << "i";  // dạng a - bi
    }
    return os;
}

// Nạp chồng toán tử cộng hai số phức
SoPhuc SoPhuc::operator+(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = this->iThuc + a.iThuc;  // cộng phần thực
    kq.iAo = this->iAo + a.iAo;        // cộng phần ảo
    return kq;
}

// Nạp chồng toán tử trừ hai số phức
SoPhuc SoPhuc::operator-(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = this->iThuc - a.iThuc;  // trừ phần thực
    kq.iAo = this->iAo - a.iAo;        // trừ phần ảo
    return kq;
}

// Nạp chồng toán tử nhân hai số phức
SoPhuc SoPhuc::operator*(SoPhuc a) {
    SoPhuc kq;
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    kq.iThuc = (this->iThuc * a.iThuc) - (this->iAo * a.iAo);  // phần thực
    kq.iAo = (this->iThuc * a.iAo) + (this->iAo * a.iThuc);    // phần ảo
    return kq;
}

// Nạp chồng toán tử chia hai số phức
SoPhuc SoPhuc::operator/(SoPhuc a) {
    SoPhuc kq;
    // mẫu số: c^2 + d^2 với số chia là (c + di)
    int mau = a.iThuc * a.iThuc + a.iAo * a.iAo;

    // kiểm tra chia cho 0
    if (mau == 0) {
        cout << "Loi: chia cho so phuc 0!" << endl;
        return SoPhuc(0, 0); // trả về 0 + 0i nếu lỗi
    }

    // (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
    kq.iThuc = (this->iThuc * a.iThuc + this->iAo * a.iAo) / mau;  // phần thực
    kq.iAo   = (this->iAo * a.iThuc - this->iThuc * a.iAo) / mau;  // phần ảo

    return kq;
}

// Nạp chồng toán tử == để so sánh hai số phức
bool SoPhuc::operator==(SoPhuc a) {
    return (this->iThuc == a.iThuc && this->iAo == a.iAo);
}

// Nạp chồng toán tử != để kiểm tra hai số phức khác nhau
bool SoPhuc::operator!=(SoPhuc a) {
    return !(*this == a); // phủ định kết quả của ==
}
