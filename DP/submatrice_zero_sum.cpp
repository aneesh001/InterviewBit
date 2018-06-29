#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> col_sum;
    vector<int> sum(m, 0);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            sum[j] += A[i][j];
        }
        col_sum.push_back(sum);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            vector<int> arr = col_sum[j];

            if(i - 1 >- 0) {
                for(int k = 0; k < m; ++k) {
                    arr[k] -= col_sum[i - 1][k];
                }
            }

            int local_ans = 0;
            int local_sum = 0;
            unordered_map<int, int> seen;
            for(int k = 0; k < m; ++k) {
                local_sum += arr[k];
                if(local_sum == 0) {
                    ++local_ans;
                }

                local_ans += seen[local_sum];
                seen[local_sum] += 1;
            }

            ans += local_ans;
        }
    }

    return ans;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << solve(grid) << endl;
    return 0;
}
