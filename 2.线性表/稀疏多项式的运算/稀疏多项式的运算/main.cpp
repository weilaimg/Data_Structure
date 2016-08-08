//
//  main.cpp
//  稀疏多项式的运算
//
//  Created by WeiLai’s Macbook Pro on 16/4/23.
//  Copyright © 2016年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
typedef struct PNode
{
    float coef;
    int expn;
    struct PNode *next;
}PNode,*Polynomial;

void CreatPolyn(Polynomial &P,int n)
{
    PNode *s,*pre,*q;
    P=new PNode;
    P->next=NULL;
    for (int i=1;i<=n;i++)
    {
        s=new PNode;
        std::cin>>s->coef>>s->expn;
        pre=P;
        q=P->next;
        while (q&&q->expn<s->expn)
        {
            pre=q;
            q=q->next;
        }
        s->next=q;
        pre->next=s;
    }
}

void AddPolyn(Polynomial &Pa,Polynomial &Pb)
{
    Polynomial p1,r,p2,p3;
    p1=Pa->next;p2=Pb->next;
    p3=Pa;
    while (p1&&p2)
    {
        if(p1->expn==p2->expn)
        {
            int sum=p1->coef+p2->coef;
            if(sum!=0)
            {
                p1->coef=sum;
                p3->next=p1;p3=p1;
                p1=p1->next;
                r=p2;p2=p2->next;delete r;
            }
            else
            {
                r=p1;p1=p1->next;delete r;
                r=p2;p2=p2->next;delete r;
            }
        }
        else if(p1->expn<p2->expn)
        {
            p3->next=p1;
            p3=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p3=p2;
            p2=p2->next;
        }
    }
    p3->next=p1?p1:p2;
    delete Pb;
}