template <class T>


typename T::value_type process (const T& container) {
    int i = 0;
    typename T::value_type sum = typename T::value_type ();
    for (typename T::const_reverse_iterator it = container.rbegin (); it != container.rend (); it++) {
        if (i == 5) {
            break;
        }
        if (i == 2 || i == 0 || i == 4) {
            sum += (*it);
        }
        i++;
    }
    return sum;
}