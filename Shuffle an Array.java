class Solution {
   int a[];
   int b[];
    public Solution(int[] nums) {
        a=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            a[i]=nums[i];
        }
        b=nums;
    }
    
    public int[] reset() {
        return a;
    }
    
    public int[] shuffle() {
        int i1=(int)(Math.random()*100);
        i1=i1%a.length;
        int i2=(int)(Math.random()*100);
        i2=i2%a.length;
        int v=b[i1];
        b[i1]=b[i2];
        b[i2]=v;
        return b;

    }
}
