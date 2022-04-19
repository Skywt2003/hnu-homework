#pragma once

// template<typename E>
class BinNode {
	private:
		BinNode *lc, *rc;
		char elem;

	public:
		BinNode(char, BinNode*, BinNode*);

		BinNode* getLeft();
		BinNode* getRight();
		char getValue();

		void setLeft(BinNode*);
		void setRight(BinNode*);
		void setValue(char);

		bool isLeaf();
};
