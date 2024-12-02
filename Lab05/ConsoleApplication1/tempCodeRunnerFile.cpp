typedef SinhVien SV;
struct NODE{
     SV info;
     NODE * next;
};

NODE* CreateNode(SV x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);

    p->info = x;
    p->next = NULL;
    return p;
}


struct LIST{
     NODE* pHead;
     NODE *pTail;

};

void AddTail (LIST &L, SV x)
{
     NODE *p =CreateNode(x);
     if(L.pHead==NULL)
     {
          L.pHead=p;
          L.pTail=L.pHead;
     }
     else
     {
         L.pTail->next =p;
         L.pTail=p;
     }
}

void Input(LIST & L)
{
    int n; cin>> n;
    SV a;
    for ( int i=0;i<n ;i++)
    {

        Input(a);
        AddTail(L,a);
    }
}

void Output(SV a)
{
    cout<<a.MASV<<"\t"<<a.HoTen<<"\t"<<a.NgaySinh<<"\t"<<a.GioiTinh<<"\t";
    cout<<a.DiemToan<<"\t"<<a.DiemLy<<"\t"<<a.DiemHoa<<"\t";
    cout<<setprecision(2);
    cout<<a.DTB<<endl;
}

void Output(LIST &L)
{
    while(L.pHead != NULL)
    {
        Output(L.pHead->info);
        L.pHead=L.pHead->next;
    }

}