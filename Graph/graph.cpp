#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 100
#define INF 9999999
using namespace std;
typedef char VertexType;//顶点类型
typedef int ArcType;    //边的权值类型
typedef struct {
	VertexType vexs[MAX];  //顶点表
	ArcType arcs[MAX][MAX];//邻接矩阵
	int vexnum, arcnum;    //顶点数和边数
} AMGraph;
typedef struct {
	VertexType head;
	VertexType tail;
	ArcType weight;
} Edge;
int Vexset[MAX];                                                //辅助数组，用于求最小生成树
int locate(AMGraph G, VertexType u);                            //查找顶点u在G.vexs中的位置
void CreateUDN(AMGraph& G, vector<VertexType>& v, Edge edges[]);//创建无向图G，v为顶点集合，edges为边集合
void printGraph(AMGraph G, vector<VertexType> v);               //打印图G
void BFS(AMGraph G, int i);                                     //广度优先搜索
void DFS(AMGraph G, int i);                                     //深度优先搜索
void MST_Kruskal(AMGraph G, Edge edges[]);                      //Kruskal算法求最小生成树
bool cmp(Edge a, Edge b);
int main() {
	AMGraph G;
	Edge edges[MAX];
	vector<VertexType> v;
	CreateUDN(G, v, edges);
	cout << "邻接矩阵" << endl;
	printGraph(G, v);
	cout << "广度优先搜索： " << endl;
	BFS(G, 0);
	cout << "深度优先搜索： " << endl;
	DFS(G, 0);
	cout << "Kruskal算法" << endl;
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
	cout << "输入顶点数和边数：";
	cin >> G.vexnum >> G.arcnum;
	cout << "输入顶点集合：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexs[i];
		v.push_back(G.vexs[i]);
	}
	//初始化邻接矩阵
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = INF;
		}
	}
	//输入边集合
	for (int i = 0; i < G.arcnum; i++) {
		VertexType x, y;
		int weight;
		cout << "请输入第" << i + 1 << "条边的起点和终点：";
		cin >> x >> y >> weight;
		edges[i].head = x, edges[i].tail = y, edges[i].weight = weight;
		int m = locate(G, x), n = locate(G, y);//查找顶点x和顶点y在G.vexs中的位置
		G.arcs[m][n] = weight;
		G.arcs[n][m] = weight;
	}
}

void printGraph(AMGraph G, vector<VertexType> v) {
	cout << "顶点数：" << G.vexnum << endl;
	cout << "边数：" << G.arcnum << endl;
	cout << "顶点集合：" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << G.vexs[i] << " ";
	}
	cout << endl;
	cout << "邻接矩阵：" << endl
	     << "  ";
	for (int i = 0; i < G.vexnum; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cout << v[i] << " ";
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] == INF) {
				cout << "∞  ";
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
	int visited[MAX];//记录访问过的顶点
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
		//查找j顶点的所有邻接顶点
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
	cout << "输出最小生成树的边和边的权值：" << endl;
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
