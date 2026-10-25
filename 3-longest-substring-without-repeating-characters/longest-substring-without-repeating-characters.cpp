
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxLen = 0;
        int hash[256];
        fill(hash, hash + 256, -1);

        while (r < s.size()) {
            unsigned char c = s[r];

            if (hash[c] >= l) {
                l = hash[c] + 1;
            }

            maxLen = max(maxLen, r - l + 1);
            hash[c] = r;
            r++;
        }

        return maxLen;
    }
};
