//
//  main.cpp
//  链队
//
//  Created by WeiLai’s Macbook Pro on 16/8/8.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
typedef int SElemType;


//----队列的链式储存节构-----
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}Qnode,*QueuePtr;
typedef struct{
    QueuePtr front;             //队头指针
    QueuePtr rear;              //队尾指针
}LinkQueue;

//----初始化------
Status InitQueue (LinkQueue &Q){
//构造一个空队列Q
    Q.front = Q.rear = new QNode;       //生成新结点作为头结点，队头和队尾指针指向此结点
    Q.front -> next =NULL;              //头节点的指针域置空
    return OK;
}

Status EnQueue (LinkQueue &Q,QElemType e){
//插入元素e为Q的新的队尾元素
    QueuePtr p;
    p = new QNode;                      //为入队的元素分配结点空间，用指针p指向
    p->data = e;                        //将新结点数据域置为e
    p->next =NULL;
    Q.rear -> next =p;                  //将新的结点插入到队尾
    Q.rear = p;                         //修改队尾指针
    return OK;
}


Status DeQueue (LinkQueue &Q , QElemType &e){
//删除Q的队头元素
    if(Q.front == Q.rear) return ERROR;     //若队列空，返回ERROR
    QueuePtr p;
    p = Q.front -> next;                    //p指向队头元素
    e = p -> data;                          //e保存队头元素的值
    Q.front -> next = p -> next;            //修改头指针
    if(Q.rear == p) Q.rear = Q.front;       //最后一个元素被删，队尾指针指向头结点
    delete p;                               //释放原队头元素的空间
    return OK;
}


SElemType GetHead (LinkQueue Q){
//返回队头的元素，不修改队头指针
    if(Q.front!=Q.rear){                    //队列非空
        return Q.front -> next -> data;     //返回队头的值，指针不变
    }
    return ERROR;
}
