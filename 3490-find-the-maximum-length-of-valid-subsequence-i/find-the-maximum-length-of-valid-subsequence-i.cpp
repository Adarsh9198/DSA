class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        //agar sub mei sab even/odd honge toh %2=0
        //agar alternating odd/even honge toh%2=1
        int e_count=0;//count of even nos
        int o_count=0;//count of odd nos
        int al_count;
        for(int &num:nums){
            if(num%2==0){
                e_count++;
            }
            else{
                o_count++;
            }
        }
        int parity=nums[0]%2;
        al_count=1;
        for(int i=1;i<n;i++){
            int curr_parity=nums[i]%2;
            if(curr_parity!=parity){
                al_count++;
                parity=curr_parity;
            }
        }
        return max({e_count,o_count,al_count});
    }
};