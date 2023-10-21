# Goal
Explore a `std::replace_if` on different amounts of data, with different policies, and with different
transformations or predicates (if applicable). Namely, to investigate
1. the performance of the library algorithm in the absence of a policy;
2. the performance of the library algorithm with different policies;
3. the performance of your own parallel algorithm when using a different number of threads, namely
namely: to build our own algorithm that divides the sample into K parts of approximately equal length, processes each part in
parts, processes each part in a separate thread (using a sequential library algorithm), and then
combines the result (using a sequential library algorithm). Print the dependence of the running time on
on the value of the parameter K. At what K is the best speed achieved? How does this value relate to
the number of processor threads? According to what law does the time increase with increasing K?

# Results
Найшвидше виконується коли К=12. Кількість потоків у моєму процесорі: 12. Можна зробити висновок, що при рівномірному розподілі на потоки, потрібно виокристовувати кількість рівну кількості потоків у процесорі.
Швидкість зі збельшенням потоків збільшується поступово, і при використані кількості більшої ніж кількість потоків у процесорі, швидкість залишається в тому діапазоні, що і при кількості рівній кількості потоків процесора.
