class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=k;
        int count=0;
        int result=INT_MIN;
        for(int l=i; l<j; l++){
            if(s[l]=='a' || s[l]=='u' || s[l]=='o' || s[l]=='i' || s[l]=='e'){
                count++;
            }
        }
        result= max(result, count);
        while(j<s.size()){
            if(s[j]=='a' || s[j]=='u' || s[j]=='o' || s[j]=='i' || s[j]=='e'){
                count++;
                
            }
            if(s[i]=='a' || s[i]=='u' || s[i]=='o' || s[i]=='i' || s[i]=='e'){
                count--;
                
            }
            j++;
            i++;
            result= max(result, count);
        }
        return result;
    }
};