class Solution {
public:
    int cap(vector<int>& weights, int mid){
        int day=0;
        int eachDayCap=0;

        for(int i=0;i<weights.size();i++){
            if((eachDayCap+weights[i])<=mid){
                eachDayCap+=weights[i];
            }
            else{
                day++;
                eachDayCap=weights[i];
            }
        }
        return day;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        long long sum=0;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];

        }
        int low=maxi;
        int high=sum;
        while(low<=high){
            long long mid=(low+high)/2;
            if(cap(weights,mid)<days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};