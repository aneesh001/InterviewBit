#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &A, int B) {
	vector<string> ans;

	int taken = 0;
	while(taken < A.size()) {
		int i = taken;
		int sum = A[i].size();

		while(i + 1 < A.size() && sum + 1 + A[i + 1].size() <= B) {
			sum += 1 + A[i + 1].size();
			i++;
		}

		string line;
		if(i == A.size() - 1) {
			for(int j = taken; j <= i; ++j) {
				if(j != taken) {
					line += " ";
				}

				line += A[j];
			}

			line += string(B - line.size(), ' ');
		}
		else {
			int wc = 0;
			int wl = 0;
			for(int j = taken; j <= i; ++j) {
				wl += A[j].size();
				wc++;
			}

			if(wc == 1) {
				line += A[taken];
				line += string(B - line.size(), ' ');
			}
			else {
				int sl = (B - wl) / (wc - 1);
				int r = (B - wl) % (wc - 1);

				for(int j = taken; j <= i; ++j) {
					if(j != taken) {
						line += string(sl, ' ');

						if(r != 0) {
							line += " ";
							r--;
						}
					}

					line += A[j];
				}
			}
		}

		ans.push_back(line);
		taken = i + 1;
	}

	return ans;
}

int main(void) {
	int n;
	cin >> n;

	vector<string> words(n);
	for(int i = 0; i < n; ++i) {
		cin >> words[i];
	}

	int l;
	cin >> l;

	for(string s: fullJustify(words, l)) {
		cout << s << endl;
	}

	return 0;
}