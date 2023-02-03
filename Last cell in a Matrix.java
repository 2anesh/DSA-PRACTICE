class Solution{
    static int [] endPoints(int [][]matrix, int R, int C){
        //code here
        int exit[] = new int[2];
        String lastD = "r";
        
        int i=0, j=0;
        while(i>=0 && i<R && j>=0 && j<C){
            exit[0]=i;
            exit[1]=j;
            
            if(matrix[i][j]==1){
                matrix[i][j]=0;
                lastD = changeDirection(lastD); 
            }
            
            int updatedIndex[] = moveInDir(lastD, i, j);
            i=updatedIndex[0];
            j=updatedIndex[1];
            
                
        }
        return exit;
    }
    
    static String changeDirection(String dir){
        String s = "";
        if(dir.equals("u"))
            s="r";
        else if(dir.equals("r"))
            s="d";
        else if(dir.equals("d"))
            s="l";
        else if(dir.equals("l"))
            s="u";
        return s;    
    }
    
    
    static int[] moveInDir(String lastD, int i, int j){
        int[] newIndex = new int[2];
        
        if(lastD.equals("r"))
            j++;
        else if(lastD.equals("l"))
            j--;
            
        else if(lastD.equals("u"))
            i--;
        else if(lastD.equals("d"))
            i++;    
        
        newIndex[0]=i;
        newIndex[1]=j;
        return newIndex;
            
    } 
}
