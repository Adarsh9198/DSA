class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0;
        int right=arr.size()-1;
        while(right-left>=k){//K size ki window chahiye isliye
            if(abs(arr[left]-x)>arr[right]-x){
                left++;
            }
            else{
                right--;
            }
        }
        //arr.begin()+left=>start index, arr.begin()+left+k=> excluding last one
     return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};