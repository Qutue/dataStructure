#include <iostream>
#define OK 1
#define ERROR -1
using namespace std;
typedef int Elemtype;
typedef int Status;

typedef struct Node {
	Elemtype data;
	struct Node* next;
} Node, *Linklist;

Status InitList(Linklist& L);
//创建链表
Status CreatList(Linklist& L, int n);
//获取第i个元素
Status GetElem(Linklist L, int i, Elemtype& e);
void PrintList(Linklist L);
//删除第i个节点
Status ListDelete(Linklist& L, int i, Elemtype& e);
//在第i个节点之前插入新节点
Status ListInsert(Linklist& L, int i, Elemtype e);
//获取链表长度
int ListLength(Linklist L);
int main() {
	Linklist L;
	int n;
	cout << "请输入数据个数：" << endl;
	cin >> n;
	Elemtype e;
	InitList(L);
	CreatList(L, n);
	PrintList(L);
	ListInsert(L, 4, 100);
	PrintList(L);
	int del;
	cout << "输入要删除的节点序号" << endl;
	cin >> del;
	if (ListDelete(L, del, e)) {
		cout << "被删除的数据为:" << e << endl;
		PrintList(L);
	}
	return 0;
}
void PrintList(Linklist L) {
	cout << "-----------------------" << endl;
	cout << "链表长度为" << ListLength(L) << endl;
	for (int i = 1; i <= ListLength(L); i++) {
		Elemtype e;
		if (GetElem(L, i, e))
			cout << "第" << i << "个为：" << e << endl;
	}
	/* Node* p = L->next;
	while (p) {
		cout << p->data << endl;
		p = p->next;
	} */

	cout << "-----------------------" << endl;
}
Status InitList(Linklist& L) {
	L = new Node;
	L->next = NULL;
	return OK;
}

Status GetElem(Linklist L, int i, Elemtype& e) {
	int length = ListLength(L);

	if (i > length || i <= 0) return ERROR;
	Linklist p;
	p = L;
	while (i--) {
		p = p->next;
	}
	e = p->data;
	return OK;
}

Status CreatList(Linklist& L, int n) {
	Linklist r = L;
	cout << "输入数据，空格分开" << endl;
	for (int i = 0; i < n; i++) {
		Linklist p = new Node;
		cin >> p->data;
		r->next = p;
		p->next = NULL;
		r = p;
	}
	return OK;
}
int ListLength(Linklist L) {
	int length = 0;
	Node* p = L->next;
	while (p != nullptr) {
		p = p->next;
		length++;
	}
	return length;
}
Status ListInsert(Linklist& L, int i, Elemtype e) {
	cout << "在第" << i << "个元素之前插入数据:" << e << endl;
	Node *p = L->next, *pt, *q = new Node;
	if (i == 1) {
		q->next = L->next;
		L->next = q;
	} else {
		while (--i) {
			pt = p;
			p = p->next;
		}
		q->next = p;
		pt->next = q;
	}
	q->data = e;
	return OK;
}

Status ListDelete(Linklist& L, int i, Elemtype& e) {
	cout << "删除第" << i << "个节点" << endl;
	if (i <= 0 || i > ListLength(L)) return ERROR;
	Node *p = L, *pt;
	while (i--) {
		pt = p;
		p = p->next;
	}
	e = p->data;
	pt->next = p->next;
	delete p;
	return OK;
}
