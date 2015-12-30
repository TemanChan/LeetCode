/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

// use stringstream to get next word
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> mymap;
        set<char> myset;
        stringstream ss(str);
        string s;
        for(char c : pattern){
            if(!(ss >> s)){ // not enough words
                return false;
            }
            if(mymap.insert(pair<string, char>(s, c)).second){
                if(myset.insert(c).second == false){
                    return false;
                }
            }else if(mymap[s] != c){
                return false;
            }
        }
        return !(ss >> s); // too much words?
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mymap;
        set<string> myset;
        int curr = 0;
        for(int i=0; i<pattern.size(); ++i){
            string w = getNextWord(str, curr);
            if(w.empty()) // not enough words
                return false;
            if(mymap.insert(pair<char, string>(pattern[i], w)).second){
                if(myset.insert(w).second == false)
                    return false;
            }else{
                if(mymap[pattern[i]] != w){
                    return false;
                }
            }
        }
        return curr >= str.size(); // if curr < str.size(), too much words
    }

    string getNextWord(const string &str, int &curr){
        if(curr >= str.size())
            return "";
        int len = 0;
        for(; curr < str.size() && str[curr] != ' '; ++len, ++curr);
        return str.substr(curr++ - len, len);
    }
};
