class Solution {
public:
    int minOperations(vector<string>& logs){
        int res = 0;
        
        for (auto& i : logs){
            if (i == "./") continue;
            if (i == "../") res = max(0, res - 1);
            else ++res;
        }
        return res;
    }
};