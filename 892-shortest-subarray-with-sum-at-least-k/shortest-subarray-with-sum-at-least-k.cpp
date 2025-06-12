class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>cumlative_sum(n,0);
        deque<int>q;
        int minLen=INT_MAX;
        int j=0;
        while(j<n){
            if(j==0){
                cumlative_sum[j]=nums[j];
            }
            else{
                cumlative_sum[j]=cumlative_sum[j-1]+nums[j];
            }
            if(cumlative_sum[j]>=k){
                minLen=min(minLen,j+1);
            }
            //shrinking of window
            while(!q.empty() && cumlative_sum[j]-cumlative_sum[q.front()]>=k){
                minLen=min(minLen,j-q.front());
                q.pop_front();
            }
            while(!q.empty()&& cumlative_sum[j]<=cumlative_sum[q.back()]){
                q.pop_back();
            }
            q.push_back(j);
            j++;
        }
        if(minLen==INT_MAX) return -1;
        else return minLen;
    }
};