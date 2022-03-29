#pragma once

#include<cstdio>
#include<cstring>
#include<iostream>

class node{
    private:
        char ch;

    public:
        node *next;

        node(char, node*);
        char getChar();
};

class link{
    private:
        node *head, *tail, *cur;

    public:
        link();
        void appendNode(char);
        void pushFrontNode(char);
        void moveToHead();
        void moveToTail();
        void moveToNext();
        char getCurrent();
};