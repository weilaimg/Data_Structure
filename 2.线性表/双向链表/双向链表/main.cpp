//
//  main.cpp
//  双向链表
//
//  Created by WeiLai’s Macbook Pro on 16/4/23.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
/*------双向链表的储存结构-----*/
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;

DuLinkList GetElem_Dul(DuLinkList L,int i)
{
    DuLNode *p;
    int j;
    p=L->next;j=1;
    while (p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i) return ERROR;
    return p;
}

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e)
{
    DuLNode *p,*s;
    if(!(p=GetElem_Dul(L,i)))
        return ERROR;
    s=new DuLNode;
    s->data=e;
    s->prior=p->prior;
    p->prior->next=s;
    s->next=p;
    p->prior=s;
    return OK;
}

Status ListDelete_DuL(DuLinkList &L,int i)
{
    DuLNode *p;
    if(!(p=GetElem_Dul(L,i)))
        return ERROR;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    delete p;
    return OK;
}