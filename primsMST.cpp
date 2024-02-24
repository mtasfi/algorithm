#include<iostream>
#include<vector>
#include<set>
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

int main() {
	set<int>treeNodes;
	set<vector<int>>edges;

	treeNodes.insert(0);
	for (int j = 0; j < v; j++) {
		if (a[0][j])edges.insert({a[0][j], 0, j});
	}
	while (edges.size()) {
		auto it = edges.begin();
		int x = (*it)[2];
		if (treeNodes.find(x) == treeNodes.end()) {
			treeNodes.insert(x);

			cout << "-> " << (*it)[0] << " " << (*it)[1] + 1 << " " << (*it)[2] + 1;
			cout << endl;

			for (int j = 0 ; j < v; j++) {
				if (a[x][j])edges.insert({a[x][j], x, j});
			}
		}
		edges.erase(it);
	}

	return 0;
}
