class Solution{
    static String secondSmallest(int S, int D){
        int min=1,digit,counter=0,temp=0,a=S,digit2;
         StringBuilder str=new StringBuilder();
        if(9*D<S || D==1){
            return("-1");
        }
        else{
        for(int i=1;i<=D;i++){
            if(i==D){
                min=0;
            }
           if(a-9>=1) {
               digit=9;
           }
           else{
               digit=9-((9-a)+min);
           }
           digit2=digit;
        if(i>1 && counter!=2){
            if(digit<9){
                digit+=1;
                counter=2;
                str = str.replace(0, 1, Integer.toString(temp-1));
                
            }
        }
        temp=digit2;
        str=str.insert(0,digit);
        a-=digit2;
        }}
        if(counter!=2){
        return("-1");}
        else{
            return(str.toString());
        }
        
        
    }}
