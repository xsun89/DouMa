//
// Created by Xin Sun on 2021-04-14.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<vector<int>> cnt(A.size());
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i].push_back(0);
            }
        }
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cnt[i][A[i][j] - 'a'] = cnt[i][A[i][j] - 'a'] + 1;
            }
        }

        vector<string> ans;
        int i = 0;
        for (int j = 0; j < cnt[i].size(); j++) {
            if (cnt[i][j] > 0) {
                bool found = true;
                int mi = cnt[i][j];
                for (int k = i + 1; k < cnt.size(); k++) {
                    if (cnt[k][j] == 0) {
                        found = false;
                        break;
                    }
                    mi = min(mi, cnt[k][j]);
                }
                if (found) {
                    for(int l = 0; l < mi && l < 4; l++) {
                        string tmp = "";
                        char c = static_cast<char>(j + 'a');
                        tmp.push_back(c);
                        ans.push_back(tmp);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> data = {"cool","lock","cook"};
    vector<string> ret = s.commonChars(data);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
    return 0;
}
