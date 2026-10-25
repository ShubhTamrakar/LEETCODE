#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        string str = "";
        int maxLen=0;
        for(int i = 0; i < l; i++)
        {
            char c = s.at(i);
            if(str.find(c)==-1)
            {
                str = str + c;
            }
            else{
                maxLen = max(maxLen, (int)str.length());
                str = str.substr((str.find(c)+1),(int)str.length());
                str = str+c;
            }
            maxLen = max(maxLen, (int)str.length());
        }
        return maxLen;
    }
};