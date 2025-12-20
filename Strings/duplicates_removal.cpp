/*
Problem: Remove Duplicates from String
Description: Given a string, remove all duplicate characters so that every character appears only once.
The order of characters should be preserved.
Example:
    Input: "programming"
    Output: "progamin"
*/

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