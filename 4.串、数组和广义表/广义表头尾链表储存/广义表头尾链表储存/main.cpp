//
//  main.cpp
//  广义表头尾链表储存
//
//  Created by WeiLai’s Macbook Pro on 9/9/16.
//  Copyright © 2016 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;

//--------广义表头尾链表存储表示--------------
typedef int  AtomType ;
typedef enum{ATOM,LIST} ElemTag;

typedef struct GLNode{
    ElemTag tag;
    union{
        AtomType atom;
        struct { struct GLNode *hp ,*tp; }ptr;
    };
}*Glist;

