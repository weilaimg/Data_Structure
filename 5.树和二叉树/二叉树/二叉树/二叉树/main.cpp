//
//  main.cpp
//  二叉树
//
//  Created by WeiLai’s Macbook Pro on 2016/10/13.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;
typedef int TElemType;


//--二叉树的链式存储---

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;



//---中序遍历的递归方法---

void InOrderTraverse (BiTree T){
    if(T){
        InOrderTraverse(T-> lchild);
        cout << T-> data;
        InOrderTraverse(T-> rchild);
    }
}

//---二叉树中序遍历的非递归算法---
void InOederTraverse_s(BiTree T){
    LinkStack S;
    BiTree p,q;
    InitStack(S);
    p = T;
    q = new BiTNode;
    while(p||!StackEmpty(S)){
        if(p){
            Push(S,p);
            p = p -> lchild;
        } else {
            Pop (S,q);
            cout << q-> data;
            p = q -> rchild;
        }
    }
}