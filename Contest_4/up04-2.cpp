#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>


void process (std::vector<int64_t>& v, int64_t limit) {
    v.reserve (v.size () * 2);
    for (auto it = v.rbegin (); it != v.rend (); it++) {
        if (*it >= limit) {
            v.push_back (*it);
        }
    }
}



