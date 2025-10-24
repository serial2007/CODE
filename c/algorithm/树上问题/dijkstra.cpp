#include<bits/stdc++.h> 
using namespace std; 
#define size 1000 // 定义图的最大节点数
#define max 1000000000 // 定义最大值
int n, m, s, e; // 节点数, 有向线段数, 起点, 终点
int graph[size][size]; // 图的邻接矩阵
int dist[size]; // 起点到各点的最短距离
bool visited[size]; // 记录节点是否被访问过
 
void dijkstra(int s)
{
    // 初始化距离和访问状态
    for(int i=1; i<=n; i++)
	{	
		dist[i] = graph[s][i];
		visited[i] = false;
	}
    
    // 遍历所有节点: 看看是否从起始点先经过i，再由i到终点权值会小一点
	for(int i=1; i<=n; i++) 
	{
		int min = max, u = -1;
        //遍历&比较 => 找到未访问节点中距离起点最近的节点
		for(int j=1; j<=n; j++)
		{
			if(dist[j] < min && !visited[j])
			{
				u = j; min = dist[j];//可以用i=1的情况来理解，找到离原点最近的一个节点
			}
		}
		if(u == -1) return; // 若未找到可达节点，退出循环
		visited[u] = true; // 标记节点u为已访问
 
        // 更新起点到各节点的距离
		for(int v=1; v<=n; v++)
		{
			//从起始点先到u再到v的路径 < 原先记录的从原点到v的路径  &&    u,v之间有通路
			if(dist[v] > dist[u] + graph[u][v] && !visited[v] && graph[u][v] != max) 
			{										//v尚未访问过
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
}
 
 
int main()
{
	cout<<"依次输入节点数, 有向线段数, 起点, 终点(数字间以空分隔): ";
	cin>>n>>m>>s>>e; // 输入节点数, 有向线段数, 起点, 终点
	for(int i=1; i<=n; i++) // 初始化图的邻接矩阵
	{
		for(int j=0; j<=n; j++)
		{
			graph[i][j] = i==j ? 0: max;
		} 
	}
	int u, v, wt;
	for(int i=1; i<=m; i++) // 输入有向线段的起点、终点和权重
	{
		cin>>u>>v>>wt;
		graph[u][v] = wt;
		graph[v][u] = wt; // 无向图，对称设置权重
	}
	dijkstra(s); // 调用Dijkstra算法求最短路径
	cout<<"min_track_length: "<<dist[e]; // 输出起点到终点的最短距离
	return 0;
}