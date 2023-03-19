class SeatManager {
    PriorityQueue<Integer> pq;
    public SeatManager(int n) {
        pq = new PriorityQueue<>();
        
        for(int i=1; i<=n; i++){
            pq.add(i);
        }
    }
    
    public int reserve() {
        return pq.remove();
    }
    
    public void unreserve(int seatNumber) {
        pq.add(seatNumber);
    }
}
