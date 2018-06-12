#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
    if (n>12)   
        return INT_MAX;
    int f = 1;
    for (auto i = 2; i<=n; ++i)
        f *= i;
    return f;
}

string util(int k, vector<int>& nums) {
    int n = nums.size();
	
    if (n==0 || k > fact(n)) {
        return "";
	}
	
    int f = fact(n-1);
    int pos = k / f;
    k %= f;
    
	string ch = to_string(nums[pos]);
    numlist.erase(nums.begin() + pos);
    return ch + util(k, nums);
}

string Solution::getPermutation(int n, int k) {
    vector<int> nums;
    for (int i = 1; i < n + 1; ++i) {
        nums.push_back(i);
	}
    return util(k-1, numlist);
}

int main(void) {
	return 0;
}