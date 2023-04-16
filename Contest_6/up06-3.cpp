#include <vector>
#include <functional>

template<typename Iterator, typename Function>
void myapply (Iterator begin, Iterator end, Function f) {
    while (begin != end) {
        f (*begin);
        ++begin;
    }
}

template<typename Iterator, typename Predicate>
std::vector<std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>>
myfilter2 (Iterator begin, Iterator end, Predicate pred) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>> result;
    while (begin != end) {
        if (pred (*begin)) {
            result.emplace_back (*begin);
        }
        ++begin;
    }
    return result;
}
