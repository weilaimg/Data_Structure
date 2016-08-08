//
//  main.cpp
//  循环队列
//
//  Created by WeiLai’s Macbook Pro on 16/8/8.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXQSIZE 100           //队列可能到达的最大长度
typedef int QElemType;
typedef int Status;
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define SElemType int

//-----队列的顺序存储结构---
typedef struct {
    QElemType *base;            //储存空间的基地址
    int front;                  //头指针
    int rear;                   //尾指针
}SqQueue;


//---循环队列的初始化-------
Status InitQueue(SqQueue &Q){
    //构造一个空队列
    Q.base = new QElemType[MAXQSIZE];       //为队列分配数组空间
    if (!Q.base) exit(OVERFLOW);
    Q.front = Q.rear = 0;                   //头指针与尾指针为零，队列为空
    return OK;
}

//----求循环队列的长度-----
int QueueLength (SqQueue Q){
    return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

//----入队--------------
Status EnQueue(SqQueue &Q , QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front){
        return ERROR;
    }
    Q.base[Q.rear]=e;
    Q.rear = (Q.rear+1)%MAXQSIZE;
    return OK;
}

//------出队---------
Status DeQueue (SqQueue &Q,int &e){
    if(Q.front==Q.rear){                //判断队空
        return ERROR;
    }
    e = Q.base[Q.front];                //取队头
    Q.front = (Q.front+1)%MAXQSIZE;     //队送加1
    return OK;
}

//----取循环队列的队头元素-------
SElemType GetHead(SqQueue Q){
    if(Q.front != Q.rear){
        return Q.base[Q.front];
    }
    return ERROR;
}
