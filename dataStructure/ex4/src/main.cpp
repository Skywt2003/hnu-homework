#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include "bintree.h"

BinNode *root1=NULL, *root2=NULL;

bool isLetter(char ch){
	return (ch>='A'&&ch<='Z');
}

bool compareTwoTrees(BinNode* node1, BinNode* node2){
	if (node1->getValue() != node2->getValue()) return false;
	if (node1->getLeft()){
		if (!node2->getLeft() || !compareTwoTrees(node1->getLeft(),node2->getLeft())) return false;
	} else {
		if (node2->getLeft()) return false;
	}
	if (node1->getRight()){
		if (!node2->getRight() || !compareTwoTrees(node1->getRight(),node2->getRight())) return false;
	} else {
		if (node2->getRight()) return false;
	}
	return true;
}

bool checkTreeNodes(BinNode* now){
	// printf("Compare: %c %c\n",now->getValue(), root2->getValue());
	if (compareTwoTrees(now, root2)) return true;
	if (now->getLeft() && checkTreeNodes(now->getLeft())) return true;
	if (now->getRight() && checkTreeNodes(now->getRight())) return true;
	return false;
}

signed main(){
	std::stack<BinNode*> s;
	std::stack<bool> flg;
	while (!s.empty()) s.pop();
	while (!flg.empty()) flg.pop();

	char ch=getchar(); while (ch!='#' && !isLetter(ch)) ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1){
		if (root1==NULL){
			root1=new BinNode(ch,NULL,NULL);
			s.push(root1); flg.push(false);
			ch=getchar(); continue;
		}
		BinNode *now = (ch=='#')?NULL:new BinNode(ch, NULL, NULL);
		if (!flg.top()){
			s.top()->setLeft(now);
			flg.pop(); flg.push(true);
			if (now) s.push(now), flg.push(false);
		} else {
			s.top()->setRight(now);
			s.pop(); flg.pop();
			if (now) s.push(now), flg.push(false);
		}
		ch=getchar();
	}

	while (!s.empty()) s.pop();
	while (!flg.empty()) flg.pop();
	ch=getchar(); while (ch!='#' && !isLetter(ch)) ch=getchar();
	while (ch!=10 && ch!=13 && ch!=-1){
		if (root2==NULL){
			root2=new BinNode(ch,NULL,NULL);
			s.push(root2); flg.push(false);
			ch=getchar(); continue;
		}
		BinNode *now = (ch=='#')?NULL:new BinNode(ch, NULL, NULL);
		if (!flg.top()){
			s.top()->setLeft(now);
			flg.pop(); flg.push(true);
			if (now) s.push(now), flg.push(false);
		} else {
			s.top()->setRight(now);
			s.pop(); flg.pop();
			if (now) s.push(now), flg.push(false);
		}
		ch=getchar();
	}

	printf(checkTreeNodes(root1)?"yes\n":"no\n");
	return 0;
}