class Solution {
public:
    int residuePrefixes(string s) {
        int residue=0;
        int dis=0;
        vector<int>v(26,0);
        for(int i=0; i<s.size(); i++){
            if(v[s[i]-'a']==0){
                v[s[i]-'a']++;
                dis++;
            }
            if((i+1)%3 == dis) residue++;
        }
        return residue;
    }
};