#include <iostream>
#include <iomanip>
#include <cstring> // Thư viện cstring để dùng hàm strcmp
using namespace std;
#define MAXN 100

struct SinhVien
{
     char MASV[10];
     char HoTen[100];
     char NgaySinh[12];
     char GioiTinh;
     float DiemToan, DiemLy, DiemHoa, DTB;
};

void Input(SinhVien &a)
{
     cin.getline(a.MASV, 10);
     cin.getline(a.HoTen, 100);
     cin.getline(a.NgaySinh, 12);
     cin >> a.GioiTinh;
     cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
     a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}

// Phần bổ sung

typedef SinhVien SV;

struct NODE
{
     SV info;
     NODE *next;
};

NODE *CreateNode(SV x)
{
     NODE *p = new NODE;
     if (p == NULL)
     {
          exit(1);
     }
     p->info = x;
     p->next = NULL;
     return p;
}

struct LIST
{
     NODE *pHead;
     NODE *pTail;
     int length;
};

void CreateEmptyList(LIST &L)
{
     L.pHead = NULL;
     L.pTail = NULL;
     L.length = 0;
}

void AddTail(LIST &L, SV x)
{
     NODE *p = CreateNode(x);
     if (L.pHead == NULL)
     {
          L.pHead = p;
          L.pTail = L.pHead;
     }
     else
     {
          L.pTail->next = p;
          L.pTail = p;
     }
     L.length++;
}

void Input(LIST &L)
{
     int n;
     cin >> n;
     SV a;
     for (int i = 0; i < n; i++)
     {
          cin.ignore(); // Bỏ qua ký tự newline sau khi nhập từng sinh viên
          Input(a);
          AddTail(L, a);
     }
}

void Output(SV a)
{
     cout << a.MASV << "\t" << a.HoTen << "\t" << a.NgaySinh << "\t" << a.GioiTinh << "\t";
     cout << a.DiemToan << "\t" << a.DiemLy << "\t" << a.DiemHoa << "\t";

     // Định dạng điểm trung bình
     if (a.DTB == static_cast<int>(a.DTB))
     {
          cout << static_cast<int>(a.DTB) << endl; // Hiển thị nếu là số nguyên
     }
     else
     {
          std::streamsize prec = cout.precision();
          std::ios_base::fmtflags flags = cout.flags();

          // Kiểm tra số chữ số thập phân
          if (a.DTB * 10 == static_cast<int>(a.DTB * 10))
          {
               cout << fixed << setprecision(1) << a.DTB << endl; // Hiển thị nếu chỉ có một chữ số thập phân
          }
          else
          {
               cout << fixed << setprecision(2) << a.DTB << endl; // Hiển thị nếu có hai chữ số thập phân
          }

          cout.precision(prec);
          cout.flags(flags);
     }
}

void Insert_Decreasing(LIST &L, SV sv)
{
     NODE *p = CreateNode(sv);
     if (L.pHead == NULL)
     {
          L.pHead = p;
          L.pTail = L.pHead;
          return;
     }
     NODE *p1 = L.pHead;
     if (strcmp(p->info.MASV, p1->info.MASV) > 0) // So sánh chuỗi MASV
     {
          p->next = L.pHead;
          L.pHead = p;
     }
     else
     {
          while (p1->next != NULL && strcmp(p1->next->info.MASV, p->info.MASV) > 0) // So sánh chuỗi MASV
          {
               p1 = p1->next;
          }
          p->next = p1->next;
          p1->next = p;
          if (p->next == NULL)
          {
               L.pTail = p;
          }
     }
}

void Output(LIST &L)
{
     NODE *temp = L.pHead;
     while (temp != NULL)
     {
          Output(temp->info);
          temp = temp->next;
     }
}

int main()
{
     LIST L;
     L.pHead = L.pTail = NULL;
     CreateEmptyList(L);
     Input(L); // DS đầu vào mặc định có thứ tự Giảm dần theo MASV

     cin.ignore();
     SinhVien sv; // Sinh viên cần chèn
     Input(sv);

     Insert_Decreasing(L, sv);

     Output(L);

     return 0;
}
