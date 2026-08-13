class Solution {
public:
    int findMax(vector<int>& nums)
    {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi, nums[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& nums, int hourly)
    {
        long long totalHours=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            totalHours+=ceil((double) nums[i]/(double) hourly);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long totalH=calculateTotalHours(piles,mid);
            if(totalH<=h)
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