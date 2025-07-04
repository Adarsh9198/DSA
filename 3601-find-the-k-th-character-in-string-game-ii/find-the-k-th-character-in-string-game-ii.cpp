class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';
        int n=operations.size();
        long long len=1;//inital character '1'
        long long index=-1;
        int op_type=-1;
        for(int i=0;i<n;i++){
            len=len*2;//after every operation length is doubled
            if(len>=k){
                op_type=operations[i];
                index=(k-len/2);//half len mei (k-l/2) el ans hoga 
                break;
            }
        }
        char ch=kthCharacter(index,operations);
        if(op_type==0){
            return ch;//same element return krna hoga
        }
        else{
            return (ch=='z')? 'a':ch+1;
        }
    }
};