#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A) {
	int ones = 0;
	int twos = 0;
	int common;

	for(int i = 0; i < A.size(); ++i) {
		twos |= (ones & A[i]);
		ones ^= A[i];
		common = ~(ones & twos);
		ones &= common;
		twos &= common;
	}

	return ones;
}

int main(void) {

}