#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

// https://leetcode.com/problems/find-all-anagrams-in-a-string/
vector<int> findAnagrams(string s, string p) {
	vector<int> ret;
	if (p.size() == 1) {
		for (size_t i = 0, n = s.size(); i < n; ++i)
			if (s[i] == p.front())
				ret.push_back(i);

		return ret;
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