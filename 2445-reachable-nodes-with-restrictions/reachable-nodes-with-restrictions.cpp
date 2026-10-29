class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,unordered_set<int>> mp;
        for (vector<int> nums:edges){
            mp[nums[0]].insert(nums[1]);
            mp[nums[1]].insert(nums[0]);
        }
        vector<bool> res(n,true);
        res[0] = false;
        for (int num: restricted){
            res[num] = false;
        }

        queue<int> q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            int num = q.front();
            ans++;
            q.pop();
            for (int i: mp[num]){
                if (res[i]){
                    q.push(i);
                    res[i] = false;
                }
            }
        }
        return ans;
        
    }
};