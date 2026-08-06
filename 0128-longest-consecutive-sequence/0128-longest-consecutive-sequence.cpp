class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==0)
        {
            return 0;
        }

        int count = 0;
        int longest = 1;
        int lastSmaller = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==lastSmaller)
            {
                count+=1;
                lastSmaller=nums[i];
            }
            else if(nums[i]!=lastSmaller)
            {
                lastSmaller=nums[i];
                count = 1;
            }
            longest = max(longest,count);
        }
        return longest;
    }
};