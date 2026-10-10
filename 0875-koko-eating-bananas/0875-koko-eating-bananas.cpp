class Solution {
public:
    long long noOfHour(vector<int>&piles,int mid){
        long long divide=0;
        for(int i=0;i<piles.size();i++){
            divide+=ceil((double)piles[i]/mid);
        }
        return divide;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=(high+low)/2;
            if(noOfHour(piles,mid)<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};