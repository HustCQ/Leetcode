class LRUCache {
private:
    list<int> _keys;
    map<int, int> _kvs;
    map<int, list<int>::iterator> _iterators;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {

        if(_kvs.count(key) != 0) {
            auto val = _kvs[key];
            put(key, val);
            return val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (_kvs.count(key) != 0) { // 命中缓存
            auto it = _iterators[key];
            _keys.erase(it);
            _keys.push_front(key);
            _kvs[key] = value;
            _iterators[key] = _keys.begin();
        } else {
            if(_kvs.size() == _capacity) { // 缓存满了，需要去除最老元素
                int oldestKey = _keys.back(); // 最老元素
                auto it = _iterators[oldestKey];
                _keys.pop_back();
                _iterators.erase(oldestKey);
                _kvs.erase(oldestKey);
            }

            _kvs[key] = value;
            _keys.push_front(key);
            _iterators[key] = _keys.begin();
        }
    }
};