class Solution

{

    //Function to perform case-specific sorting of strings.

    public static String caseSort(String str)

    {

        // Your code here

        int n=str.length();

        StringBuilder small=new StringBuilder();

        StringBuilder upper=new StringBuilder();

        for(char c:str.toCharArray()){

            if(c>=97){

                small.append(c);

            }

            else{

                upper.append(c);

            }

        }

        char sm[]=small.toString().toCharArray();

        char up[]=upper.toString().toCharArray();

         StringBuilder sb=new StringBuilder();

         Arrays.sort(sm);

        Arrays.sort(up);

        int i=0,j=0;

        for(char c:str.toCharArray()){

            if(c>=97){

                sb.append(sm[i++]);

               }

            else{

                sb.append(up[j++]);

            }

        }

        return sb.toString();

    }

}
