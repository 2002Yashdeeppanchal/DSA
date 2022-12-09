class Solution {
public:
    int wordLadderLength(string startword, string targetword, vector<string>& wordlist) {
        
        queue<pair<string,int>>q;
        q.push({startword,1});
        
        set<string>st;
        for(auto i : wordlist){
            st.insert(i);
        }
        
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==targetword){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        
        return 0;
        
        
    }
};
