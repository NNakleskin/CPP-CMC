#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Student {
    private:
    public:
    int num;
    double avg;
    std::string name;
    Student(std::string str, int mark) {
        name.append(str);
        num = 0;
        avg = mark;
    }

    void add_mark(int mark) {
        this->num++;
        this->avg += mark / 2;
    }

    Student& operator+= (const Student& rhs) {
        this->num = this->num + 1;
        this->avg = (this->avg + rhs.avg) / 2;
        return *this;
    }
};


int main() {
    std::vector<Student> student_vect;
    std::string str;
    int num;
    while(std::cin >> str) {
        std::cin >> num;
        const Student tmp(str, num);
        bool flag = false;
        int max = student_vect.size ();
        for (int i = 0; i < max; i++) {
            if (!student_vect[i].name.compare (str)) {
                student_vect[i].operator+=(tmp);
                flag = true;
            }
        }
        if(flag == false) {
            student_vect.push_back(tmp);
        }
    }
    for (int i = 0; i < max; i++) {
        std::cout << student_vect[i].name << " " << student_vect[i].avg << std::endl;
    }
}