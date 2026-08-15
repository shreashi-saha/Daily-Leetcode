class Solution {
public:
    int countPartitions(vector<int>& nums, int maxSum)
    {
        int n = nums.size();
        int partitions=1;
        int subarraySum=0;

        for(int i=0;i<n;i++)
        {
            if(subarraySum+nums[i]>maxSum)
            {
                partitions++;
                subarraySum=0;
            }
            subarraySum+=nums[i];
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int partitions = countPartitions(nums, mid);
            if(partitions>k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};