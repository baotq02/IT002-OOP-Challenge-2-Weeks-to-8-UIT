#include <iostream>
#include <string>
using namespace std;

class ThiSinh {
private:
    string Ten;
    string MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;

public:
    void Nhap() {
        cout << "Nhap ten thi sinh: "; getline(cin, Ten);
        cout << "Nhap MSSV: "; getline(cin, MSSV);
        cout << "Nhap ngay sinh: "; cin >> iNgay;
        cout << "Nhap thang sinh: "; cin >> iThang;
        cout << "Nhap nam sinh: "; cin >> iNam;
        cout << "Nhap diem Toan: "; cin >> fToan;
        cout << "Nhap diem Van: "; cin >> fVan;
        cout << "Nhap diem Anh: "; cin >> fAnh;
        cin.ignore(); // Ignore the newline character left in the input buffer
    }

    void Xuat() {
        cout << "Thi sinh: " << Ten << endl;
        cout << "MSSV: " << MSSV << endl;
        cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
        cout << "Diem Toan: " << fToan << endl;
        cout << "Diem Van: " << fVan << endl;
        cout << "Diem Anh: " << fAnh << endl;
        cout << "Tong diem: " << Tong() << endl;
    }

    float Tong() {
        return fToan + fVan + fAnh;
    }

    // Accessor for MSSV to use outside the class
    string getMSSV() {
        return MSSV;
    }
};

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character left in the input buffer

    ThiSinh* thisinh = new ThiSinh[n];
    ThiSinh thiSinhDiemCaoNhat;

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
        thisinh[i].Nhap();
    }

    for (int i = 0; i < n; i++) {
        if (thisinh[i].Tong() > 15) {
            cout << "Thong tin thi sinh co tong diem lon hon 15: " << endl;
            thisinh[i].Xuat();
        }
    }

    float maxScore = 0;
    for (int i = 0; i < n; i++) {
        if (thisinh[i].Tong() > maxScore) {
            maxScore = thisinh[i].Tong();
            thiSinhDiemCaoNhat = thisinh[i];
        }
    }

    cout << "Thong tin thi sinh co diem cao nhat: " << endl;
    thiSinhDiemCaoNhat.Xuat();

    // Check if the user is the highest scorer
    if (thiSinhDiemCaoNhat.getMSSV() == "your_mssv_here") {
        cout << "Ban co diem so cao nhat!" << endl;
    }

    delete[] thisinh;
    return 0;
}
