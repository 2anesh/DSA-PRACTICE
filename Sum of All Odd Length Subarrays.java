class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
         List<Integer> list = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            list.add(arr[i]);
        }
        int sum = 0;
        int odd = 1;
        for (int i = 0; i < arr.length; i += 1) {
            if(odd>arr.length) break;
            if (i+odd <= arr.length) {
                List<Integer> sublist = list.subList(i, i+odd);
                for (int j = 0; j < sublist.size(); j++) {
                    sum += sublist.get(j);
                }
                if (i == arr.length - 1 && odd < arr.length) {
                    odd += 2;
                    i = -1;
                }
            }else{
                odd += 2;
                i = -1;
            }
        }
        return sum;
    }
}
