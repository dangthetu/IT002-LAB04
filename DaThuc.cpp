#include "DaThuc.h"

// Hàm tính giá trị của đa thức tại x
double DaThuc::giaTri(double x) const {
    double sum = 0;
    // Tính tổng theo công thức: heso[i] * x^i
    for (int i = 0; i <= bac; i++)
        sum += heso[i] * pow(x, i);
    return sum;
}

// Nạp chồng toán tử >> để nhập đa thức
istream& operator>>(istream &is, DaThuc &a) {
    cout << "Nhap bac da thuc (0.." << (MAX-1) << "): ";
    is >> a.bac;

    // Đảm bảo bậc nằm trong giới hạn hợp lệ
    if (a.bac < 0) a.bac = 0;
    if (a.bac >= MAX) a.bac = MAX - 1;

    // Nhập hệ số từ x^0 đến x^bac
    for (int i = 0; i <= a.bac; i++) {
        cout << "Nhap he so cho x^" << i << ": ";
        is >> a.heso[i];
    }

    // Đặt các hệ số bậc cao hơn bằng 0
    for (int i = a.bac + 1; i < MAX; i++)
        a.heso[i] = 0;

    return is;
}

// Nạp chồng toán tử << để in đa thức ra màn hình
ostream& operator<<(ostream &os, const DaThuc a) {
    bool first = true; // Biến dùng để xử lý dấu +/- đầu tiên

    for (int i = a.bac; i >= 0; i--) {
        if (a.heso[i] != 0) {
            // In dấu cộng hoặc trừ nếu không phải phần tử đầu tiên
            if (!first)
                os << (a.heso[i] > 0 ? " + " : " - ");

            // Lấy trị tuyệt đối hệ số nếu không phải phần tử đầu
            double val = (first ? a.heso[i] : fabs(a.heso[i]));

            // Chỉ in hệ số nếu không phải là 1 (trừ trường hợp x^0)
            if (i == 0 || val != 1) os << val;

            // In biến x nếu bậc lớn hơn 0
            if (i > 0) os << "x";

            // In mũ nếu bậc lớn hơn 1
            if (i > 1) os << "^" << i;

            first = false;
        }
    }

    // Nếu tất cả hệ số đều là 0, in ra "0"
    if (first) os << "0";

    return os;
}

// Nạp chồng toán tử cộng 2 đa thức
DaThuc DaThuc::operator+(DaThuc d) {
    DaThuc kq;

    // Bậc kết quả là bậc lớn nhất trong hai đa thức
    kq.bac = max(bac, d.bac);
    if (kq.bac > MAX) kq.bac = MAX;

    // Cộng từng hệ số tương ứng
    for (int i = 0; i <= kq.bac; i++) {
        double a = (i <= bac ? heso[i] : 0);
        double b = (i <= d.bac ? d.heso[i] : 0);
        kq.heso[i] = a + b;
    }

    // Các hệ số dư còn lại gán bằng 0
    for (int i = kq.bac + 1; i <= MAX; i++)
        kq.heso[i] = 0;

    return kq;
}

// Nạp chồng toán tử trừ 2 đa thức
DaThuc DaThuc::operator-(DaThuc d) {
    DaThuc kq;

    // Bậc kết quả là bậc lớn nhất trong hai đa thức
    kq.bac = max(bac, d.bac);
    if (kq.bac > MAX) kq.bac = MAX;

    // Trừ từng hệ số tương ứng
    for (int i = 0; i <= kq.bac; i++) {
        double a = (i <= bac ? heso[i] : 0);
        double b = (i <= d.bac ? d.heso[i] : 0);
        kq.heso[i] = a - b;
    }

    // Các hệ số dư còn lại gán bằng 0
    for (int i = kq.bac + 1; i <= MAX; i++)
        kq.heso[i] = 0;

    return kq;
}

// Nạp chồng toán tử nhân 2 đa thức
DaThuc DaThuc::operator*(DaThuc d) {
    DaThuc kq;

    // Bậc của tích hai đa thức là tổng bậc
    int productBac = bac + d.bac;
    kq.bac = (productBac > MAX ? MAX : productBac);

    // Khởi tạo hệ số bằng 0
    for (int i = 0; i <= kq.bac; i++)
        kq.heso[i] = 0;

    // Nhân từng hệ số của hai đa thức
    for (int i = 0; i <= bac; i++) {
        for (int j = 0; j <= d.bac && i + j <= kq.bac; j++) {
            kq.heso[i + j] += heso[i] * d.heso[j];
        }
    }

    return kq;
}
