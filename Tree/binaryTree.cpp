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
	cout << "�ݹ��������: ";
	preorderTraversal(T);
	cout << endl;
	cout << "�ݹ��������: ";
	inorderTraversal(T);
	cout << endl;
	cout << "�ݹ�������: ";
	postorderTraversal(T);
	cout << endl;
	cout << "�ǵݹ��������: ";
	inorderTraversal2(T);
	cout << endl;
	cout << "Ҷ�ӽڵ���Ŀ: " << leafNodeNum(T) << endl;
	cout << "�������: " << depth(T);
	cout << endl;
	return 0;
}
//���������˳��ݹ鴴��
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
//�ݹ��������
void preorderTraversal(BinTree T) {
	if (T) {
		cout << T->data << " ";
		preorderTraversal(T->lchild);
		preorderTraversal(T->rchild);
	}
}
//�ݹ��������
void inorderTraversal(BinTree T) {
	if (T) {
		inorderTraversal(T->lchild);
		cout << T->data << " ";
		inorderTraversal(T->rchild);
	}
}
//�ݹ�������
void postorderTraversal(BinTree T) {
	if (T) {
		postorderTraversal(T->lchild);
		postorderTraversal(T->rchild);
		cout << T->data << " ";
	}
}
// �ǵݹ��������
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
	return;
}
//�ݹ���Ҷ�ӽڵ���Ŀ
int leafNodeNum(BinTree T) {
	if (T == NULL) return 0;
	if (T->lchild == NULL && T->rchild == NULL) return 1;
	return leafNodeNum(T->lchild) + leafNodeNum(T->rchild);
}
//�ݹ����������
int depth(BinTree T) {
	if (T == NULL) return 0;
	return max(depth(T->lchild), depth(T->rchild)) + 1;
}
