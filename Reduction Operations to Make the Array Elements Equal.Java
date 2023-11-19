class Solution {
    public int reductionOperations(int[] nums) {
        int x = 0;
        for (int num : nums) {
            if (num > x) x = num;
        }
        int[] numLine = new int[x];
        int count = 0;
        

        for (int num : nums) {
            numLine[num - 1] += 1;
        }
        
        int idx = 0;
        for (int num : numLine) {
            if (num == 0) {continue;}
            if (idx == 0) { idx++; continue;}
            
            count += (num * idx);
            idx++;
        }

        return count;
    }
}
