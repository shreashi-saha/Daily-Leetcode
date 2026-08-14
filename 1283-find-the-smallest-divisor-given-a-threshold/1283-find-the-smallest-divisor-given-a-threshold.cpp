class Solution {
public:
    int sum(vector<int>& nums, int d)
    {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=ceil((double) nums[i]/(double) d);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold)
        {
            return -1;
        }
        int low=1, high= *max_element(nums.begin(), nums.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(sum(nums,mid)<=threshold)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};