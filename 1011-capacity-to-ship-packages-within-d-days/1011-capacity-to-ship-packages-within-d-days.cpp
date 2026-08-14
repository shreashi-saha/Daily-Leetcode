class Solution {
public:
    int canShip(vector<int>& weights, int days, int load)
    {
        int n=weights.size();
        int currload=0;
        int requiredDays=1;
        for(int i=0;i<n;i++)
        {
            if(currload+weights[i]>load)
            {
                requiredDays++;
                currload=0;
            }
            currload+=weights[i];
        }
        return requiredDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(), weights.end());
        int high= accumulate(weights.begin(), weights.end(), 0);
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canShip(weights, days, mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};