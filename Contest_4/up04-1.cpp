#include <vector>
#include <cstdint>

void process (const std::vector<uint64_t>& first, std::vector<uint64_t>& second, std::size_t step) {
    auto second_it = second.rbegin ();
    for (auto it = first.begin (); it < first.end () && second_it != second.rend (); it += step) {
        *second_it += *it;
        ++second_it;
    }
}