class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        int n=asteroids.length;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]<=0)
            {
                while(!stack.isEmpty() && stack.peek ()> 0 && stack.peek()<asteroids[i]*-1)
                    stack.pop();
                
                if(!stack.isEmpty() && stack.peek()==asteroids[i]*-1)
                    stack.pop();
                
                else if(!stack.isEmpty() && stack.peek() >= -1*asteroids[i])
                    continue;
                else
                    stack.push (asteroids[i]);
            }
        else
            stack.push(asteroids[i]);
            
            
        }
        
        n=stack.size();
        int arr[]=new int[n];
        
        for(int i=n-1;i>=0;i--)
        arr[i]=stack.pop();
        return arr;
        
    }
}
