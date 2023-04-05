/*В пространстве имен numbers реализуйте класс complex_stack, который будет реализовывать функциональность иммутабельного стека комплексных чисел из предыдущей задачи.

Реализация не должна использовать стандартные контейнерные классы (vector, stack и т. п.).

Класс должен реализовывать:

конструктор по умолчанию.
конструкторы, деструкторы и операции, необходимые для корректного управления памятью.
++++метод size для получения числа элементов в стеке (возвращает size_t).
++++доступ к произвольному элементу стека только на чтение с помощью операции [].
++++бинарный оператор <<, у которого первый аргумент - complex_stack, а второй аргумент - complex, бинарный оператор возвращает новый стек, в который добавлен указанный элемент. Исходный стек не изменяется.
++++унарный оператор +, который возвращает элемент типа complex с вершины стека.
++++унарный оператор ~, который удаляет один элемент из стека и возвращает модифицированный стек, исходный стек при этом не изменяется.
На проверку сдавайте только класс complex_stack.

Возможные ошибки (извлечение из пустого стека, доступ за пределами стека) игнорируйте.

Дополнительно реализуйте:

Семантику переноса в конструкторе, присваивании и операциях << и ~
placement new для минимизации вызовов конструкторов при перевыделении памяти*/

#include <cstddef>
#include <string>
#include <cmath>    

namespace numbers {
    class complex_stack {
        complex* arr_;
        size_t size_ = 0;
        size_t capacity_ = 0;
    public:

        complex_stack (): arr_ (new complex[10]), size_ (0), capacity_ (10) {}

        complex_stack (size_t size) {
            arr_ = new complex[size];
            capacity_ = size;
            this->size_ = 0;
        }

        complex_stack (const complex_stack& other) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            arr_ = new complex[other.capacity_];
            for (size_t i = 0; i < other.size_; ++i) {
                arr_[i] = other.arr_[i];
            }
        }

        complex_stack (complex_stack&& other) noexcept: arr_ (other.arr_), size_ (other.size_), capacity_ (other.capacity_) {
            other.arr_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        complex_stack& operator=(const complex_stack& other) {
            delete []  arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            arr_ = new complex[other.capacity_];
            for (size_t i = 0; i < other.size_; ++i) {
                arr_[i] = other.arr_[i];
            }
            return *this;
        }

        ~complex_stack () {
            delete [] arr_;
        }


        size_t size () const {
            return size_;
        }


        complex operator+() const {
            return arr_[size_ - 1];
        }

        complex_stack operator~() const {
            complex_stack res (*this);
            res.size_--;
            return res;
        }

        const complex& operator[](size_t i) const {
            return arr_[i];
        }

        complex_stack operator<<(const complex& x) const {
            if (size_ == capacity_) {
                complex_stack res (size_ * 2);
                res.size_ = size_ + 1;
                for (size_t i = 0; i < size_; ++i) {
                    res.arr_[i] = arr_[i];
                }
                res.arr_[size_] = x;
                return res;
            } else {
                complex_stack res (*this);
                res.arr_[size_] = x;
                res.size_++;
                return res;
            }
        }
    };
}