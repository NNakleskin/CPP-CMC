#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <functional>
/*
#include "up03-2.cpp"
#include "mz03-1.cpp"


Функции подается на вход польская инверсная запись выражения над комплексными числами с одной переменной и значение переменной. В качестве результата функция возвращает вычисленное значение.

Каждый элемент польской записи находится в отдельном элементе вектора.

Возможные ошибки при вычислении игнорируйте.

Вы должны сдать только функцию eval.

В польской записи допускаются следующие элементы:

Запись комплексного числа в виде (RE,IM) (см. предыдущие задачи).
Обозначение переменной "z" (строчная латинская буква).
Знаки бинарных операций +, -, *, /.
Знак унарной операции !, которая заносит в стек элемент, находящийся на верхушке стека.
Знак унарной операции ;, которая удаляет элемент с верхушки стека.
Знак унарной операции ~, которая вычисляет комплексно-сопряженное число.
Знак унарной операции #, которая меняет знак у числа.
Обратите внимание, что польская запись z1 z2 - обозначает (z1 - z2), а не (z2 - z1)!

Каждая строка в массиве строк содержит ровно один элемент польской записи. Пробельные символы отсутствуют.

Реализуйте отображение из операций в действия с помощью отображения (std::map) анонимных функций.
*/

namespace numbers {
    complex eval (const std::vector<std::string>& args, const complex& z) {
        complex_stack stack;
        std::map<std::string, std::function<void (complex_stack&, const complex&)>> funcs = {
            {"z", [](complex_stack& st, const complex& z) {
                st = st << z;
            }},
            {"+", [](complex_stack& st, const complex&) {
                complex elem1, elem2;
                elem1 = +st;
                st = ~st;
                elem2 = +st;
                st = ~st;
                st = st << (elem1 + elem2);
            }},
            {"-", [](complex_stack& st, const complex&) {
                complex elem1, elem2;
                elem1 = +st;
                st = ~st;
                elem2 = +st;
                st = ~st;
                st = st << (elem2 - elem1);
            }},
            {"*", [](complex_stack& st, const complex&) {
                complex elem1, elem2;
                elem1 = +st;
                st = ~st;
                elem2 = +st;
                st = ~st;
                st = st << (elem1 * elem2);
            }},
            {"/", [](complex_stack& st, const complex&) {
                complex elem1, elem2;
                elem1 = +st;
                st = ~st;
                elem2 = +st;
                st = ~st;
                st = st << (elem2 / elem1);
            }},
            {"!", [](complex_stack& st, const complex&) {
                complex elem;
                elem = +st;
                st = st << elem;
            }},
            {";", [](complex_stack& st, const complex&) {
                st = ~st;
            }},
            {"~", [](complex_stack& st, const complex&) {
                st = st << ~+ st;
            }},
            {"#", [](complex_stack& st, const complex&) {
                st = st << -+st;
            }}
        };
        for (const auto& elem : args) {
            if (funcs.count (elem)) {
                funcs[elem] (stack, z);
            } else {
                complex value (elem.c_str ());
                funcs["z"] (stack, value);
            }
        }
        return +stack;
    }
}