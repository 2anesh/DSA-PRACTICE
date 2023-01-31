class Solution {

  public:

 int minRepeats(string A, string B) {

 

        // code here

 int q = (B.length() - 1) / A.length() + 1;

    string t = "";

    for (int i = 0; i < q; i++) t += A;

    if (t.find(B) != string::npos) return q;

    t += A;

    if (t.find(B) != string::npos) return q + 1;

    return -1;

    }

};
