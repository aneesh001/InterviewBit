#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &A) {
	stack<int> st;
    
    int sol = 0;
    
    int i = 0, n = A.size();
    
    while(i < n){
        if(st.empty() || A[st.top()] <= A[i]){
            st.push(i);
            i++;
        }
        else{
            int top = st.top();
            st.pop();
            
            int area = 0;
            
            if(st.empty()){
                area = A[top] * i;
            }
            else{
                area = A[top] * (i - st.top() - 1);
            }
            
            sol = max(sol, area);
        }
    }
    
    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        int area = 0;
        
        if(st.empty()){
            area = A[top] * i;
        }
        else{
            area = A[top] * (i - st.top() - 1);
        }
        
        sol = max(sol, area);
    }
    
    return sol;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> hist(n);
	for(int i = 0; i < n; ++i) {
		cin >> hist[i];
	}

	cout << largestRectangleArea(hist) << endl;

	return 0;
}