class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int i=0;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int k = s.size();
        for(auto &t : s)
        {
            nums[i]=t;
            i++;
        }
        return k;
    }
};