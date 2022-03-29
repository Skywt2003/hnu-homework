#pragma once

#include<cstdio>
#include<cstring>
#include<iostream>
#include "link0.h"
#include "link.h"

int n=0;

link link1,link2;

signed main(){
    char ch=getchar();
    while (ch!=10 && ch!=13 && ch!=-1){
        link1.appendNode(ch);
        link2.pushFrontNode(ch);
        n++;
        ch=getchar();
    }

    link1.moveToHead();
    link2.moveToHead();
    for (int i=1;i<=n/2;i++){
        link1.moveToNext();
        link2.moveToNext();
        if (link1.getCurrent() != link2.getCurrent()){
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}
