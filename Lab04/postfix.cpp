
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE
{
     float info;
     NODE *pNext;
};

NODE *CreateNode(float x)
{
     NODE *p = new NODE;
     p->info = x;
     p->pNext = NULL;
     return p;
}
struct stack
{
     NODE *top;
};
// kiểm tra stack rỗng
bool empty(const stack &s)
{
     return (s.top == NULL);
}
// tạo stack rỗng
void CreateEmptyStack(stack &s)
{
     s.top = NULL;
}
// thêm phần tử vào đầu stack
void push(stack &s, float x)
{
     NODE *p = CreateNode(x);
     if (s.top == NULL)
          s.top = p;
     else
     {
          p->pNext = s.top;
          s.top = p;
     }
}
// xóa phần tử đầu stack
void pop(stack &s)
{
     if (s.top == NULL)
          return;
     NODE *p = s.top;
     s.top = s.top->pNext;
     delete p;
}
// trả về giá trị đầu của stack
float &top(stack s)
{
     return s.top->info;
}
// ktra phép tính
bool isOperator(char x)
{
     return ((x == '-') || (x == '+') || (x == '*') || (x == '/') || (x == '^'));
}
// ktra dấu ngoặc
bool isBracket(char x)
{
     return ((x == '(') || (x == ')'));
}

void InputPostFix(char postix[], int &n)
{
     char k;
     cin >> k;
     n = 0;
     while (k != '#')
     {
          postix[n++] = k;
          cin >> k;
     }
}

float evaluate_expression(char pf[], int &np)
{
     stack s;
     s.top = NULL;
     float temp;
     for (int i = 0; i < np; i++)
     {
          if (isOperator(pf[i]) == 0)
          {
               push(s, float(pf[i] - '0'));
          }
          else
          {
               float b = top(s);
               pop(s);
               float a = top(s);
               pop(s);

               // Thực hiện phép tính
               switch (pf[i])
               {
               case '+':
                    temp = a + b;
                    break;
               case '-':
                    temp = a - b;
                    break;
               case '*':
                    temp = a * b;
                    break;
               case '/':
                    temp = a / b;
                    break;
               case '^':
                    temp = pow(a, b);
                    break;
               }
               push(s,temp);
          }
     }

     return top(s);
}
int main()
{
     char postfix[MAXN];
     int np;

     InputPostFix(postfix, np);
     // Output(postfix, np);

     cout.precision(3);
     cout << evaluate_expression(postfix, np);

     return 0;
}
// ý tưởng:
/*duyệt qua mảng ký tự, ktra nếu là ký tự số thì
thêm vào stack, nếu là ký tự phép tính thì thực hiện
tính phép tính đó giữa số đó và số trước đó trong stack
sau khi tính xong, kết quả sẽ lưu vào vị trị của số
tiếp theo đó, và xóa ký tự hiện tại ra khỏi stack */