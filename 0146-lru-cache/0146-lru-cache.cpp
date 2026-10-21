class LRUCache {
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;

        auto it = mp[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            cache.erase(mp[key]);
        } else if (cache.size() == cap) {
            int oldKey = cache.back().first;
            cache.pop_back();
            mp.erase(oldKey);
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};