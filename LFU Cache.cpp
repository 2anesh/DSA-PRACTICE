class LFUCache {
    unordered_map<int, list<pair<int,int>> > freq_to_kv; // freq, linked list of nodes by recency
    unordered_map<int, list<pair<int,int>>::iterator> key_to_ll; // key to position within linked list
    unordered_map<int, int> key_to_freq; // key to frequency.
    
    int min_freq; /* keep track of position of lowest frequency */
    int capac;

public:
    LFUCache(int capacity){
        capac = capacity;
        min_freq = 0;
    }

    int get(int key) {
        if (key_to_ll.find(key) == key_to_ll.end())
        {
            return -1;
        }
        else
        {
            /* retrieve value */
            int ret_val = key_to_ll[key]->second;

            /* move up a frequency, update min_freq if applicable */
            int curr_freq = key_to_freq[key];

            freq_to_kv[curr_freq].erase(key_to_ll[key]); // delete from curr_freq's linked list

            /* update min_freq if curr_freq is emptied and we are equal to the min_freq */
            if (freq_to_kv[curr_freq].empty() && curr_freq == min_freq)
            {
                min_freq++;
            }

            freq_to_kv[curr_freq+1].push_back(make_pair(key, ret_val));
            key_to_ll[key] = --freq_to_kv[curr_freq+1].end(); //update to point to new position

            key_to_freq[key]++;

            return ret_val;
        }
    }

    void put(int key, int value) {

        if (capac <= 0)
        {
            return;
        }

        const auto it = key_to_ll.find(key);
        if (it == key_to_ll.end())
        {
            if (key_to_ll.size() >= capac)
            {
                /* delete least recent of the least frequent (front() of linked list) */
                
                // extract the key of the boi to be deleted
                int key_delet = freq_to_kv[min_freq].front().first;

                key_to_ll.erase(key_delet);
                key_to_freq.erase(key_delet);

                freq_to_kv[min_freq].pop_front();
            }
            
            /* insert element */
            freq_to_kv[1].push_back(make_pair(key, value));
            key_to_ll[key] = --freq_to_kv[1].end();
            key_to_freq[key] = 1;

            // reset min_freq
            min_freq = 1;
        }
        else
        {
            /* update value */
            key_to_ll[key]->second = value;
            get(key); /* up frequency, etc */
        }
    }
};
