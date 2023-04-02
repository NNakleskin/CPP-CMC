#include <array>
#include <iostream>

class Matrix {
public:
    Matrix () { data_.fill ({ 0, 0, 0 }); }

    int& operator[](int i, int j) { return data_[i][j]; }


    auto begin () { return data_.begin (); }
    auto end () { return data_.end (); }
    auto begin () const { return data_.begin (); }
    auto end () const { return data_.end (); }

private:
    std::array<std::array<int, 3>, 3> data_;
};

