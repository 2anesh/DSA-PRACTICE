class Solution

{

    public int CountWays(String str)

    {

        int [] dp = new int[str.length()];

        int mod = 1000000007;

        dp[0] = 1;

        for(int i=1; i< str.length(); i++){

            if(str.charAt(i) == '0' && str.charAt(i-1) == '0'){

                dp[i] = 0;

            }else if(str.charAt(i) != '0' && str.charAt(i-1) == '0'){

                dp[i] = dp[i-1];

            }else if(str.charAt(i) == '0' && str.charAt(i-1) != '0'){

                if(str.charAt(i-1) == '1' || str.charAt(i-1) == '2'){

                    dp[i] = (i>=2 ? dp[i-2]: 1);

                }

            }else {

               String st = str.substring(i-1,i+1);

               dp[i] = dp[i-1];

                if(Integer.parseInt(st) <= 26){

                    dp[i] += (i>=2 ? dp[i-2]: 1);

                } 

            }

            dp[i] = dp[i] %mod;

        }

        return dp[str.length()-1];

    }

}
