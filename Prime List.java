class Solution {
    private int MAX = (int)1e5+1;
    private boolean[] prime = new boolean[MAX];
    
    void fillPrimeArray() {
        Arrays.fill(prime, true);
        prime[0] = false;
        prime[1] = false;
        
        for (int p=2; p*p < MAX; p++) {
            if (prime[p]) {
                for (int i=p*p; i < MAX; i+=p) prime[i] = false;
            }
        }}
    
    int getNearestPrime(int num) {
        if(prime[num]) return num;
        int left = num-1, right = num+1;
        
        while(left >= 0 && !prime[left]) { left--; }
        while(right < MAX && !prime[right]) { right++; }
        
        if(left < 0) return right;
        if(right > MAX-1) return left;
        
        return num-left <= right-num ? left : right;
    }
    
    Node primeList(Node head) {
        if(!prime[2]) fillPrimeArray();
        
        Node temp = head;
        
        while(temp != null) {
            temp.val = getNearestPrime(temp.val);
            temp = temp.next;
        }
        return head;
    }}
