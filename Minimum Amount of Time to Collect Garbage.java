class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int minTime = 0;
        boolean lastM = false, lastG = false, lastP = false;

        for (int i = 1; i < travel.length; i++) travel[i] += travel[i - 1];
       
        for (int i = 0; i < garbage.length; i++) {
            minTime += garbage[i].length();
        }
        
        for (int i = garbage.length - 1; i > 0; i--) {
            if (garbage[i].contains("G")) {minTime += travel[i - 1]; break;}
        }

        for (int i = garbage.length - 1; i >= 0; i--) {
            if (garbage[i].contains("P")) {minTime += travel[i - 1]; break;}
        }

        for (int i = garbage.length - 1; i >= 0; i--) {
            if (garbage[i].contains("M")) {minTime += travel[i - 1]; break;}
        }

        return minTime;
    }
}
