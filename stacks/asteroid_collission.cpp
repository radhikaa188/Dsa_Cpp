class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i = 0;

        while (i < asteroids.size()) {
            if (asteroids[i] < 0) {
                while (!st.empty() && st.top() > 0 && st.top() < -asteroids[i]) {
                    st.pop();
                }

                if (!st.empty() && st.top() > 0 && st.top() == -asteroids[i]) {
                    st.pop();
                    i++;     
                }
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                    i++;  
                }
                else {
                      i++;
                }
            } else {
                st.push(asteroids[i]);
                i++;
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
