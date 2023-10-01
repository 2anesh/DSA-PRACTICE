class Solution {
    public String reverseWords(String s) {
         String[] words = s.split(" "); 
        StringBuilder result = new StringBuilder();
        
        for (String word : words) {
            result.append(reverseWord(word)).append(" "); 
        }
        
        return result.toString().trim(); 
    }
    
    private String reverseWord(String word) {
        char[] chars = word.toCharArray();
        int left = 0, right = chars.length - 1;
        
        while (left < right) {
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
        
        return new String(chars);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String input_str = "Let's take LeetCode contest";
        String output_str = solution.reverseWords(input_str);
        System.out.println(output_str);
    }
}
