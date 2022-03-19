#include <iostream>
#define MAXSIZE 100
#define OVERFLOW -1
#define OK 1
#define ERROR -1
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct QNode {
	ElemType data;
	struct QNode* next;
} QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;
Status InitQueue(LinkQueue& Q);
Status EnQueue(LinkQueue& Q, ElemType e);
Status DeQueue(LinkQueue& Q, ElemType& e);
ElemType getHead(LinkQueue Q);
void QueueDisp(LinkQueue Q);
int main() {
	LinkQueue Q;
	InitQueue(Q);
	QueueDisp(Q);
	for (int i = 1; i <= 6; i++) {
		EnQueue(Q, i);
	}
	QueueDisp(Q);
	ElemType e;
	DeQueue(Q, e);
	cout << e << "出队" << endl;
	QueueDisp(Q);
	cout << "队首元素为" << getHead(Q) << endl;
	return 0;
}
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = nullptr;
	return OK;
}
Status EnQueue(LinkQueue& Q, ElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = nullptr;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue& Q, ElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	QNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	delete p;
	return OK;
}
ElemType getHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
	else
		return ERROR;
}
void QueueDisp(LinkQueue Q) {
	cout << "-----------------------" << endl;
	if (Q.front == Q.rear) {
		cout << "空栈" << endl;
		return;
	}

	do {
		Q.front = Q.front->next;
		cout << Q.front->data << "  ";
	} while (Q.front->next != nullptr);
	cout << endl
	     << "-----------------------" << endl;
}
