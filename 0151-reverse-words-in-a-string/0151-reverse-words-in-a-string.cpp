class Solution {
public:
    string reverseWords(string s) {
        istringstream stream(s);
        string w = "";
        stack<string> st;
        while(stream >> w){
            st.push(w);
        }
        string ans = "";
        ans += st.top();
        st.pop();
        while(!st.empty()){
            ans += " ";
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};