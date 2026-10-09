class Solution {
public:
    int divisor(vector<int>nums,int mid){
        int divide=0;
        for(int i=0;i<nums.size();i++){
            divide=divide+ceil((double)nums[i]/mid);
        }
        return divide;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(divisor(nums,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};