class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        boolean isSorted = true;
        for (int wordsIndex = 0; wordsIndex < words.length-1; wordsIndex++) {
            for (int charIndex = 0; charIndex < words[wordsIndex].length(); charIndex++) {  
                int word1Index = order.indexOf(words[wordsIndex].charAt(charIndex));
                int word2Index = order.indexOf(words[wordsIndex+1].charAt(charIndex));
                int word1Length = words[wordsIndex].length()-1;
                int word2Length = words[wordsIndex+1].length()-1;
                
                if (word1Index < word2Index) {
                    break;
                }
                
                if (word1Index > word2Index || (charIndex == word2Length && word1Length != word2Length)) {
                    isSorted = false;
                    break;
                }                       
            }
            
            if (!isSorted) {
                break;
            }
        }
        
        return isSorted;
    }
}
