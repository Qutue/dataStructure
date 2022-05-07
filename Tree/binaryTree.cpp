#include <iostream>
#include <stack>
using namespace std;
typedef char TElementType;
typedef struct BinNode {
	TElementType data;
	struct BinNode *lchild, *rchild;
} BinNode, *BinTree;
void creatBinTree(BinTree& T);
void preorderTraversal(BinTree T);
void inorderTraversal(BinTree T);
void postorderTraversal(BinTree T);
void inorderTraversal2(BinTree T);
int leafNodeNum(BinTree T);
int depth(BinTree T);
int main() {
	BinTree T = new BinNode;
	creatBinTree(T);
	cout << "递归先序遍历: ";
	preorderTraversal(T);
	cout << endl;
	cout << "递归中序遍历: ";
	inorderTraversal(T);
	cout << endl;
	cout << "递归后序遍历: ";
	postorderTraversal(T);
	cout << endl;
	cout << "非递归先序遍历: ";
	inorderTraversal2(T);
	cout << "叶子节点数目: " << leafNodeNum(T) << endl;
	cout << "树的深度: " << depth(T);
	cout << endl;
	return 0;
}
//按照先序遍顺序递归创建
void creatBinTree(BinTree& T) {
	TElementType ch;
	cin >> ch;
	if (ch == '#') T = NULL;
	else {
		T = new BinNode;
		T->data = ch;
		creatBinTree(T->lchild);
		creatBinTree(T->rchild);
	}
}
//递归先序遍历
void preorderTraversal(BinTree T) {
	if (T) {
		cout << T->data << " ";
		preorderTraversal(T->lchild);
		preorderTraversal(T->rchild);
	}
}
//递归中序遍历
void inorderTraversal(BinTree T) {
	if (T) {
		inorderTraversal(T->lchild);
		cout << T->data << " ";
		inorderTraversal(T->rchild);
	}
}
//递归后序遍历
void postorderTraversal(BinTree T) {
	if (T) {
		postorderTraversal(T->lchild);
		postorderTraversal(T->rchild);
		cout << T->data << " ";
	}
}
// 非递归中序遍历
void inorderTraversal2(BinTree T) {
	stack<BinNode*> S;
	BinNode* p = T;
	BinNode* q = new BinNode;
	while (p || !S.empty()) {
		if (p) {
			S.push(p);
			p = p->lchild;
		} else {
			q = S.top();
			S.pop();
			cout << q->data << " ";
			p = q->rchild;
		}
	}
}
//递归求叶子节点数目
int leafNodeNum(BinTree T) {
	if (T == NULL) return 0;
	if (T->lchild == NULL && T->rchild == NULL) return 1;
	return leafNodeNum(T->lchild) + leafNodeNum(T->rchild);
}
//递归求树的深度
int depth(BinTree T) {
	if (T == NULL) return 0;
	return max(depth(T->lchild), depth(T->rchild)) + 1;
}
