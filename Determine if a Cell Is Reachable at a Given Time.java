class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1){
            return false;
        }
        if(Math.abs(fx-sx)<=t && Math.abs(fy-sy)<=t){
            return true;
        } 
        return false;
    }
}
