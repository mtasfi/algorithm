#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define v 9
#define INF 1e5
using namespace std;

int a[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
};

int main() {
	int dist[v];
	for (int i = 0; i < v; ++i)
	{
		dist[i] = INF;
	}
	vector<vector<int>>edges;
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; j++) {
			if (a[i][j])edges.push_back({a[i][j], i, j});
		}
	}
	dist[0] = 0;
	for (int i = 0; i < v - 1; ++i)
	{
		for (auto it : edges) {
			int w = it[0];
			int a = it[1];
			int b = it[2];
			dist[b] = min(dist[b], dist[a] + w);
		}
	}
	for (int i = 0; i < v; ++i)cout << dist[i] << " ";
	return 0;
}
