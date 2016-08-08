//
//  main.cpp
//  顺序线性表
//
//  Created by WeiLai’s Macbook Pro on 16/4/23.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//


#include <iostream>

/*------常用宏定义----*/
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
/*------------------*/
#define MAXSIZE 100
typedef int ElemType;
/*---顺序表储存结构---*/
typedef struct
{
    ElemType *elem;
    int length;
}SqList;

Status InitList (SqList &L)
{
    L.elem=new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}

Status GetElem(SqList L,int i,ElemType &e)
{
    if(i<1||i>L.length) return ERROR;
    e=L.elem[i-1];
    return OK;
}

ElemType LocateElem (SqList L,ElemType e)
{
    for (int i=0;i<L.length;i++)
        if(L.elem[i]==e)return i+1;
    return 0;
}

Status ListInsert (SqList &L,int i,ElemType e)
{
    if((i<1)||(i>L.length+1)) return ERROR;
    if(L.length==MAXSIZE) return ERROR;
    for (int j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];
    L.elem[i-1]=e;
    ++L.length;
    return OK;
}

Status ListDelete(SqList &L,int i)
{
    if((i<1)||i>L.length)return ERROR;
    for (int j=i;j<=L.length-1;j++)
        L.elem[j-1]=L.elem[j];
    --L.length;
    return OK;
}

/*-------------------*/
int main()
{
    SqList A;
    InitList(A);
    ListInsert(A, 1, 13);
    int t;
    GetElem(A, 1, t);
    std::cout << t;
    return 0;
}