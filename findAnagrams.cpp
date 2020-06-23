#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/find-all-anagrams-in-a-string/
vector<int> findAnagrams(string s, string p) {
	unordered_map<char, size_t> charCount;
	for (char c : p)
		charCount[c]++;

	vector<int> ret;
	unordered_map<char, size_t> charOccur;
	size_t l = 0, r = 0, total = 0;
	while (l <= r && r < s.size()) {
		char c = s[r];

		// is in pattern
		if (p.find(c) != string::npos) {
			charOccur[c]++;
			++total;

			if (charOccur[c] == charCount[c]) {
				if (total == p.size()) {
					ret.push_back(l);

					// push l one symbol
					charOccur[s[l]]--;
					++l; --total;
				}
			}
			else if (charOccur[c] > charCount[c]) {
				// push l until we encounter c
				do {
					charOccur[s[l]]--;
					--total;
				} while (s[l++] != c && l < r);
			}
			++r;
		}
		else { // not in pattern
			l = r = r + 1;
			total = 0;
			charOccur.clear();
		}
	}

	return ret;
}

int main() {
	auto s = "cbaebabacd"s, p = "abc"s;
	printf("%s %s\n", s.c_str(), p.c_str());

	auto idx = findAnagrams(s, p);
	for (int i : idx)
		printf("%d ", i);

	return 0;
}