#include<iostream>
#include<vector>
#include<algorithm>
#define v 7
using namespace std;

int a[v][v] = {
	{0, 3, 0, 0, 0, 12, 0},
	{3, 0, 5, 0, 0, 0, 4},
	{0, 5, 0, 6, 0, 0, 3},
	{0, 0, 6, 0, 1, 0, 0},
	{0, 0, 0, 1, 0, 10, 7},
	{12, 0, 0, 0, 10, 0, 2},
	{0, 4, 3, 0, 7, 2, 0}
};
int parent[v], sz[v];

int findSet(int u) {
	if (parent[u] == u)return u;
	return findSet(parent[u]);
}
void unionSet(int u, int u2) {
	int a = findSet(u);
	int b = findSet(u2);
	if (sz[a] > sz[b]) {
		parent[b] = a;
		sz[a] += sz[b];
	} else {
		parent[a] = b;
		sz[b] += sz[a];
	}
}

int main() {
	for (int i = 0; i < v; ++i)
	{
		parent[i] = i;
		sz[i] = 1;
	}
	vector<vector<int>>edges, mst;
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; j++) {
			if (a[i][j])edges.push_back({a[i][j], i, j});
		}
	}
	sort(edges.begin(), edges.end());
	for (auto it : edges) {
		int a = findSet(it[1]);
		int b = findSet(it[2]);
		if (a != b) {
			mst.push_back(it);
			unionSet(a, b);
		}
	}
	cout << "MST:" << endl;
	cout << "weight i      j" << endl;
	cout << "------ -      -" << endl;
	for (auto it : mst) {
		for (auto itr : it) {
			cout << itr << "      ";
		}
		cout << endl;
	}

	return 0;
}
