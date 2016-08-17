//
//  main.cpp
//  数制转换
//
//  Created by WeiLai’s Macbook Pro on 16/8/16.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;

//链栈

typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode,*LinkStack;

int InitStack(LinkStack &S){
    S=NULL;
    return 1;
}

int Push (LinkStack &S,int e){
    LinkStack p;
    p = new StackNode;
    p -> data = e;
    p -> next = S;
    S = p;
    return 1;
}

int Pop (LinkStack &S,int &e){
    if(S == NULL) return 0;

    LinkStack p;
    p = S;
    e = p -> data;
    S = S -> next;
    delete p;
    return 1;
}

int StackEmpty(LinkStack &S){
    if (S==NULL)return 1;
    return 0;
}

void conversion(int N){
    LinkStack S;
    InitStack(S);
    while (N){
        Push(S, N%8);
        N=N/8;
    }
    while (!StackEmpty(S)){
        int e;
        Pop(S, e);
        cout << e;
    }
    cout << '\n';
}

int main(){
    int a=9;
    conversion(a);
    return 0;
}
