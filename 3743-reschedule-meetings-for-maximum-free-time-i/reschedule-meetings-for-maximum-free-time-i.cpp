class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeTime;
        //k shift krne pr (K+1) free time merge honge 
        freeTime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);

        int i=0;
        int j=0;
        int maxFree=0;
        int currSum=0;
        int n=freeTime.size();
        while(j<n){
             currSum+=freeTime[j];
            if(i<n && (j-i+1)>k+1){
                currSum-=freeTime[i];
                i++;
            }
            maxFree=max(maxFree,currSum);
            j++;
        }
        return maxFree;
    }
};