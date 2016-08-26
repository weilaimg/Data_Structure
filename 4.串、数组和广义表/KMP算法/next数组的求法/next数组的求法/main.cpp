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
    int i , j;
    i = 0;j =1;
    text[0] = 0;
    while(j<strlen(T)){
        
        if(T[i] == T[j]){
            
            i++;
            text[j] = i;
            j++;
            
        } else {
            
            i=0;
            if(T[i]!=T[j]){
                text[j] = 0;
                j++;
            }
        
        }
    }
}

void test(){
    char a[100];
    cout << "a = ";
    cin >> a;
    int test[strlen(a)];
    get_text(a, test);
    cout << "b = ";
    for (int i = 0;i < strlen(a);i++){
        cout << test[i];
    }
    cout << '\n';
}

int main()
{
    while (1) test();
}