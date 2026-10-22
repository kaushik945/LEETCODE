
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" &&
               tokens[i] != "*" && tokens[i] != "/"){
                st.push(stoi(tokens[i]));
            }else{
                int first = st.top();
                st.pop();

                int second = st.top();
                st.pop();

                if(tokens[i] == "+"){
                    st.push(second + first);
                }
                if(tokens[i] == "-"){
                    st.push(second - first);
                }
                if(tokens[i] == "*"){
                    st.push(second * first);
                }
                if(tokens[i] == "/"){
                    st.push(second / first);
                }
            }
        }

        return st.top();
    }
};
