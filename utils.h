//
// Created by admin on 19.10.2023.
//

#ifndef REPLACE_IF_UTILS_H
#define REPLACE_IF_UTILS_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <execution>
#include <optional>
#include <vector>
#include <random>

struct test {
    bool (*predicate)(int);
    std::string name;
};

void vector_fil(std::vector<int> &v);

template <typename ExecutionPolicy, typename T>
void test_replace_if(std::vector<T>& v, const test &pred, const T& new_value, ExecutionPolicy policy, std::optional<std::string> policy_name) {
    std::cout << std::left << std::setw(11 + 7) << "std::replace_if" << std::setw(10 + 7) << v.size();
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << std::setw(9 + 7) << (policy_name ? policy_name.value().c_str() : "-")
              << std::setw(11 + 7) << pred.name << std::setw(7) << " ";
    std::replace_if(policy, v.begin(), v.end(), pred.predicate, new_value);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << std::setw(8) << std::fixed << duration.count() << " sec" << std::endl;
}


#endif //REPLACE_IF_UTILS_H
