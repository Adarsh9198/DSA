class Solution {
public:
    int removeString(string &s,char first, char second, int score){
        stack<char>st;
        int total=0;
        for(char &c:s){
            if(!st.empty() && st.top()==first && c==second){
                st.pop();
                total+=score;
            }
            else{
                st.push(c);
            }
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        s=temp;//for second pass of minimum score
        return total;
    }
    int maximumGain(string s, int x, int y) {
        int maxPoint=0;
        if(x>y){
            maxPoint+=removeString(s,'a','b',x);
            maxPoint+=removeString(s,'b','a',y);
        }
        else{
            maxPoint+=removeString(s,'b','a',y);
            maxPoint+=removeString(s,'a','b',x);
        }
        return maxPoint;
    }
};