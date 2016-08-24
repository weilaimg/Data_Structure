//
//  main.cpp
//  舞伴问题
//
//  Created by WeiLai’s Macbook Pro on 8/24/16.
//  Copyright © 2016 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;
typedef int Status;



//跳舞都个人信息
typedef struct {
    char name [20];
    char sex;
}Person;

//队列的顺序储存结构
#define MAXQSIZE 100
typedef struct {
    Person * base;
    int front;
    int rear;
}SqQueue;

//队列操作
Status InitQueue(SqQueue &Q){
    //构造一个空队列
    Q.base = new Person [MAXQSIZE];
    if(!Q.base) exit(-2);
    Q.front = Q.rear = 0;
    return 1;
}

Status EnQueue(SqQueue &Q,Person e){
    if((Q.rear +1)%MAXQSIZE == Q.front )
        return 0;
    Q.base [Q.rear] = e;
    Q.rear = (Q.rear +1) % MAXQSIZE;
    return 1;
}

Status DeQueue (SqQueue &Q,Person &e){
    //删除队头元素，并取其值
    if(Q.front == Q.rear ) return 0;
    e = Q.base[Q.front];
    Q .front = (Q.front + 1)%MAXQSIZE;
    return 1;
}

Person GetHead (SqQueue Q){
    //返回队头元素，不修改指针
    if(Q.front!= Q.rear){
        return Q.base [Q.front];
    }
    Person e;
    return e;
}

Status QueueEmpty(SqQueue Q){
    if(Q.front == Q.rear ) return 1;
    return 0;
}

SqQueue Mdancers,Fdancers;


void DancerPartner(Person dancer [],int num){
    //结构数组存放dancer性别，num 是跳舞人数
    InitQueue(Mdancers);                    //男队列
    InitQueue(Fdancers);                    //女队列
    int i;
    Person p;
    for (i = 0 ; i < num ; i++){
        p = dancer [i];
        if(p.sex == 'F' ) EnQueue(Fdancers, p);         //插入女队
        else EnQueue(Mdancers, p);                      //插入男队
    }
    cout << "The dancing partners are : \n";
    while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)){
        //依次输出男女姓名
        DeQueue(Fdancers, p);
        cout << p.name << "\t";                                                 //没啥难的，不注释了
        DeQueue(Mdancers, p);
        cout << p.name << "\n";
    }
    if (!QueueEmpty(Fdancers)){
        p = GetHead(Fdancers);
        cout << "The First woman to get a partner is : "<<p.name<<endl;
    }
    else if (!QueueEmpty(Mdancers)){
        p = GetHead(Mdancers);
        cout << "The First man to get a partner is : "<<p.name<<endl;
    }
}
