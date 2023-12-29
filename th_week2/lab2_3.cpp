#include <iostream>
#include <cmath>
using namespace std;
class Diem
{
public:
    float x;
    float y;
    Diem()
    {
        x = 0;
        y = 0;
    }
};
class Dagiac
{
private:
    int n;
    Diem *Dinh;

public:
    void Nhap()
    {
        cout << "Nhap so dinh cua da giac :" << endl;
        cin >> n;
        Dinh = new Diem[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap diem thu:" << i + 1 << endl;
            cin >> Dinh[i].x >> Dinh[i].y;
        }
    }
    void Xuat()
    {

        for (int i = 0; i < n; i++)
        {
            cout << "(" << Dinh[i].x << ";" << Dinh[i].y << ")" << endl;
        }
    }
    Dagiac TinhTien(int dx, int dy)
    {
        Dagiac temp = *this;
        for (int i = 0; i < n; i++)
        {
            temp.Dinh[i].x += dx;
            temp.Dinh[i].y += dy;
        }
        return temp;
    }
    Dagiac PhongTo(int scale)
    {
        Dagiac temp = *this;
        for (int i = 0; i < n; i++)
        {
            temp.Dinh[i].x *= scale;
            temp.Dinh[i].y *= scale;
        }
        return temp;
    }
    Dagiac ThuNho(int scale)
    {
        Dagiac temp = *this;
        for (int i = 0; i < n; i++)
        {
            temp.Dinh[i].x /= scale;
            temp.Dinh[i].y /= scale;
        }
        return temp;
    }

    Dagiac Quay(float alpha)
    {
        Dagiac temp = *this;
        for (int i = 0; i < n; i++)
        {
            temp.Dinh[i].x = Dinh[i].x * cos(alpha) - Dinh[i].y * sin(alpha);
            temp.Dinh[i].y = Dinh[i].x * sin(alpha) + Dinh[i].y * cos(alpha);
        }
        return temp;
    }
    Dagiac(const Dagiac &other)
    {
        n = other.n;
        Dinh = new Diem[n];
        for (int i = 0; i < n; i++)
        {
            Dinh[i] = other.Dinh[i];
        }
    }
    Dagiac()
    {
        // Khởi tạo mặc định cho 'n' và 'Dinh'
        n = 0;
        Dinh = nullptr;
    }

};
int main()
{
    Dagiac dg;
    dg.Nhap();
    dg.Xuat();
    int dx, dy;
    cout << "Nhap vecto tinh tien:" << endl;
    cin >> dx >> dy;
    Dagiac tt = dg.TinhTien(dx, dy);
    cout << "Vecto sau khi tinh tien la:" << endl;
    tt.Xuat();
    dg.Xuat();
    int scale;
    cout << "Nhap he so phong to:";
    cin >> scale;
    Dagiac pt = dg.PhongTo(scale);
    cout << "Da giac sau khi phong to:" << endl;
    pt.Xuat();
    cout << "Nhap he so thu nho:";
    cin >> scale;
    Dagiac tn = dg.ThuNho(scale);
    cout << "Da giac sau khi thu nho:" << endl;
    tn.Xuat();
    int alpha;
    cout << "Nhap goc xoay:";
    cin >> alpha;
    Dagiac xoay = dg.Quay(alpha);
    cout << "Da giac sau khi xoay:" << endl;
    xoay.Xuat();
}