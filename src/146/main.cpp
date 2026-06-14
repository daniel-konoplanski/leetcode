#include <iterator>
#include <unordered_map>
#include <list>

class LRUCache
{
private:
    using ListIter = std::list<std::pair<int,int>>::iterator;
    using Key = int;
    using Value = int;

public:
    LRUCache(int capacity)
        : capacity_{capacity}
    {
    }

    int get(int key)
    {
        if (!map_.contains(key))
            return -1;

        auto iterator = map_[key];
        auto value = iterator->second;

        list_.erase(iterator);
        list_.push_front({key, value});
        map_[key] = list_.begin();

        return value;
    }

    void put(int key, int value)
    {
        if (map_.contains(key))
        {
            list_.erase(map_[key]);
            list_.push_front({key, value});
            map_[key] = list_.begin();
            return;
        }

        if (currentElements_ == capacity_)
        {
            auto [k, v] = list_.back();
            map_.erase(k);
            list_.pop_back();
        }
        else
        {
            currentElements_++;
        }

        list_.push_front({key, value});
        map_.insert_or_assign(key, list_.begin());
    }

private:
    int currentElements_{};
    int capacity_{};
    std::list<std::pair<Key, Value>> list_;
    std::unordered_map<Key, ListIter> map_;
};

auto main() -> int
{
}
