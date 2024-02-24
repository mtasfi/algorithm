// sample input
/*	7 9
	A B
	B D
	D C
	C A
	B C
	E F
	F G
	G E
	B E
*/

#include<bits/stdc++.h>
#define char2int(x) x-'A'
#define int2char(x) char(x+'A')
using namespace std;

int mytime = 0;

string dfs(vector<vector<int>>&edges, int n, int idx, int visited[], vector<pair<int, int>>&timing) {
	if (visited[idx])return "";
	string s; s.push_back(int2char(idx));
	visited[idx] = 1;
	timing[idx].first = ++mytime;
	for (auto it : edges[idx])s += dfs(edges, n, it, visited, timing);
	timing[idx].second = ++mytime;
	return s;
}

vector<int>getTopological(vector<pair<int, int>>timing) {
	vector<pair<int, int>>v;
	for (int i = 0; i < timing.size(); ++i)
	{
		v.push_back({timing[i].second, i});
	}
	sort(v.rbegin(), v.rend());
	vector<int>ans;
	for (auto it : v)ans.push_back(it.second);
	return ans;
}

int main() {
	int n, e; cin >> n >> e;
	vector<vector<int>>edges(n);
	for (int i = 0; i < e; ++i)
	{
		char a, b;
		cin >> a >> b;
		edges[char2int(a)].push_back(char2int(b));
	}
	int visited[n];
	vector<pair<int, int>>timing(n);

	for (int i = 0; i < n; ++i)visited[i] = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])dfs(edges, n, i, visited, timing);
	}

	vector<int>topologicalSort = getTopological(timing);

	for (auto it : topologicalSort)cout << int2char(it) << " ";

}
