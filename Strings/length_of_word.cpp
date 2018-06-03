#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {
	int i = A.size() - 1;

	while(i >= 0 && !isalpha(A[i])) {
		--i;
	}

	if(i < 0) {
		return 0;
	}

	int ans = 0;
	while(i >= 0 && isalpha(A[i])) {
		++ans;
		--i;
	}

	return ans;
}

int main(void) {

}