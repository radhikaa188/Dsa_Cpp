// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        //using set for avoiding duplicates
        unordered_set<char> singleChar;
        string result = "";
        for(char c: s){
            // is c not present ir return .end()
            if(singleChar.find(c)==singleChar.end()){
                result.push_back(c);
                //insert the ele for future testing
                singleChar.insert(c);
            }
        }
        return result;
    }
};