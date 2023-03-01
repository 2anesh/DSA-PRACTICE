class Solution {
    public int[] sortArray(int[] nums) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>((a,b) -> a - b);
        int[] result = new int[nums.length];

        for(int i=0;i<nums.length;i++)
        minHeap.add(nums[i]);

        for(int j=0;j<nums.length;j++)
        result[j]=minHeap.poll();

        return result;
    }
}
