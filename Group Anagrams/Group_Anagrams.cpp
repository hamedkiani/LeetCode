class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int ln = strs.size();
        vector< vector<string> > res;
         if (ln == 0)
             return res;
        unordered_map<string, vector<string>> str_map;
        for(int i = 0; i < ln; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            str_map[temp].push_back(strs[i]);
        }
        for ( auto sm = str_map.begin(); sm!=str_map.end(); sm++){
            res.push_back(sm->second );
        }
        return res;
    }
};
