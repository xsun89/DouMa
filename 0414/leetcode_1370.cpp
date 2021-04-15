//
// Created by Xin Sun on 2021-04-14.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string sortString(string s) {
        vector<int> cnt(26);
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a'] += 1;
        }
        string ans;
        bool flag = true;
        while(flag == true){
            flag = false;
            for(int i = 0; i < 26; i++){
                if(cnt[i] > 0){
                    char c = static_cast<char>(i + 'a');
                    ans.push_back(c);
                    cnt[i]--;
                    if(cnt[i] > 0){
                        flag = true;
                    }
                }
            }
            flag = false;
            for(int i = 25; i >= 0; i--){
                if(cnt[i] > 0){
                    char c = static_cast<char>(i + 'a');
                    ans.push_back(c);
                    cnt[i]--;
                    if(cnt[i] > 0){
                        flag = true;
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    string str = "aaaabbbbcccc";
    string ret = s.sortString(str);
    cout << ret << endl;
    return 0;
}