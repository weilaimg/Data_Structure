//
//  main.cpp
//  括号匹配检测
//
//  Created by WeiLai’s Macbook Pro on 8/17/16.
//  Copyright © 2016 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
using namespace std;

struct zhan{
    char data;
    struct zhan * next;
};

int InitStacks(struct zhan * &S){
    S=NULL;
    return 1;
}

int Push (struct zhan * &S , char e){
    struct zhan *p;
    p = new struct zhan;
    p -> data = e;
    p -> next = S;
    S = p;
    return 1;
}

int Pop (struct zhan * &S , char &e){
    if(S == NULL) return 0;
    struct zhan *p ;
    p = S;
    e = p->data;
    S = p->next;
    delete p;
    
    return 1;
}

char GetTop(struct zhan *&S){
    if (S == NULL) return 0;
    return S -> data;
}

int StrackEmpty(struct zhan *S){
    if (S == NULL) return 1;
    return 0;
}

int Matching (){
//检测表达式中所含的括号是否正确匹配
    char ch,x;
    struct zhan * S;
    InitStacks(S);                  //初始化空栈
    int flag  = 1;
    cin >> ch;
    while (ch != '#' && flag){
        switch (ch){
            case '{':
            case '(':
            case '[':Push(S,ch);break;
            case ')':if(!StrackEmpty(S)&&GetTop(S)=='(')Pop(S,x);else flag = 0;break;
            case ']':if(!StrackEmpty(S)&&GetTop(S)=='[')Pop(S,x);else flag = 0;break;
            case '}':if(!StrackEmpty(S)&&GetTop(S)=='{')Pop(S,x);else flag = 0;break;
                
        }
        cin >> ch;
    }
    if(StrackEmpty(S)&&flag){
        return 1;
    }
    return 0;
}

int main(){
    
    int status = Matching();
    if(status) cout << "匹配成功"<<endl;
    else cout << "匹配失败"<<endl;
}