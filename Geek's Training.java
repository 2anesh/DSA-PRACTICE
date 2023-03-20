class Solution{

    public int maximumPoints(int points[][],int n){

        

        int[]prev = new int[4];

        

        prev[0] = Math.max(points[0][1],points[0][2]);

        prev[1] = Math.max(points[0][0],points[0][2]);

        prev[2] = Math.max(points[0][1],points[0][0]);

        prev[3] = Math.max(Math.max(points[0][1],points[0][2]),points[0][0]);

        

        for(int day = 1; day < n; day++){

            int[] temp = new int[4];

            for(int task = 0; task < 4; task++){

                for(int i = 0; i < 3; i++){

                    if(i != task){ 

                        temp[task] = Math.max(temp[task], prev[i] + points[day][i]);

                    }

                }

            }

            prev = temp;

        }

        

        return prev[3];

    }

}
