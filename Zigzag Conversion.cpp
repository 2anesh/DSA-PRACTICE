class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<vector<char> > rows(numRows);
        int cur_row = 0;
        int dir = 1;
        for(int i = 0; i < s.size(); i++){
            rows[cur_row].push_back(s[i]);
            if(cur_row == numRows - 1){
                dir = -1;
            } else if(cur_row == 0){
                dir = 1;
            }
            cur_row += dir;
        }
        string ans = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < rows[i].size(); j++){
                ans.push_back(rows[i][j]);
            }
        }
        return ans;
    }
};
