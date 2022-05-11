#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 100
#define INF 9999999
using namespace std;
typedef char VertexType;//��������
typedef int ArcType;    //�ߵ�Ȩֵ����
typedef struct {
	VertexType vexs[MAX];  //�����
	ArcType arcs[MAX][MAX];//�ڽӾ���
	int vexnum, arcnum;    //�������ͱ���
} AMGraph;
typedef struct {
	VertexType head;
	VertexType tail;
	ArcType weight;
} Edge;
int Vexset[MAX];                                                //�������飬��������С������
int locate(AMGraph G, VertexType u);                            //���Ҷ���u��G.vexs�е�λ��
void CreateUDN(AMGraph& G, vector<VertexType>& v, Edge edges[]);//��������ͼG��vΪ���㼯�ϣ�edgesΪ�߼���
void printGraph(AMGraph G, vector<VertexType> v);               //��ӡͼG
void BFS(AMGraph G, int i);                                     //�����������
void DFS(AMGraph G, int i);                                     //�����������
void MST_Kruskal(AMGraph G, Edge edges[]);                      //Kruskal�㷨����С������
bool cmp(Edge a, Edge b);
int main() {
	AMGraph G;
	Edge edges[MAX];
	vector<VertexType> v;
	CreateUDN(G, v, edges);
	cout << "�ڽӾ���" << endl;
	printGraph(G, v);
	cout << "������������� " << endl;
	BFS(G, 0);
	cout << "������������� " << endl;
	DFS(G, 0);
	cout << "Kruskal�㷨" << endl;
	MST_Kruskal(G, edges);
	return 0;
}
int locate(AMGraph G, VertexType u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == u) {
			return i;
		}
	}
	return -1;
}

void CreateUDN(AMGraph& G, vector<VertexType>& v, Edge edges[]) {
	cout << "���붥�����ͱ�����";
	cin >> G.vexnum >> G.arcnum;
	cout << "���붥�㼯�ϣ�" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexs[i];
		v.push_back(G.vexs[i]);
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = INF;
		}
	}
	//����߼���
	for (int i = 0; i < G.arcnum; i++) {
		VertexType x, y;
		int weight;
		cout << "�������" << i + 1 << "���ߵ������յ㣺";
		cin >> x >> y >> weight;
		edges[i].head = x, edges[i].tail = y, edges[i].weight = weight;
		int m = locate(G, x), n = locate(G, y);//���Ҷ���x�Ͷ���y��G.vexs�е�λ��
		G.arcs[m][n] = weight;
		G.arcs[n][m] = weight;
	}
}

void printGraph(AMGraph G, vector<VertexType> v) {
	cout << "��������" << G.vexnum << endl;
	cout << "������" << G.arcnum << endl;
	cout << "���㼯�ϣ�" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << G.vexs[i] << " ";
	}
	cout << endl;
	cout << "�ڽӾ���" << endl
	     << "  ";
	for (int i = 0; i < G.vexnum; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << v[i] << " ";
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] == INF) {
				cout << "��  ";
			} else {
				cout << G.arcs[i][j] << " ";
			}
		}
		cout << endl;
	}
}
void BFS(AMGraph G, int i) {
	int visited[MAX];
	for (int j = 0; j < G.vexnum; j++) {
		visited[j] = 0;
	}
	visited[i] = 1;
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int j = q.front();
		q.pop();
		cout << G.vexs[j] << " ";
		for (int k = 0; k < G.vexnum; k++) {
			if (G.arcs[j][k] != INF && visited[k] == 0) {
				visited[k] = 1;
				q.push(k);
			}
		}
	}
	cout << endl;
}
void DFS(AMGraph G, int i) {
	int visited[MAX];//��¼���ʹ��Ķ���
	for (int j = 0; j < G.vexnum; j++) {
		visited[j] = 0;
	}
	visited[i] = 1;
	stack<int> s;
	s.push(i);
	while (!s.empty()) {
		int j = s.top();
		s.pop();
		cout << G.vexs[j] << " ";
		//����j����������ڽӶ���
		for (int k = 0; k < G.vexnum; k++) {
			if (G.arcs[j][k] != INF && visited[k] == 0) {
				visited[k] = 1;
				s.push(k);
			}
		}
	}
	cout << endl;
}
bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

void MST_Kruskal(AMGraph G, Edge edges[]) {
	VertexType edge[MAX];
	sort(edges, edges + G.arcnum, cmp);
	for (int i = 0; i < G.vexnum; i++) {
		Vexset[i] = i;
	}
	cout << "�����С�������ıߺͱߵ�Ȩֵ��" << endl;
	for (int i = 0; i < G.arcnum; i++) {
		int m = Vexset[locate(G, edges[i].head)], n = Vexset[locate(G, edges[i].tail)];
		if (m != n) {
			cout << edges[i].head << "-" << edges[i].tail << " " << edges[i].weight << endl;
			for (int j = 0; j < G.vexnum; j++) {
				if (Vexset[j] == m) {
					Vexset[j] = n;
				}
			}
		}
	}
	cout << endl;
}
