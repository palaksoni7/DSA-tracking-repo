class Solution {
public:
    int flowerbloom(vector<int>& bloomDay, int mid, int k) {
        int cnt=0;
        int noOfFlower=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
                if(cnt==k){
                    noOfFlower++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return noOfFlower;

    }
 


    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(flowerbloom(bloomDay,mid,k)>=m){
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
        }
        return low;;
    }
};