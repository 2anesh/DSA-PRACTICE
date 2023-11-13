class Solution {
    public String sortVowels(String s) {
        int n=s.length();
        char[] charArray=s.toCharArray();
        String[] vowel=new String[n];
        int k=0;
        for(int i=0;i<n;i++) {
            if (isVowel(charArray[i])) {
                vowel[k++] =String.valueOf(charArray[i]);
            }
        }
        vowel=Arrays.copyOf(vowel,k);

        Arrays.sort(vowel);
        int j=0;
        for(int i=0;i<charArray.length;i++) {
            if(isVowel(charArray[i])){
                charArray[i]=vowel[j++].charAt(0);
            }
        }
        return new String(charArray);
    }

    private boolean isVowel(char c) {
        return c=='A' || c=='E' ||  c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
}
