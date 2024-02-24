#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define v 9
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
	int visited[v], dist[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i] = 0;
		dist[i] = INT_MAX;
	}
	dist[0] = 0;
	for (int i = 0; i < v; ++i)
	{
		int mn = INT_MAX, idx = 0;
		for (int j = 0; j < v; j++) {
			if (!visited[j] and dist[j] < mn) {
				mn = dist[j];
				idx = j;
			}
		}
		visited[idx] = 1;
		for (int j = 0; j < v; j++) {
			if (a[idx][j])dist[j] = min(dist[j], dist[idx] + a[idx][j]);
		}
	}
	for (int i = 0; i < v; ++i)cout << dist[i] << " ";
	return 0;
}
