#include "tests.h"
#include "predicates.h"


void test_custom_replace_if() {
    std::vector<int> v( 50000000);

    std::cout << std::left
              << std::setw(10 + 7) << " "
              << std::setw(1 + 7) << "K"
              << std::setw(10 + 7) << "SIZE"
              << std::setw(9 + 7) << "PREDICATE"
              << std::setw(11) << "TIME TAKEN" << std::endl;
    for (int k = 1; k <= 20; k++) {
        vector_fil(v);
        std::cout << std::setw(10 + 7) << "par_replace_if"
                  << std::left << std::setw(1 + 7) << k
                  << std::setw(10 + 7) << v.size()
                  << std::setw(9 + 7) << "is_odd";
        auto start = std::chrono::high_resolution_clock::now();
        par_replace_if(v.begin(), v.end(), is_odd, 0, k);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;

        std::cout << std::setw(8) << std::fixed << duration.count() << " sec" << std::endl;

    }
}
void test_all() {
    std::vector<test> tests = {
            {is_even, "is_even"},
            {is_prime,    "is_prime"},
            {is_odd,    "is_odd"}
    };

    std::cout << std::left
              << std::setw(11 + 7) << " "
              << std::setw(10 + 7) << "SIZE"
              << std::setw(9 + 7) << "POLICY"
              << std::setw(11 + 7) << "PREDICATE"
              << std::setw(11) << "TIME TAKEN" << std::endl;

    for (int i = 5000; i <= 500000; i *= 10) {
        std::vector<int> v(i);

        for (auto &pred: tests) {
            vector_fil(v);
            test_replace_if(v, pred, 1, std::execution::sequenced_policy{}, std::optional<std::string>("seq"));
            vector_fil(v);
            test_replace_if(v, pred, 1, std::execution::unsequenced_policy{}, std::optional<std::string>("unseq"));
            vector_fil(v);
            test_replace_if(v, pred, 1, std::execution::parallel_policy{}, std::optional<std::string>("par"));
            vector_fil(v);
            test_replace_if(v, pred, 1, std::execution::parallel_unsequenced_policy{}, std::optional<std::string>("par_unseq"));
            vector_fil(v);
            std::cout << std::endl;
        }
    }
}

