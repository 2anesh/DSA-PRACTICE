class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i = 0;
        int ansIndex = 0;

        while(i < chars.size()) {

            int j = i+1;

            while(j < chars.size() && chars[i] == chars[j]) {
                j++;
            }

            // Yo vector khatm hogya h, ya fer new.different character milgya

            // purana character store kar leta hu
            chars[ansIndex++] = chars[i];

            int count = j-i;

            if(count>1) {
                // adding the count value digit by digit
                string cnt = to_string(count);
                for(char ch: cnt) {
                    chars[ansIndex++] = ch;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};
