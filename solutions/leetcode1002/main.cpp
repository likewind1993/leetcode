#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

//class Solution {
//public:
//    vector<string> commonChars(vector<string>& A)
//    {
//        vector<string> res;
//        map<int, int> counts;
//        int n = A.size();
//        for(int i = 0; i<A[0].size(); ++i)
//            counts[A[0][i] - 'a'] ++;
//        for (int i = 1; i < n; ++i) {
//            map<int, int> cur_str;
//            for (auto ch : A[i]) {
//                cur_str[ch -'a'] ++;
//            }
//            vector<int> dels;
//            for (auto iter : counts) {
//                auto index = cur_str.find(iter.first);
//                if (index != cur_str.end()) { 
//                    if(index->second < counts[index->first])
//                        counts[index->first] = index->second;
//                }
//                else {
//                    dels.push_back(iter.first);
//                }
//            }
//            for(auto iter : dels)
//                counts.erase(iter);
//        }
//        
//        for (auto iter : counts) {
//            int n = iter.second;
//            for (int i = 0; i < n; ++i) {
//                char ch = iter.first + 'a';
//                stringstream stream;
//                stream << ch;
//                res.push_back(stream.str());
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<string> commonChars(vector<string> A) {
        int counts [26], num [26];
        for(int & i : counts)
            i = 300;

        for (const auto& str : A) {
            for(int & i : num)
                i = 0;
            for (char ch : str) {
                num[ch - 'a']++;
            }

            for (int i = 0; i < 26; ++i) 
                counts[i] = min(counts[i], num[i]);
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                char ch = i + 'a';
                string s = "";
                s += ch;
                for(int j = 0; j<counts[i]; ++j)
                    res.push_back(s);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> a = { "cool","lock","cook" };

    auto res = solution.commonChars(a);

    for(auto iter : res)
        cout<< iter<<endl;
    return 0;
}