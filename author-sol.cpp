#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int m = s.size();
		// count the no. of ones and zeroes in the sequence
		vector<int> counter(2);
		for (int i = 0; i < m; i++) {
			counter[s[i] - '0']++;
		}
		// calculate the total segments that can be made
		int segments = n / k;
		// if the no. of ones and zeroes (separately) cannot be divided 
		// equally into segments, then the answer does not exist
		if (counter[0] % segments != 0 && counter[1] % segments != 0) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		// otherwise, calculate the no. of ones and zeroes per segment
		int zeroes = counter[0] / segments;
		int ones = counter[1] / segments;
		// form the lexicographically smallest string by putting 0s in front of 1s
		string first_batch = "";
		for (int i = 0; i < zeroes; i++) {
			first_batch += "0";
		}
		for (int i = 0; i < ones; i++) {
			first_batch += "1";
		}
		// form mirror images by reversing the string every iteration
		string ans = first_batch;
		for (int i = 0; i < segments - 1; i++) {
			reverse(first_batch.begin(), first_batch.end());
			ans += first_batch;
		}
		cout << ans << '\n';
	}
	return 0;
}
