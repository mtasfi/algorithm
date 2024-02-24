#include<iostream>
using namespace std;
#define v 7
#define INF 1000000

int a[v][v] = {
	{INF, 3, INF, INF, INF, 12, INF},
	{3, INF, 5, INF, INF, INF, 4},
	{INF, 5, INF, 6, INF, INF, 3},
	{INF, INF, 6, INF, 1, INF, INF},
	{INF, INF, INF, 1, INF, 10, 7},
	{12, INF, INF, INF, 10, INF, 2},
	{INF, 4, 3, INF, 7, 2, INF}
};

int main() {
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	cout << "All pair Shortest path:" << endl;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (a[i][j] == INF)cout << "INF ";
			else
				cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
