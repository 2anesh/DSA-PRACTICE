public static int maxCoins(int n,int arr[][])
    {
        Arrays.sort(arr, (a, b)->a[1]==b[1]? a[0]-b[0]:a[1]-b[1]);
        int max = Integer.MIN_VALUE;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        tm.put(0, 0);
        for(int p[] : arr){
            int key = tm.floorKey(p[0]);
            int prev = tm.get(key);
                // System.out.println(key+" "+prev+" ----> "+p[0]+" "+p[1]+" "+p[2]);
                max = Math.max(prev+p[2], max);
                int prevEndMax = tm.get(tm.floorKey(p[1]));
                
                        tm.put(p[1], Math.max(prevEndMax,p[2]));
                    
            
        }
        return max;
    }
