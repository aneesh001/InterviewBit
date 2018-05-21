#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class solution {
	vector<Interval> merge(vector<Interval> &A);
};

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end(), [](const Interval &a, const Interval &b) {
    	return a.first < b.first;
    });

    vector<Interval> ret;

    int start = A[0].start;
    int end = A[0].end;

    for(int i = 1; i < A.size(); ++i) {
    	if(A[i].start <= end) {
    		start = min(start, A[i].start);
    		end = max(end, A[i].end);
    	}
    	else {
    		ret.push_back(Interval(start, end));
    		start = A[i].start;
    		end = A[i].end;
    	}
    }
    ret.push_back(Interval(start, end));

    return ret;
}
