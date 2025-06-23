class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(n,1);//intially every child will have one candy
        for(int i=1;i<n;i++){////checking left neighbour
            if(ratings[i]>ratings[i-1]){
                candies[i]=(candies[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){//right neighbour dekh rhe hai
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};