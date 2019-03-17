#include <iostream>
# define OK 1
# define ERROR 0
typedef int ElemType ;
typedef struct LNode {
    ElemType data;
    struct LNode * next;
} LNode,*Linklist;
using namespace std;
int InitList(Linklist & L);
int GetElem(Linklist L,int i,ElemType &e);
LNode * LocateElem(Linklist L,ElemType e);
int ListInsert(Linklist & L,int i,ElemType e);
int ListDelete(Linklist &L,int i);
void CreateList_H(Linklist & L,int n);
void CreateList_R(Linklist & L,int n);
int InitList(Linklist & L) {
    L = new LNode;
    L->next = NULL;
    return OK;

}
int GetElem(Linklist L,int i,ElemType &e) {
    Linklist p = L->next;
    int j = 1;
    while(p&&j<i) {
        p=p->next;
        ++j;
    }
    if(!p||j>i)return ERROR;
    e=p->data;
    return OK;
}
LNode * LocateElem(Linklist L,ElemType e) {
    Linklist p=L->next;
    while(p&&p->data!=e) {
        p = p->next;
    }
    return p;
}
int ListInsert(Linklist & L,int i,ElemType e) {
    Linklist p=L;
    int j=0;
    while(p&&(j < i-1)) {
        p=p->next;
        ++j;
    }
    if(!p||(j>i-1))return ERROR;
    Linklist s = new LNode;
    s->data= e;
    s->next = p->next;
    p->next = s;
    return OK;
}
int ListDelete(Linklist &L,int i) {
    Linklist p = L;
    int j=0;
    while((p->next)&&(j<i-1)) {
        p=p->next;
        ++j;
    }
    if(!(p->next)||(j>i-1))return ERROR;
    Linklist q = p->next;
    p->next=q->next;
    delete q;
    return OK;
}
void CreateList_H(Linklist & L,int n) {
    // 逆序输入ｎ个元素的值，建立带头节点的单列表Ｌ
    L = new LNode;
    L->next = NULL;
    for(int i =0; i<n ; i++) {
        Linklist p = new LNode;
        cin >> p->data;
        p->next=L->next;
        L->next =p;
    }
}
void CreateList_R(Linklist & L,int n) {
    L=new LNode;
    L->next=NULL;
    Linklist r = L;
    for(int i =0; i<n; i++) {
        Linklist p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next = p;
        r = p;
    }
}
int main() {
    Linklist p;
    InitList(p);
    ListInsert(p,1,12);
    int e=0;
    GetElem(p,1,e);
    cout << e << endl;
    cout <<LocateElem(p,12)->data;
    cout << ListDelete(p,1) << endl;
    return 0;
}
