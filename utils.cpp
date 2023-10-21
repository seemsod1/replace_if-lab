#include "utils.h"


void vector_fil(std::vector<int> &v) {
    int i = 0;
    for (auto &e: v) {
        e = i;
        i++;
    }
}
