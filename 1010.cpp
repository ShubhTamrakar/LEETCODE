class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
   unordered_map<int,int> mp;
        long long c = 0;
        
        mp[time[0] % 60] = 1;
        
        for(int i = 1; i < time.size(); i++) {
            int rem = time[i] % 60;
            int complement = (60 - rem) % 60;
            
            c += mp[complement];
            
            mp[rem]++;
        }
        
        return c;      
    }
};
