class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        vector<int>setBit(32,-1);//32 bit representation of each num
        //setBit[j]=i means that jth bit can be set by element at index i
        
        for(int i=n-1;i>=0;i--){
            //nums[i] =binary rep
            int endidx=i;
            for(int j=0;j<32;j++){
                if(!(nums[i] & (1<<j))){//if bit not set
                    if(setBit[j]!=-1){
                        endidx=max(endidx,setBit[j]);
                    }
                }
                else{
                    setBit[j]=i;
                }
            }
            res[i]=endidx-i+1;//
        }
        return res;
    }
};