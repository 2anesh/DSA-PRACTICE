 public class LFUCache{
    
    HashMap<Integer, Integer> cache = new HashMap<>();
    HashMap<Integer, Integer> keyCounts = new HashMap<>();
    HashMap<Integer, LinkedHashSet<Integer>> freqMap = new HashMap<>();
    int capacity;
    int min = -1;
        
    public LFUCache (int capacity) {
        this.capacity = capacity;
        freqMap.put(1, new LinkedHashSet<>());
    }
    
    public int get(int key) {
        if(cache.containsKey(key) == false) return -1;
        int count = keyCounts.get(key);
        keyCounts.put(key, count+1); // update
        freqMap.get(count).remove(key);
        if(count == min && freqMap.get(count).size() == 0) min++;
        if(freqMap.containsKey(count+1) == false) freqMap.put(count+1, new LinkedHashSet<>());
        freqMap.get(count+1).add(key);
        return cache.get(key);
    }
    
    public void put(int key, int value) {
       if(capacity <= 0) return;
       if(cache.containsKey (key)){
            cache.put(key, value);
            get(key);
            return;
        }
        if(cache.size() >= capacity){
            int evict = freqMap.get(min).iterator ().next();
            freqMap.get(min).remove(evict);
            cache.remove (evict);
            keyCounts.remove(evict);
        }
        cache.put(key, value);
        keyCounts.put (key, 1);
        min = 1;
        freqMap.get(1).add(key);
    }
}
