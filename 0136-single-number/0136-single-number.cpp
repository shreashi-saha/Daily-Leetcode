class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto &t : mp)
        {
            if(t.second==1)
            {
                return t.first;
            }
        }
        return -1;
    }
};