class Solution {
    
    //FOR STORING THE INDEXES 
    public static class Pair{
        int row;
        int col;
        
        Pair(int row, int col)
        {
            this.row = row;
            this.col = col;
        }
    }
    public int maxDistance(int[][] grid) {
        
        //FOR DFS
        LinkedList<Pair> queue = new LinkedList<>();
        
        
        int r = grid.length;
        int c = grid[0].length;
        
        //ADDING THE INDEX OF ALL THE 1 PRESENT IN THE MATRIX
        for(int i =0; i<r; i++)
        {
            for(int j =0; j<c; j++)
            {
                if(grid[i][j] == 1)
                {
                    queue.addLast(new Pair(i,j));
                }
            }
        }
        
        //IF THERE ARE NO 1 PRESENT or ALL THE ELEMENTS IN THE GRID IS 1
        if(queue.size()==0 || queue.size() == r*c){return -1;}
        
        //DIRECTIONS FOR THE DFS TO TRAVEL
        int[][] dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        //FOR COUNING THE LEVELS
        int level = -1;
        
        //DFS
        while(queue.size() > 0)
        {
            //FOR COUNIG THE LEVELS 
            level++;
            //SIZE OF THE QUEUE BEFORE THE INNER DFS
            int size = queue.size();
            
            //SLOWLY DECREASING THE size ON EACH ITERATION 
            while(size-- > 0)
            {   
                //FOR GETTING THE FIRS OBJECT
                Pair rem = queue.removeFirst();
                
                //LOOKING IN 4 DIRECTIONS   LEFT|RIGHT|UP|DOWN
                for(int i = 0; i<4; i++)
                {
                    //COPYING THE COORDINATE FROM rem OBJECT
                    int rowdash = rem.row+dirs[i][0];
                    int coldash = rem.col+dirs[i][1];
                    
                    //BASE CASE IF THE COORDINATES ARE OUT OF BOUND  OR  THE COORDINATE IS ALREADY VISITED 
                    if(rowdash < 0 || coldash < 0 || rowdash >= r || coldash >= c || grid[rowdash][coldash] == 1){ continue;}
                    
                    //ADDIN THE COORDINATE TO THE QUEUE
                    queue.addLast(new Pair(rowdash, coldash));
                    //MARKING THE COORDINATE VISITED == 1
                    grid[rowdash][coldash] = 1;
                }
            }
        }
        
        return level;
    }
}
