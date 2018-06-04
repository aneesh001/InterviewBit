#include <bits/stdc++.h>
using namespace std;

int strStr(const string A, const string B) {
	for(int i = 0; i < A.size(); ++i) {
		int a = i;
		int b = 0;

		while(b < B.size() && a < A.size()) {
			if(A[a] != B[b]) {
				break;
			}

			a++;
			b++;
		}

		if(b == B.size()) {
			return i;
		}
	}

	return -1;
}

int main(void) {

}