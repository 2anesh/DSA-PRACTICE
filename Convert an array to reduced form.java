class Solution {
    void convert(int[] arr, int n) {
        int[] temp = arr.clone();
        Arrays.sort(temp);
        Map<Integer,Integer> indexMap = new HashMap<>();
        for(int index = 0;index <n;index++){
            indexMap.put(temp[index],index);
        }
        for(int index = 0;index < n;index++){
            arr[index] = indexMap.get(arr[index]);
        }
    }
}
