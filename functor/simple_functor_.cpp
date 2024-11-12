#include <functional>

void deleteAllItems(int); // <- функция, которую нужно вызвать

std::function<void(int)> foo; // <- функтор

foo = deleteAllItems; // <- создание коллбека

foo(); // <- вызов функции deleteAllItems(int);


https://qna.habr.com/q/377133
