class WordDictionary {
public:
    vector<string> v;
    
    WordDictionary() {}

    void addWord(string word){
        v.push_back(word);
    }

    bool search(string word){
        for (string s : v){
            if (s.length() != word.length()) continue;
            int i = 0;

            while (i < s.length()){
                if (s[i] == word[i] || word[i] == '.') ++i;
                else break;
            }

            if (i == s.length()) return true;
        }
        return false;
    }
};