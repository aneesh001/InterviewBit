#include <bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
	vector<pair<int, int>> bookings;
	for(int i = 0; i < arrive.size(); ++i) {
		bookings.push_back({arrive[i], 1});
		bookings.push_back({depart[i], -1});
	}

	sort(bookings.begin(), bookings.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		if(a.first != b.first) return a.first < b.first;
		else return a.second > b.second;
	});

	int present = 0;
	for(int i = 0; i < bookings.size(); ++i) {
		present += bookings[i].second;

		if(present > K) {
			return false;
		}
	}

	return true;
}

int main(void) {
	vector<int> a {40, 18};
	vector<int> b {40, 43};
	int K = 1;

	cout << 
}