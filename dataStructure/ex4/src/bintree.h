#pragma once

#include "bintree_def.h"

// template<typename E>

BinNode::BinNode(char tmp, BinNode* ls, BinNode* rs){
	elem=tmp, lc=ls, rc=rs;
}

BinNode* BinNode::getLeft(){return lc;}
BinNode* BinNode::getRight(){return rc;}
char BinNode::getValue(){return elem;};

void BinNode::setLeft(BinNode* tmp){lc=tmp;}
void BinNode::setRight(BinNode* tmp){rc=tmp;}
void BinNode::setValue(char tmp){elem=tmp;}

// bool BinNode::isLeaf(){return (lc==NULL && rc==NULL);}
