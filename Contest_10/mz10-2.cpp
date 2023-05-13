#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <cctype>

struct Rule {
    std::string left;
    std::string right;
};

std::vector<Rule> remove_unreachable (std::vector<Rule> rules) {
    std::unordered_set<char> reachable{'S'};
    std::vector<Rule> result;
    bool changed = true;
    while (changed) {
        changed = false;
        for (const auto& rule : rules) {
            if (reachable.count (rule.left[0])) {
                for (char symbol : rule.right) {
                    if (isupper (symbol) && !reachable.count (symbol)) {
                        reachable.insert (symbol);
                        changed = true;
                    }
                }
            }
        }
    }
    for (const auto& rule : rules) {
        if (reachable.count (rule.left[0])) {
            result.push_back (rule);
        }
    }
    return result;
}

int main () {
    std::vector<Rule> rules;
    std::string line;
    while (std::getline (std::cin, line)) {
        std::istringstream iss (line);
        Rule rule;
        iss >> rule.left >> rule.right;
        rules.push_back (rule);
    }
    std::vector<Rule> result = remove_unreachable (rules);
    for (const auto& rule : result) {
        std::cout << rule.left << " " << rule.right << std::endl;
    }
    return 0;
}