//
//  main.cpp
//  KMP算法
//
//  Created by WeiLai’s Macbook Pro on 8/25/16.
//  Copyright © 2016 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#include <string.h>

#define MaxLength 255
using namespace std;
typedef char SString[MaxLength+1];


int StrAssign(SString A,char *chars){
    if(strlen(chars)>MaxLength)
        return 0;
    else {
        A[0] = strlen(chars);
        for (int i = 1 ; i<=A[0] ; i++ ){
            A[i] = *(chars+i-1);
        }
        return 1;
    }
}


int Index_KMP(SString S ,SString T,int pos , int next[]){
    //利用模式串T的next函数求T在主串中第pos个字符之后的位置
    //其中，T非空，pos >=1 && pos <= S.length
    
    int i,j;
    i = pos ;
    j = 1;
    while(i <= S[0] && j << T[0]){
        if(j == 0 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }
    if(j > T[0]) return i-T[0];
    else return 0;
}