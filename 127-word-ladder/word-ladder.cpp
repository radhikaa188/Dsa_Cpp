class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()){
            int steps = q.front().second;
            string word = q.front().first;
            q.pop();
            if(word == endWord) return steps;
            for(int i=0; i<word.size(); i++){
                char org = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                //so that it gets back to original
                word[i] = org;
            }
        }
        return 0;
    }
};