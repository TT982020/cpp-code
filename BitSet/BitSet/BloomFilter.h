#pragma once
#include <string>
struct BKDRHash
{
    size_t operator()(const string& str)
    {
        register size_t hash = 0;
        for (auto ch : str)
        {
            hash = hash * 131 + ch;
        }
        return hash;
    }
};

struct APHash
{
    size_t operator()(const string& str)
    {
        register size_t hash = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if ((i & 1) == 0)
            {
                hash ^= ((hash << 7) ^ str[i] ^ (hash >> 3));
            }
            else
            {
                hash ^= (~((hash << 11) ^ str[i] ^ (hash >> 5)));
            }
        }
        return hash;
    }
};

struct DJBHash
{
    size_t operator()(const string& str)
    {
        register size_t hash = 5381;
        for (auto ch : str)
        {
            hash += (hash << 5) + ch;
        }
        return hash;
    }
};



template<size_t N,
        class K = string,
        class Hash1 = BKDRHash,
        class Hash2 = APHash,
        class Hash3 = DJBHash>
class bloomfilter {
public:
    void set(const K& key) {
        BKDRHash hs1;
        APHash hs2;
        DJBHash hs3;
        size_t hash1 = hs1(key) % N;
        size_t hash2 = hs2(key) % N;
        size_t hash3 = hs3(key) % N;
        _bs.set(hash1);
        _bs.set(hash2);
        _bs.set(hash3);
    }

    bool test(const K& key) {
        BKDRHash hs1;
        APHash hs2;
        DJBHash hs3;
        size_t hash1 = hs1(key) % N;
        if (_bs.test(hash1) == false )
        {
            return false;
        }
        size_t hash2 = hs2(key) % N;
        if (_bs.test(hash2) == false)
        {
            return false;
        }
        size_t hash3 = hs3(key) % N;
        if (_bs.test(hash3) == false)
        {
            return false;
        }
        return true;
    }
private:
    bit_set::bitset<N> _bs;
};
