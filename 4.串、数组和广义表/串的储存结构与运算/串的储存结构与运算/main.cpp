//
//  main.cpp
//  串的储存结构与运算
//
//  Created by WeiLai’s Macbook Pro on 8/25/16.
//  Copyright © 2016 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;


//---------串的定长顺序储存结构------------
#define MAXLEN 255                  //串的最大储存长度
typedef struct {
    char ch[MAXLEN+1];              //存储串的一维数组
    int length;                     //串的当前长度
}SString;

//---------串的堆式顺序储存结构------------
typedef struct{
    char *ch;                       //若是非空串，则按串长分配储存区，否则ch为NULL
    int length;                     //串和当前长度
}HString;


//---------串的链式顺序储存结构------------
#define CHUNKSIZE 80                //定义块的大小，可自由定义

typedef struct Chunk{
    char ch [CHUNKSIZE];
    struct Chunk *next;
}Chunk;

typedef struct {
    Chunk *head,*tail;              //串的头尾指针
    int length;                     //串的当前长度
}LString;

/*********串的模式匹配算法***************/

//-------------BF(Brute-Force)算法：
int Index_BF(SString S,SString T,int pos){
    //返回模式T在主串中第pos个字符开始第一次出现的位置。若不存在，则返回0
    //其中，T非空，pos >= 1 && pos <= S.length;
    
    int i,j;
    i = pos;
    j=1;
    while (i<=S.length && j<= T.length){        //两个串均未到达串尾
        if(S.ch[i] == T.ch[j]){++i,++j;}        //继续比较后面的字符
        else {i = i-j+2; j=1;}                  //指针后退重新开始匹配
    }
    if (j>T.length) return i-T.length;          //匹配成功
    else return 0;                              //匹配失败
    
}