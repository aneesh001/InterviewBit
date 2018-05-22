#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int A) {
	vector<int> row {1};

	for(int i = 1; i <= A; ++i) {
		vector<int> new_row;

		for(int j = 0; j <= i; ++j) {
			if(j == 0 || j == i) {
				new_row.push_back(1);
			}
			else {
				new_row.push_back(row[j] + row[j - 1]);
			}
		}

		row = new_row;
	}

	return row;
}

int main(void) {
	int k;
	cin >> k;

	for(int i: getRow(k)) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}