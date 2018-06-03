#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &A) {
    string ans;

    int i = 0;
    while(i < A.size() && !isalpha(A[i])) {
    	++i;
    }

    if(i >= A.size()) {
    	return;
    }

    int j = A.size() - 1;
    while(j >= i && !isalpha(A[j])) {
		--j;
    }

    while(j >= i) {
    	int space = 0;
    	while(j >= i && !isalpha(A[j])) {
    		++space;
    		--j;
    	}

    	if(space > 0) {
    		ans += ' ';
    	}

    	string word;
    	while(j >= i && isalpha(A[j])) {
    		word += A[j];
    		--j;
    	}

    	for(int k = word.size() - 1; k >= 0; --k) {
    		ans += word[k];
    	}
    }

    A = ans;
}

int main(void) {
	return 0;
}