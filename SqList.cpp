#include <iostream>
#define MAXSIZE 100
#define ERROR -1
#define OK 1
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct
{
	ElemType* elem;
	int length;
} SqList;
//初始化顺序表
Status InitList(SqList& L);
//顺序表长度
int ListLength(SqList L);
//顺序表插入
Status ListInsert(SqList& L, int i, ElemType e);
//顺序表取值
int GetElem(SqList L, int i, ElemType& e);
//顺序表删除
Status ListDelete(SqList& L, int i, ElemType& e);
//顺序表查找
int LocateElem(SqList L, ElemType e);
int main() {
	SqList L;
	if (!InitList(L)) {
		cout << "链表初始化失败 " << endl;
		exit(0);
	};
	for (int i = 0; i < 10; i++) {
		L.elem[i] = i + 1;
		L.length++;
	}
	for (int i = 0; i < L.length; i++) {
		ElemType e;
		GetElem(L, i, e);
		cout << e << " ";
	}
	cout << endl;
	cout << "该顺序表的长度为:" << ListLength(L) << endl;

	ElemType e;
	ListDelete(L, 3, e);
	cout << "删除第三个元素，删除的元素为：" << e << endl;
	cout << "删除之后的顺序表：" << endl;
	for (int i = 0; i < L.length; i++) {
		ElemType e;
		GetElem(L, i, e);
		cout << e << " ";
	}
	cout << endl;
	//查找值为6的元素所在位置
	if (LocateElem(L, 6)) {
		cout << "6所在的位置为：" << LocateElem(L, 6) << endl;
	} else {
		cout << "未查找到元素6" << endl;
	}
	//查找第7个元素
	GetElem(L, 7, e);
	cout << "第七个元素为：" << e << endl;
	ListInsert(L, 1, 100);
	for (int i = 0; i < L.length; i++) {
		ElemType e;
		GetElem(L, i, e);
		cout << e << " ";
	}
	return 0;
}
Status InitList(SqList& L) {
	//L.elem = new ElemType[MAXSIZE];
	L.elem = (int*) malloc(sizeof(int) * 100);
	if (!L.elem) return ERROR;
	L.length = 0;
	return OK;
}

int ListLength(SqList L) {
	return L.length;
}

Status ListInsert(SqList& L, int i, ElemType e) {
	if (i < 1 || i > L.length - 1) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

Status ListDelete(SqList& L, int i, ElemType& e) {
	if ((i < 1) || (i > L.length)) return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j <= L.length - 1; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i + 1;
	}
	return -1;
}
int GetElem(SqList L, int i, ElemType& e) {
	if (i < 0 || i > L.length) return ERROR;
	e = L.elem[i];
	return OK;
}
