//
//  main.cpp
//  next数组的求法
//
//  Created by WeiLai’s Macbook Pro on 8/26/16.
//  Copyright © 2016 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

void get_next (char T[] , int *next);

void get_text (const char T[] , int text[]){
    int i=0 , j=1;
    text[0] = -1;
    text[1] = 0;
    while(j<strlen(T)){
        if(i==-1 || T[i] == T[j])
//            text[j++] = ++i;
//            text[++j] = ++i;
        {
            i++;j++;
            if(T[i] != T[j]) text[j] = i;
            else text [j] = text[i];
        }
        else
            i = text[i];
    }
}

void test(){
    char a[100] = "abcabcac";
//    cout << "a = ";
//    cin >> a;
    int test[strlen(a)+1];
    get_text(a, test);
    cout << "b = ";
    for (int i = 0;i < strlen(a);i++){
        cout << test[i];
    }
    cout << '\n';
}


int main(){
    test();
}