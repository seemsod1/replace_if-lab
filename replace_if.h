#ifndef REPLACE_IF_REPLACE_IF_H
#define REPLACE_IF_REPLACE_IF_H


#include <vector>
#include <algorithm>
#include <thread>

template<typename Iterator, typename Predicate, typename T>
void replace_part(Iterator begin, Iterator end, Predicate pred, const T& new_value) {
    std::replace_if(begin, end, pred, new_value);
}

template<typename Iterator, typename Predicate, typename T>
void par_replace_if(Iterator begin, Iterator end, Predicate pred, const T& new_value, int numThreads) {
    int dataSize = std::distance(begin, end);
    int partSize = dataSize / numThreads;

    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        Iterator partBegin = begin + i * partSize;
        Iterator partEnd = (i == numThreads - 1) ? end : partBegin + partSize;

        threads.emplace_back([partBegin, partEnd, &pred, new_value]() {
            replace_part(partBegin, partEnd, pred, new_value);
        });
    }

    for (auto &thread: threads) {
        thread.join();
    }
}

#endif //REPLACE_IF_REPLACE_IF_H
