#include <bits/stdc++.h>
using namespace std;

string intToRoman(int A) {
	map<int, string> m;
	m.insert({1000, "M"});
	m.insert({900, "CM"});
	m.insert({500, "D"});
	m.insert({400, "CD"});
	m.insert({100, "C"});
	m.insert({90, "XC"});
	m.insert({50, "L"});
	m.insert({40, "XL"});
	m.insert({10, "X"});
	m.insert({9, "IX"});
	m.insert({5, "V"});
	m.insert({4, "IV"});
	m.insert({1, "I"});

	string ans;

	while(A) {
		if(A >= 1000) {
			int times = A / 1000;

			for(int i = 0; i < times; ++i) {
				ans += m[1000];
			}

			A = A % 1000;
		}
		else if(A >= 900) {
			ans += m[900];
			A -= 900;
		}
		else if(A >= 500) {
			ans += m[500];
			A -= 500;
		}
		else if(A >= 400) {
			ans += m[400];
			A -= 400;
		}
		else if(A >= 100) {
			for(int i = 0; i < A / 100; ++i) {
				ans += m[100];
			}

			A = A % 100;
		}
		else if(A >= 90) {
			ans += m[90];
			A -= 90;
		}
		else if(A >= 50) {
			ans += m[50];
			A -= 50;
		}
		else if(A >= 40) {
			ans += m[40];
			A -= 40;
		}
		else if(A >= 10) {
			for(int i = 0; i < A / 10; ++i) {
				ans += m[10];
			}

			A = A % 10;
		}
		else if(A >= 9) {
			ans += m[9];
			A -= 9;
		}
		else if(A >= 5) {
			ans += m[5];
			A -= 5;
		}
		else if(A >= 4) {
			ans += m[4];
			A -= 4;
		}
		else {
			for(int i = 0; i < A; ++i) {
				ans += m[1];
			}
			A = 0;
		}
	}

	return ans;
}

int main(void) {

}