#include <iostream>
using namespace std;

struct NODE
{
     int info;
     NODE *pNext;
};
struct queue
{
     NODE *front;
     NODE *back;
};
NODE *CreatNode(int x)
{
     NODE *p = new NODE;
     p->info = x;
     p->pNext = NULL;
     return p;
}
void AddTailQ(queue &q, int x)
{
     NODE *p = CreatNode(x);
     if (q.front == NULL)
     {
          q.front = p;
          q.back = q.front;
     }
     else
     {
          q.back->pNext = p;
          q.back = p;
     }
}
void EnQ(queue &q, int &x)
{
     AddTailQ(q, x);
}

void DeQ(queue &q, int &x)
{
     NODE *p;
     if (q.front != NULL)
     {
          x = q.front->info;
          p = q.front;
          q.front = q.front->pNext;
          if (q.front == NULL)
               q.back = NULL;
          delete p;
     }
}
void creQ_EMPTY(queue &q)
{
     q.back = NULL;
     q.front = NULL;
}
void createQueue(queue &q)
{
     creQ_EMPTY(q);
     queue q1;
     creQ_EMPTY(q1);
     int x;
     cin >> x;
     while (x != -1)
     {
          AddTailQ(q1, x);
          cin >> x;
     }
     cout << "output: ";
     NODE *p = q1.front;
     while (q1.front != NULL)
     {
          if (q1.front->info != 0)
          {
               EnQ(q, q1.front->info);
          }
          else if (q.front != NULL)
          {
               int dequeuedValue;
               DeQ(q, dequeuedValue);
               cout << dequeuedValue << " ";
          }
          q1.front = q1.front->pNext;
     }
     cout << "\nfront: ";
     if (q.front != NULL)
          cout << q.front->info;
     cout << "\nback: ";
     if (q.front != NULL)
          cout << q.back->info;
}

int main()
{
     queue q;
     createQueue(q);
     return 0;
}
