class Solution {

    public static int freq(int n, int [] A, int i){

        int count = 0;

        for(int j=i; j<A.length; j++){

            if(A[j] == n){

                count++;

            }

        }

        return count;

    }

    public static ArrayList<Integer> solveQueries(int N, int num, int[] A, int[][] Q) {

        // code here

        ArrayList<Integer> list = new ArrayList<>();

        int row = num;

        int col = Q[0].length;

        for(int i=0; i<num; i++){

            int count=0;

            for(int j=Q[i][0]; j<=Q[i][1]; j++){

                if(freq(A[j], A, j) == Q[i][2]){

                    count++;

                }

            }

            list.add(count);

        }

        return list;

    }

}

