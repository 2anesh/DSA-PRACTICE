class SeatManager {
    PriorityQueue<Integer> pq;
    int i=1, size;

    public SeatManager(int n) {
        pq = new PriorityQueue<>();
        size = n;
    }
    
    public int reserve() {
        if(pq.size()!=0)
            return pq.poll();

        else if(i<=size) return i++;

        return -1;
    }
    
    public void unreserve(int seatNumber) {
        pq.add(seatNumber);
    }
}
