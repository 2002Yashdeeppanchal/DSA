class Solution {
public:
    vector<vector<string>> findSequences(string beginword, string endword, vector<string>& wordlist) {
        
        queue<vector<string>>q;
        q.push({beginword});
        
        set<string>st;
        for(auto i : wordlist){
            st.insert(i);
        }
        
        vector<vector<string>>ans;
        
        //ye vo strings hai jo ki new add hui hai copy me dekh level 0 me bat hai
        //then bat->pat and bat->bot so new string are pat and bot inko iss level
        //ke complete hone pr delete krna hai
        vector<string>usedstring;
        
        while(!q.empty()){
        
            int sz=q.size();
            //do level wise
            for(int i=0;i<sz;i++){
                vector<string>level=q.front();
                string word=level.back();//issi string ko modify krke new string add hongi
                if(word==endword){
                    ans.push_back(level);
                    q.pop();
                    continue;
                }
                for(int j=0;j<word.size();j++){
                    char original=word[j];
                    for(char ch='a';ch<='z';ch++){
                        word[j]=ch;
                        if(st.find(word)!=st.end()){
                            level.push_back(word);
                            q.push(level);
                            level.pop_back();
                            usedstring.push_back(word);
                        }
                    }
                    word[j]=original;
                }
                q.pop();
            }
            
            for(auto i : usedstring){
                st.erase(i);
            }
            
            usedstring.clear();
            
        }
        
        return ans;
    }
};
