#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string convert_low(string str) {
        for (int i = 0; i < str.size(); ++i) {
            if(str[i]>='A' && str[i]<='Z')
                str[i] = str[i] - 'A' + 'a';
        }

        //transform(str.begin(), str.end(), str.begin(), tolower);
        return str;
    }
    bool isVowel(char ch) {
        
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string convert_vow(string str) {

        for (int i = 0; i < str.size(); ++i) {
            if(isVowel(str[i]))
                str[i] = '*';
        }
        return str;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        set<string> words_perfect;
        unordered_map<string, string> words_cap;
        unordered_map<string, string> words_vow;

        vector<string> res;

        for (auto word : wordlist) {
            words_perfect.insert(word);

            string word_low = convert_low(word);
            if(words_cap[word_low].empty())
                words_cap[word_low] = word;

            string word_vow = convert_vow(word_low);
            if(words_vow[word_vow].empty())
                words_vow[word_vow] = word;
        }

        for (auto query : queries) {
            if (words_perfect.find(query) != words_perfect.end()) {
                res.emplace_back(query);
                continue;
            }
            string word_low = convert_low(query);

            if (!words_cap[word_low].empty()) {
                res.emplace_back(words_cap[word_low]);
                continue;
            }

            string word_vow = convert_vow(word_low);
            
            if (!words_vow[word_vow].empty()) {
                res.emplace_back(words_vow[word_vow]);
                continue;
            }
            res.emplace_back("");
        }

        return res;
    }
};
//vector<string> wordlist = { "KiTe","kite","hare","Hare" };
//vector<string> queries = { "kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto" };
int main() {
    vector<string> wordlist = { "ae", "aa" };
    vector<string> queries = { "UU" };

    Solution solution;

    vector<string> res = solution.spellchecker(wordlist, queries);
    
    for(auto str : res)
        cout<<str<<endl;
    
    return 0;

}