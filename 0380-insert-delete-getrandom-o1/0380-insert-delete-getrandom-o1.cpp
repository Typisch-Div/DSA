class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> pos;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (pos.count(val)) return false;

        pos[val] = nums.size();
        nums.push_back(val);

        return true;
    }

    bool remove(int val) {
        if (!pos.count(val)) return false;

        int i = pos[val];
        int last = nums.back();

        nums[i] = last;
        pos[last] = i;

        nums.pop_back();
        pos.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};