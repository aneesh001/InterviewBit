#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &A) {
    int n = A.size();

    for(int x = 0; x < n / 2; ++x) {
    	for(int y = x; y < n - x - 1; ++y) {
    		int tmp = A[x][y];
    		A[x][y] = A[n - y - 1][x];
    		A[n - y - 1][x] = A[n - x - 1][n - y - 1];
    		A[n - x - 1][n - y - 1] = A[y][n - x - 1];
    		A[y][n - x - 1] = tmp;
    	}
    }
}

int main(void) {

}