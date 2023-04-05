#include <string>

class StringView {
public:
    StringView (std::string& s, size_t begin = 0, size_t count = std::string::npos)
        : begin_ (begin), end_ (s.size ()) {
        if (begin < s.size ()) {
            end_ = std::min (begin + count, s.size ());
            begin_ = begin;
            str_ = &s;
        }
    }

    StringView (const StringView& sv, size_t begin = 0, size_t count = std::string::npos)
        : begin_ (begin), end_ (sv.size ()) {
        if (begin < sv.size ()) {
            end_ = std::min (begin + count, sv.size ());
            begin_ = begin + sv.begin_;
            str_ = sv.str_;
        }
    }

    size_t length () const { return end_ - begin_; }
    size_t size () const { return end_ - begin_; }
    const char& operator[](size_t index) const { return (*str_)[begin_ + index]; }
    const char& at (size_t index) const {
        if (index >= length ()) throw std::out_of_range ("StringView::at");
        return (*str_)[begin_ + index];
    }

    std::string str (size_t begin = 0, size_t count = std::string::npos) const {
        begin = std::min (begin, length ());
        count = std::min (count, length () - begin);
        return str_->substr (begin_ + begin, count);
    }

    // итераторы произвольного доступа
    const char* begin () const { return &(*str_)[begin_]; }
    const char* end () const { return &(*str_)[end_]; }

    bool operator==(const StringView& other) const {
        if (length () != other.length ()) return false;
        for (size_t i = 0; i < length (); ++i)
            if ((*this)[i] != other[i]) return false;
        return true;
    }

    bool operator!=(const StringView& other) const {
        return !operator==(other);
    }

    bool operator<(const StringView& other) const {
        size_t min_len = std::min (length (), other.length ());
        for (size_t i = 0; i < min_len; ++i) {
            if ((*this)[i] < other[i]) return true;
            if ((*this)[i] > other[i]) return false;
        }
        return length () < other.length ();
    }

    bool operator>(const StringView& other) const {
        return !operator<=(other);
    }

    bool operator<=(const StringView& other) const {
        return operator<(other) || operator==(other);
    }

    bool operator>=(const StringView& other) const {
        return !operator<(other);
    }

private:
    std::string* str_;
    size_t begin_, end_;
};