class Solution {
    public int longestStrChain(String[] words) {
       
        Arrays.sort(words, (a, b) -> Integer.compare(a.length(), b.length()));

        Map<String, Integer> wordLen = new HashMap<>();

        int maxLen = 1;

        for (String word : words) {
           
            wordLen.put(word, 1);

            for (int i = 0; i < word.length(); i++) {
                StringBuilder predecessor = new StringBuilder(word);
                predecessor.deleteCharAt(i);
                String predecessorStr = predecessor.toString();

                if (wordLen.containsKey(predecessorStr)) {
                    int currLen = wordLen.get(word);
                    int predecessorLen = wordLen.get(predecessorStr) + 1;
                    wordLen.put(word, Math.max(currLen, predecessorLen));
                }
            }

            maxLen = Math.max(maxLen, wordLen.get(word));
        }

        return maxLen;
    }
}
