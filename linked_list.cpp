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
LNode * listMerge(LNode *head1,LNode *head2);
void linked_list_display(Linklist L);
LNode * listMerge1(LNode *head1,LNode *head2);
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
LNode * listMerge1(LNode *head1,LNode *head2)
{
    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;
    LNode *head = NULL;
    if(head1->data <head2->data)
    {
        head = head1;
        head->next = listMerge1(head1->next,head2);
    }
    else
    {
        head = head2;
        head->next = listMerge1(head1,head2->next);
    }
}
LNode * listMerge(LNode *head1,LNode *head2)
{
    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;
    LNode *head = NULL;
    LNode *p1 = head1;
    LNode *p2 = head2;
    if(p1->data < p2->data)
    {
        head = p1;
        p1 = p1->next;
    }
    else
    {
        head = p2;
        p2 = p2->next;
    }
    LNode *p = head;
    while(p1 && p2)
    {
        if(p1->data < p2->data)
        {
            p->next = p1;
            p1 = p1->next;
        }
        else
        {
            p->next=  p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if(p1)
    {
        p->next = p1;
    }
    else if(p2)
    {
        p->next = p2;
    }
    return head;
}
void linked_list_display(Linklist L)
{
    int cnt = 0;
    while(L){
        if(cnt != 0)cout << "->";
        cout << L->data;
        L = L->next;
        cnt ++;
    }
    cout <<endl;
}
int main() {
    Linklist p1;
    Linklist p2;
    CreateList_R(p1,4);
    CreateList_R(p2,4);
    p1 = p1->next;
    p2 = p2->next;
    cout << "单链表1为： ";
    linked_list_display(p1);
    cout << "单链表2为: ";
    linked_list_display(p2);

    p1 = p1->next;
    p2 = p2->next;
    Linklist p = listMerge(p1,p2);
    cout << "\n归并排序后的链表: ";
    linked_list_display(p);
    return 0;
}
