#include <vector>
#include <algorithm>

void process (const std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> indices (v1);
    std::sort (indices.begin (), indices.end ());
    auto last = std::unique (indices.begin (), indices.end ());
    indices.erase (last, indices.end ());
    int shift = 0;
    for (auto it = indices.begin (); it != indices.end (); ++it) {
        int index = *it - shift;
        if (index < (int) v2.size () && index >= 0) {
            v2.erase (v2.begin () + index);
            shift++;
        }
    }
}