#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Student {
private:
public:
    long long num;
    long long sum;
    std::string name;
    Student (std::string str, int mark) {
        name.append (str);
        num = 1;
        sum = mark;
    }

    void add_mark (int mark) {
        this->num++;
        this->sum += mark;
    }

    Student& operator+= (const Student& rhs) {
        this->num = this->num + 1;
        this->sum += rhs.sum;
        return *this;
    }
    double get_avg () {
        return (double) sum / (double) num;
    }
};

bool operator<(const Student& lhs, const Student& rhs) {
    return lhs.name < rhs.name;
}


int main () {
    std::vector<Student> student_vect;
    std::string str;
    int num;
    while (std::cin >> str) {
        std::cin >> num;
        const Student tmp (str, num);
        bool flag = false;
        for (size_t i = 0; i < student_vect.size (); i++) {
            if (!student_vect[i].name.compare (str)) {
                student_vect[i].operator+=(tmp);
                flag = true;
            }
        }
        if (flag == false) {
            student_vect.push_back (tmp);
        }
    }

    stable_sort (student_vect.begin (), student_vect.end ());

    for (size_t i = 0; i < student_vect.size (); i++) {
        std::cout << student_vect[i].name << " " << student_vect[i].get_avg () << std::endl;
    }
}