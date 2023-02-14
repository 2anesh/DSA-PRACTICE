class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string s;
        int i = a.length()-1; 
        int j = b.length()-1;
        while(i>=0 || j>=0)
        {
            int x = (i>=0)?a[i--]-'0':0;  // checks if the digit is 0 or 1 and converts it to string
            int y = (j>=0)?b[j--]-'0':0;
			
            int sum = x+y+carry;
			
            s.append(to_string(sum%2)); // as 1+1=0 and 1+1+1=1 so sum = 2 and sum = 3 respectively, thus 0 and 1 will be added to the string
			
            carry = sum/2; // if sum = 2, so carry added will be 1
        }
        if(carry>0)
            s.append(to_string(1));
        reverse(s.begin(), s.end());
        return s;
    }
};
