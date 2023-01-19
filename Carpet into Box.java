class Solution{
    int count=0;
    int carpetBox(int A, int B, int C, int D) { 
        find(A, B, Math.min(C,D), Math.max(C,D));
        return count;
    }
    
    void find(int cWidth, int cLength, int boxWidth, int boxLength){
        int carpetWidth=Math.min(cWidth, cLength);
        int carpetLength=Math.max(cWidth, cLength);
        
        if(boxLength<carpetLength){
            count++;
            carpetLength/=2;
            find(carpetWidth, carpetLength, boxWidth, boxLength);
        }
        else if(boxWidth<carpetWidth){
            count++;
            carpetWidth/=2;
            find(carpetWidth, carpetLength, boxWidth, boxLength);
        }
    }
   
}
