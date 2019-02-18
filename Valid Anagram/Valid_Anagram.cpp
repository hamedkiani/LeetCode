class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() == 0 && t.size() ==0)
            return true;
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> count;
        for(int i = 0; i < s.length(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto c = count.begin(); c!=count.end(); c++)
            if (c->second != 0)
                return false;
        return true;
    }
};
