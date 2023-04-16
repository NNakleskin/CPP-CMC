template<typename Container, typename Predicate>
Container myfilter (const Container& container, Predicate pred) {
    Container result;
    for (const auto& elem : container) {
        if (pred (elem)) {
            result.insert (result.end (), elem);
        }
    }
    return result;
}