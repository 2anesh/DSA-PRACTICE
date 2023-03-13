class Solution {
public int numBusesToDestination(int[][] routes, int source, int target) {
    if(source == target) return 0;
    
    HashMap<Integer,ArrayList<Integer>> graph = new HashMap<>();
    
    //build the graph
    //key : the station
    //value: the buses can be taken in this station
    for(int i=0;i<routes.length;i++){
       for(int stop:routes[i]){
           graph.putIfAbsent(stop,new ArrayList<>());
           graph.get(stop).add(i);
       }
    }
    
    Queue<Integer> q = new ArrayDeque<>();
    Set<Integer> visited = new HashSet<>();
    
    q.offer(source);
    
    int count = 0;
    while(!q.isEmpty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            ArrayList<Integer> buses= graph.get(q.poll());
            for(int bus:buses){
                if(visited.contains(bus)) continue;
                visited.add(bus);
                for(int stop:routes[bus]){
                    if(stop == target) return count+1;
                    q.offer(stop);
                }
            }
        }
        count++;
    }
    
    return -1;
	}
}
