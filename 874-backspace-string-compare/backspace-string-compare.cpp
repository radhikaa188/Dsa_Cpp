class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        while (i >= 0 || j >= 0) {

            int skip = 0;

            while (i >= 0) {
                if (s[i] == '#') {
                    skip++;
                    i--;
                } else if (skip > 0) {
                    skip--;
                    i--;
                } else {
                    break; // valid char
                }
            }
            int skipj = 0;

            while (j >= 0) {
                if (t[j] == '#') {
                    skipj++;
                    j--;
                } else if (skipj > 0) {
                    skipj--;
                    j--;
                } else {
                    break; // valid char
                }
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            } else {
                if (i >= 0 || j >= 0)
                    return false;
            }

            i--;
            j--;
        }
        return true;
    }
};