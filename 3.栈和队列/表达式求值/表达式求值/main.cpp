//
//  main.cpp
//  表达式求值
//
//  Created by WeiLai’s Macbook Pro on 8/19/16.
//  Copyright © 2016 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

struct zhan {
    char data;
    struct zhan * next;
};

int InitStack(struct zhan *&S){
    S = NULL;
    return 1;
}

int Push (struct zhan * &S,char e){
    struct zhan *p;
    p = new struct zhan;
    p -> data = e;
    p -> next = S;
    S = p;
    return 1;
}

char GetTop(struct zhan *&S){
    if (S != NULL)
    return S -> data;
    return 0;
}

int Pop (struct zhan *&S,char &e){
    if(S == NULL) return 0;
    struct zhan *p;
    p = S;
    e = p->data;
    S = p-> next;
    delete p;
    return 1;
}


struct zhan1 {
    int data;
    struct zhan1 * next;
};

int InitStack1(struct zhan1 *&S){
    S = NULL;
    return 1;
}

int Push1 (struct zhan1 * &S,int e){
    struct zhan1 *p;
    p = new struct zhan1;
    p -> data = e;
    p -> next = S;
    S = p;
    return 1;
}

char GetTop1(struct zhan1 *&S){
    if (S != NULL)
        return S -> data;
    return 0;
}

int Pop1 (struct zhan1 *&S,int &e){
    if(S == NULL) return 0;
    struct zhan1 *p;
    p = S;
    e = p->data;
    S = p-> next;
    delete p;
    return 1;
}



int In (char ch){
    int flag = 0;
    char a[]= {'+','-','*','/','(',')','#'};
    for (int i = 0; i < strlen(a);i++){
        if (ch == a[i]){
            flag = 1 ;
            break;
        }
    }
    return flag;
}

char Precede(char x,char y){
    char a[]= {'+','-','*','/','(',')','#'};
    char b[7][7]={
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=',' '},
        {'>','>','>','>',' ','>','>'},
        {'<','<','<','<','<',' ','='},
    };
    int i ,j;
    for (i = 0 ; i < strlen(a);i++){
        if(a[i]==x)break;
    }
    for (j = 0 ; j < strlen(a);j++){
        if(a[j]==y)break;
    }
    return b[i][j];
}

int Operate(int a, char theta , int b){
    int sum = 0;
    switch(theta){
        case '+':sum = a+b;break;
        case '-':sum = a-b;break;
        case '*':sum = a*b;break;
        case '/':sum = a/b;break;
    }
    return sum;
}

int EvaluateExpression(){
    //算术表达式求值的算符优先算法，设OPTR和OPND分别为运算符和操作数栈
    struct zhan *OPTR;
    struct zhan1 *OPND;
    char ch,theta,x;
    int t=0,sum=0,a,b;
    InitStack1(OPND);                    //初始化操作数栈
    InitStack(OPTR);                    //初始化运算符栈
    Push (OPTR , '#');                  //表达式起始符'#'压入栈
    cin >> ch;
    
    while (ch != '#'||GetTop(OPTR)!= '#'){              //表达式没有结束或栈顶不为'#'
        if(!In(ch)){                                    //如果ch不是运算符则压入操作数栈
            t = sum  = 0 ;
            while(!In(ch)){
                sum  = sum*10;
                t = ch - '0';
                sum +=t;
                cin >> ch;
            }                                           //将字符型转换为整形数
            Push1(OPND, sum);
        }
        else{
            switch(Precede(GetTop(OPTR),ch)){           //比较OPTR的栈顶元素与ch的优先级
                case '<':
                    Push(OPTR,ch);cin >> ch ;break;     //当前字符压入栈
                case '>':
                    Pop(OPTR,theta);                    //弹出栈顶运算符
                    Pop1(OPND,b);Pop1(OPND,a);          //弹出操作数
                    Push1(OPND,Operate(a, theta, b));   //将运算结果压入栈
                    break;
                case '=':                               //栈顶元素中‘（’且ch是‘）’
                    Pop(OPTR,x);cin >> ch;break;        //弹出‘（’
            }
        }
    }
    return GetTop1(OPND);
}

int main(){
    cout << EvaluateExpression();
}
