class Solution {
    static int minRepeats(String a, String b) {
        // code here
        int temp = b.length()/a.length();
        if(b.length()%a.length() != 0){
            temp+= 1;
        }
        int temp2 = temp +1;
        String c = "";
        for (int i = 0; i < temp; i++) {
            c += a;
        }

        String d = "";
        for (int i = 0; i < temp2; i++) {
            d += a;
        }

        if(c.contains(b)){
            return temp;
        } else if(d.contains(b)){
            return temp2;
        }else{
            return -1;
        }
    }
};
