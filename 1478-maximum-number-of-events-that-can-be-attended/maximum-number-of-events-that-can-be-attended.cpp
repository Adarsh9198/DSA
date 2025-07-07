class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());//start day based
        priority_queue<int,vector<int>,greater<int>>pq;//least end time on top
        int day=events[0][0];//first event start day
        int i=0;
        int n=events.size();
        int count=0;
        while(!pq.empty() || i<n){
            if(pq.empty()){
                day=events[i][0];// suppose first event starts at 5 and other at ten 
            }

            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);//end day push kr diya
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                count++;//one event completed
            }
            day++;
            while(!pq.empty() && pq.top()<day){
                pq.pop();//agar end day...day se kam hai toh woh event hoga hi nhi 
            }
        }
        return count;
    }
};