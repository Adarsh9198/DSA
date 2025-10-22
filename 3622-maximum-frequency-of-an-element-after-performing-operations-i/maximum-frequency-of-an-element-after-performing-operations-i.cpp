class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal=*max_element(nums.begin(),nums.end())+k;

        vector<int>diff(maxVal+2,0);
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;

            int l=max(nums[i]-k,0);
            int r=min(nums[i]+k,maxVal);
            //freq of elements in the range that can be made
            diff[l]++;
            diff[r+1]--;
        }
        int result=1;
        for(int target=0;target<=maxVal;target++){
            diff[target]+=(target>0 ? diff[target-1] : 0);//cum sum

            int targetFreq=freq[target];//pehle kitni baar present tha element
            int needConversion = diff[target]-targetFreq;

            int maxPossibleFreq= min(needConversion,numOperations);

            result=max(result,targetFreq+maxPossibleFreq);
        }
        return result;
    }
};