#include <iostream>
#include <cmath>
using namespace std;
class Diem
{
public:
    float x, y;

public:
    Diem()
    {
        x = 0;
        y = 0;
    }
};
class Tamgiac
{
private:
    Diem A, B, C;

public:
    Tamgiac()
    {
        // Khởi tạo các điểm A, B, C với giá trị mặc định
        A.x = 0;
        A.y = 0;
        B.x = 0;
        B.y = 0;
        C.x = 0;
        C.y = 0;
    }
    void Nhap()
    {
        cout << "\nNhap toa do diem A" << endl;
        cin >> A.x >> A.y;
        cout << "\nNhap toa do diem B" << endl;
        cin >> B.x >> B.y;
        cout << "\nNhap toa do diem C" << endl;
        cin >> C.x >> C.y;
    }
    void Xuat()
    {
        cout << "\nA(" << A.x << "," << A.y << ")";
        cout << "\nB(" << B.x << "," << B.y << ")";
        cout << "\nC(" << C.x << "," << C.y << ")";
    }
    Tamgiac(const Tamgiac &other)
    {
        this->A.x = other.A.x;
        this->B.x = other.B.x;
        this->C.x = other.C.x;
        this->A.y = other.A.y;
        this->B.y = other.B.y;
        this->C.y = other.C.y;
    }
    Tamgiac TinhTien(int dx, int dy)
    {
        Tamgiac temp = *this;
        temp.A.x += dx;
        temp.A.y += dy;
        temp.B.x += dx;
        temp.B.y += dy;
        temp.C.x += dx;
        temp.C.y += dy;
        return temp;
    }
    Tamgiac PhongTo(int scale)
    {
        Tamgiac temp = *this;
        temp.A.x *= scale;
        temp.A.y *= scale;
        temp.B.x *= scale;
        temp.B.y *= scale;
        temp.C.x *= scale;
        temp.C.y *= scale;
        return temp;
    }
    Tamgiac ThuNho(int scale)
    {
        Tamgiac temp = *this;
        temp.A.x /= scale;
        temp.A.y /= scale;
        temp.B.x /= scale;
        temp.B.y /= scale;
        temp.C.x /= scale;
        temp.C.y /= scale;
        return temp;
    }
    Tamgiac Quay(float alpha)
    {
        Tamgiac temp = *this;
        temp.A.x = A.x * cos(alpha) - A.y * sin(alpha);
        temp.A.y = A.x * sin(alpha) + A.y * cos(alpha);
        temp.B.x = B.x * cos(alpha) - B.y * sin(alpha);
        temp.B.y = B.x * sin(alpha) + B.y * cos(alpha);
        temp.C.x = C.x * cos(alpha) - C.y * sin(alpha);
        temp.C.y = C.x * sin(alpha) + C.y * cos(alpha);
        return temp;
    }
};

int main()
{
    Tamgiac tg;
    tg.Nhap();
    tg.Xuat();
    int dx, dy;
    cout << "\nNhap vecto tinh tien" << endl;
    cin >> dx >> dy;
    Tamgiac tt;
    tt = tg.TinhTien(dx, dy);
    cout << "\nToa do tam giac sau khi tinh tien:";
    tt.Xuat();
    Tamgiac pt;
    int scale;
    cout << "\nNhap he so phong to" << endl;
    cin >> scale;
    pt = tg.PhongTo(scale);
    cout << "\nToa do tam giac sau khi phong to:";
    pt.Xuat();
    Tamgiac tn;
    cout << "\nNhap he so thu nho" << endl;
    cin >> scale;
    tn = tg.ThuNho(scale);
    cout << "\nToa do tam giac sau khi thu nho:";
    tn.Xuat();
    Tamgiac quay;
    cout << "\n Nhap goc quay" << endl;
    int alpha;
    cin >> alpha;
    Tamgiac tq;
    quay = tg.Quay(alpha);
    cout << "Toa do tam giac sau khi quay" << endl;
    quay.Xuat();
}