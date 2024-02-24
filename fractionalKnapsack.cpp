#include<bits/stdc++.h>
using namespace std;

int main() {
	int bagSize = 10;
	int n = 4;
	int values[n] = {60, 70, 80, 8};
	int weights[n] = {100, 200, 500, 1};

	vector<pair<double, int>>items(n);
	for (int i = 0; i < n; ++i)
	{
		items[i] = {(values[i] * 1.0) / weights[i], weights[i]};
	}
	sort(items.rbegin(), items.rend());

	// for (auto it : items)cout << it.first << " ";
	// cout << endl;

	double profit = 0;
	for (int i = 0; i < n; ++i)
	{
		if (bagSize >= items[i].second)profit += items[i].first * items[i].second, bagSize -= items[i].second;
		else profit += bagSize * items[i].first, bagSize = 0;
	}
	cout << "profit = " << profit << endl;
	cout << "space left = " << bagSize << endl;
	return 0;
}
