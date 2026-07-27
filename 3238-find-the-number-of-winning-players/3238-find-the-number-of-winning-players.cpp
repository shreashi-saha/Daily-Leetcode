class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> cnt(n, vector<int>(11,0));
        unordered_set<int> winners;
        for(auto &p : pick)
        {
            int player = p[0];
            int color = p[1];
            cnt[player][color]++;
            if(cnt[player][color]>player)
            {
                winners.insert(player);
            }
        }
        return winners.size();
        
    }
};