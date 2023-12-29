#include <iostream>
using namespace std;

class Diem
{
private:
    int iHoanh;
    int iTung;

public:
    Diem()
    {
        this->iHoanh = 0;
        this->iTung = 1;
    }
    Diem(int Hoanh)
    {
        this->iHoanh = Hoanh;
        this->iTung = 1;
    }
    Diem(int Hoanh, int Tung)
    {
        this->iHoanh = Hoanh;
        this->iTung = Tung;
    }
    // Diem(const Diem &x)
    // {
    //     iHoanh=x.iHoanh;
    //     iTung=x.iTung;
    // }
    void Xuat()
    {
        cout << iHoanh << "/" << iTung << endl;
    }

    int GetTungDo()
    {
        return iTung;
    }
    int GetHoanhDo()
    {
        return iHoanh;
    }
    void SetTungDo(int Tung)
    {
        this->iTung = Tung;
    }
    void SetHoanhdo(int Hoanh)
    {
        this->iHoanh = Hoanh;
    }
    Diem TinhTien(int dx, int dy)
    {
        Diem temp=*this;
        temp.iHoanh+=dx;
        temp.iTung+=dy;
        return temp;
    }
};

int main()
{
    Diem d(1, 2);
    d.Xuat();
    cout << "Change?[y/n]" << endl;
    char a;
    cin >> a;
    if (a == 'y')
    {
        int x, y;
        cout << "\nTung:";
        cin >> y;
        d.SetTungDo(y);
        cout << "\nHoanh:";
        cin >> x;
        d.SetHoanhdo(x);
    }
    Diem temp;
    int dx, dy;
    cout << "\nNhap vecto tinh tien:" << endl;
    cin >> dx;
    cin >> dy;

    cout << "\nVecto sau khi tinh tien:" << endl;
    d.TinhTien(dx, dy).Xuat();
}
