class Solution {
public:
    //T.C=O(2K); S.C=O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        //left_sum+right_sum=sum
        int left_sum=0;
        int right_sum=0;
        int max_sum=0;
        for(int i=0;i<k;i++){//O(k)
            left_sum+=cardPoints[i];
        }
        max_sum=left_sum;
        int rightIdx=n-1;
        for(int i=k-1;i>=0;i--){//O(k)
            left_sum-=cardPoints[i];
            right_sum+=cardPoints[rightIdx];
            rightIdx=rightIdx-1;
            max_sum=max(max_sum,left_sum+right_sum);
        }
        return max_sum;
    }
};