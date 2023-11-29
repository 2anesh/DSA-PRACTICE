class Solution {
public:
    int isEulerCircuit(int V, vector<int>adj[]){
        int even_degree=0;
        int odd_degree=0;
        
        for(int i=0;i<V;i++){
            if(adj[i].size()%2==0){
                even_degree++;
            }else{
                odd_degree++;
            }
        }
        
        if(even_degree==V){
            return 2;
        }
        
        if(odd_degree>0 && odd_degree==2)
        return 1;
        
        return 0;
    }
};

