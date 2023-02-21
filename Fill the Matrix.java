class Solution
{
	public static int minIteration(int N, int M, int x, int y){
		
		return Math.max(x-1, N-x) + Math.max(y-1, M-y);
		
	}
}
