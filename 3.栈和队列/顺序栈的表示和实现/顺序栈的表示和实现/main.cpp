//
//  main.cpp
//  顺序栈的表示和实现
//
//  Created by WeiLai’s Macbook Pro on 16/6/29.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;
/*------常用宏定义----*/
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int  Status;
/*------------------*/
#define MAXSIZE 100
typedef int SElemType;
typedef int ElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack (SqStack &S)
{//构造一个空栈
    S.base=new SElemType[MAXSIZE];
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize=MAXSIZE;
    return OK;
}

Status Push (SqStack &S,SElemType e)
{//插入元素e为新的栈顶元素
    if(S.top-S.base==S.stacksize) return ERROR;
    *S.top++=e;
    return OK;
}

Status Pop (SqStack &S,SElemType &e)
{//删除S的栈顶元素，用e返回其值
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

SElemType GetTop (SqStack S)
{//返回栈顶元素，不修改栈顶指针
    if(S.top!=S.base)
        return *(S.top-1);
    return ERROR;
}

