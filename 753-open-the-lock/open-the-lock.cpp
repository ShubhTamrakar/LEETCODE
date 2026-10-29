class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        queue<string> q;
        vector<char> vet= {'0','1','2','3','4','5','6','7','8','9'};

        q.push("0000");
        st.insert("0000");
        for (string dead:deadends){
            if (dead=="0000") return -1;
            st.insert(dead);
        }

        int count = 0;
        while(count<100){
            int size = q.size();
            for (int i=0; i<size; i++){
                string tup = q.front();
                q.pop();
                if (tup == target) return count;
                for (int i=0; i< 4; i++){
                    int idx1 = (tup[i]-'0'+1);
                    idx1 %= 10;
                    int idx2 = (tup[i]-'0'-1);
                    idx2 = (idx2<0)?9:idx2;

                    string new_tup_1 = tup.substr(0,i)+ vet[idx1]   + tup.substr(i+1,4-i-1);
                    string new_tup_2 = tup.substr(0,i)+ vet[idx2]   + tup.substr(i+1,4-i-1);

                    if (!(st.find(new_tup_1) != st.end())){
                        q.push(new_tup_1);
                        st.insert(new_tup_1);
                    }
                    if (!(st.find(new_tup_2) != st.end())){
                        q.push(new_tup_2);
                        st.insert(new_tup_2);
                    }
                }
            }
            count++;
        }
        return -1;
        
    }
};