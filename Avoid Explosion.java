class Solution {

    ArrayList<String> avoidExlosion(int mix[][], int n, int danger[][], int m) {

        // Code Here

        ArrayList<String> ans=new ArrayList<>();

        int par[]=new int[n];

        for(int i=0;i<n;i++)

           par[i]=i;

        

        for(int a[]:mix){

            int x=findPar(a[0]-1,par);

            int y=findPar(a[1]-1,par);

            boolean flag=true;

            for(int i=0;i<danger.length;i++){

                int l=findPar(danger[i][0]-1,par);

                int r=findPar(danger[i][1]-1,par);

                if((x==l && y==r) || (x==r && y==l)){

                    flag=false;

                    break;

                }

            }

            if(flag==false){

                ans.add("No");

            }

            else{

                union(x,y,par);

                ans.add("Yes");

            }

        }

        return ans;

        

    }

    public int findPar(int x,int par[]){

        if(par[x]==x)

          return x;

        return findPar(par[x],par);

    }

    public void union(int a,int b,int arr[]){

        int x=findPar(a,arr);

        int y=findPar(b,arr);

        if(x==y)

          return;

        arr[y]=x;

    }

}
