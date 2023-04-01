#include <string>

using namespace std;

class BinaryNumber {
public:
    BinaryNumber (const string& s): value (s) {}
    operator string() const { return value; }

    const BinaryNumber& operator++() {
        int n = value.size ();
        bool carry = true;
        for (int i = n - 1; i >= 0; --i) {
            if (value[i] == '0') {
                value[i] = '1';
                carry = false;
                break;
            } else {
                value[i] = '0';
            }
        }

        if (carry) {
            value = '1' + value;
        }

        return *this;
    }

private:
    string value;
};
