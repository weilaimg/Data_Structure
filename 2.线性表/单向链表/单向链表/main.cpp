//
//  main.cpp
//  单向链表
//
//  Created by WeiLai’s Macbook Pro on 16/4/23.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
/*-----单向链表的储存结构-----*/
typedef struct LNode                //加LNode为了指针域定义，若不加，无法定义指针域
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;                   //LNode *p == LinkList p;

Status InitList(LinkList &L)
{
    L=new LNode;
    L->next=NULL;
    return OK;
}

Status GetElem(LinkList L,int i,ElemType &e)
{
    LNode *p;
    p=L->next;int j=1;
    while (p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i) return ERROR;
    e=p->data;
    return OK;
}

LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p;
    p=L->next;
    while (p&&p->data!=e)
        p=p->next;
    return p;
}

Status ListInsert(LinkList &L,int i,ElemType e)
{
    LNode *p,*s;
    int j;
    p=L;j=0;
    while (p&&(j<i-1))
    {p=p->next;++j;}
    if(!p||j>i-1) return ERROR;
    s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status ListDelete(LinkList &L,int i)
{
    LNode *p,*q;
    int j;
    p=L;j=0;
    while ((p->next) && (j<i-1))
    {p=p->next;++j;}
    if(!(p->next)||(j>i-1)) return ERROR;
    q=p->next;
    p->next=q->next;
    delete q;
    return OK;
}

void CreateList_H(LinkList &L,int n)
{
    LNode *p;
    L=new LNode;
    L->next=NULL;
    for(int i=0;i<n;++i)
    {
        p=new LNode;
        std::cin>>p->data;
        p->next=L->next;
        L->next=p;
    }
}

void CreateList_R(LinkList &L,int n)
{
    LNode *p,*r;
    L=new LNode;
    L->next=NULL;
    r=L;
    for(int i=0;i<n;i++)
    {
        p=new LNode;
        std::cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}

