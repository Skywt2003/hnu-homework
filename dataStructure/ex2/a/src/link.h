#pragma once

#include<cstdio>
#include<cstring>
#include<iostream>
#include "link0.h"

// Node 部分

node::node(char c, node *nxt){
    ch = c;
    next = nxt;
}

char node::getChar(){
    return ch;
}

// Link 部分

link::link(){
    tail = new node(' ', NULL);
    head = new node(' ', tail);
    cur = head;
}

void link::appendNode(char c){
    node *now = head;
    while (now->next != tail) now = now->next;
    now->next = new node(c, tail);
}

void link::pushFrontNode(char c){
    head->next = new node(c, head->next);
}

void link::moveToHead(){
    cur = head;
}

void link::moveToTail(){
    cur = tail;
}

void link::moveToNext(){
    cur = cur->next;
}

char link::getCurrent(){
    return cur->getChar();
}