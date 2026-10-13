class Solution {
public:
    int fun(vector<int>& nums,  long long mid) {
        int count=1;
        long long arrSize=0;
        for(int i=0;i<nums.size();i++){
            if(arrSize+nums[i]<=mid){
                arrSize+=nums[i];
            }
            else{
                count++;
                arrSize=nums[i];
            }
        }
        return count;
    }




    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int low=maxi;
        int high=sum;
        while(low<=high){
            long long mid=(low+high)/2;
            if(fun(nums,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};