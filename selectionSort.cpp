#include<iostream>
using namespace std;

int main() {
	int n = 6;
	int a[n] = {10, 1, 1, 15, 2, 34};

	for (int i = 0; i < n; ++i)
	{
		int mn = i;
		for (int j = i; j < n; j++) {
			if (a[mn] > a[j])mn = j;
		}
		swap(a[i], a[mn]);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
