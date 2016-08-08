//
//  main.cpp
//  汉诺塔
//
//  Created by WeiLai’s Macbook Pro on 16/6/29.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;

int m=0;
void move (char A,int n,char C)
{
    cout <<"第"<<++m<<"步,将第"<<n<<"个圆盘从"<<A<<"移动到"<<C<<endl;
}

void Hanoi (int n,char A,char B,char C)
{
    if(n==1) move (A,1,C);
    else
    {
        Hanoi(n-1, A, C, B);
        move (A,n,C);
        Hanoi(n-1, B, A, C);
    }
}

int main()
{
    char a='A',b='B',c='C';
    int n;
    cin >> n;
    Hanoi (n,a,b,c);
    return 0;
}

