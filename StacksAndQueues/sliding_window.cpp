#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
	deque<int> q;
	for(int i = 0; i < k; ++i) {
		while(!q.empty() && A[q.back()] <= A[i]) {
			q.pop_back();
		}
		q.push_back(i);
	}

	vector<int> res;
	for(int i = k; i < A.size(); ++i) {
		res.push_back(A[q.front()]);

		while(!q.empty() && A[i] >= A[q.back()]) {
			q.pop_back();
		}

		while(!q.empty() && q.front() <= i - k) {
			q.pop_front();
		}

		q.push_back(i);
	}

	return res;
}

int main(void) {

}