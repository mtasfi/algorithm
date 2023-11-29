//author mtasfi
#include<iostream>
#include<map>
#include<queue>
using namespace std;

map<char, string>codes;

struct node {
	char c;
	int cost;
	node *left, *right;
	bool operator<(const node& other) const {
		return !(cost < other.cost);
	}
};

node root;

void dfs(node* x, string path) {
	if (x->left == NULL and x->right == NULL) {
		codes[x->c] = path;
		return;
	}
	dfs(x->left, path + "0");
	dfs(x->right, path + "1");
}

string encode(string s) {
	string coded = "";
	for (auto it : s)coded += codes[it];
	return coded;
}

string decode(string coded) {
	int n = coded.length();
	string s = "";
	node* tmp = &root;
	for (int i = 0; i < n; ++i)
	{
		if (tmp->left == NULL) {
			s.push_back(tmp->c);
			tmp = &root;
		}
		if (coded[i] == '1')tmp = tmp->right;
		else tmp = tmp->left;
	}
	return s;
}

int main() {
	string s = "aassfffffffffiiii";

	map<char, int>m;
	for (auto it : s)m[it]++;

	priority_queue<node> pq;
	for (auto it : m) {
		node tmp;
		tmp.c = it.first;
		tmp.cost = it.second;
		tmp.left = NULL;
		tmp.right = NULL;
		pq.push(tmp);
	}

	while (pq.size() > 1) {
		node* node1 = new node(pq.top());
		pq.pop();
		node* node2 = new node(pq.top());
		pq.pop();

		node* newNode = new node;
		newNode->cost = node1->cost + node2->cost;
		newNode->left = node1;
		newNode->right = node2;
		pq.push(*newNode);
	}

	root = pq.top();

	dfs(&root, "");
	cout << encode(s) << endl;
	cout << decode(encode(s)) << endl;

	return 0;
}
