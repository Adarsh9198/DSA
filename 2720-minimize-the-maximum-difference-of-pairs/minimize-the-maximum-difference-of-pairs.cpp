class Solution {
public:
    bool isValue(vector<int>&nums,int p,int mid){
        int count_pairs=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=mid){
                count_pairs++;
                i+=2;//kyoki us index ko dobara nhi le skte
            }
            else{
                i+=1;
            }
        }
        return count_pairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;//minimum difference zero hoga
        int r=nums[n-1]-nums[0];//maximum difference itna hi ho skta hai,isse jyada difference pairs ke beech mei nahi dikh skta
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;//we have to find p pairs whose difference is <=mid
            if(isValue(nums,p,mid)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};