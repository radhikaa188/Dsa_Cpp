class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.size()-1;
        while(left<right){
            //while s[left] is not alphanumeric then left ptr++
            while(left<right && !isalnum(s[left])) left++;
            // while s[right] is not alphanumeric then right ptr++
            while(left<right && !isalnum(s[right])) right--;
            // if not equal return false
            if(tolower(s[left])!= tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};