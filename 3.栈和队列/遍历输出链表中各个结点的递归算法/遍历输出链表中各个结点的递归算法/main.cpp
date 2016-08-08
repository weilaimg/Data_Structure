//
//  main.cpp
//  遍历输出链表中各个结点的递归算法
//
//  Created by WeiLai’s Macbook Pro on 16/8/8.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;


/*---构造一个链栈----*/
typedef struct StackNode{
    int data;
    struct StackNode *next;
    
}*LinkList;


/*---链栈的递归算法---*/

void TraverseList(LinkList p){
    if(p==NULL)return;
    else{
        cout << p->data <<endl;
        TraverseList(p->next);
    }
}


/*---简化链栈的递归算法---*/

void Traverse_List(LinkList p){
    if(p){
        cout << p->data <<endl;
        Traverse_List(p->next);
    }
}