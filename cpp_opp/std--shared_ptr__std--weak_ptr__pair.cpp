 #include <iostream>
 #include <memory>


// https://t.me/easy_c_plus/634

//В чем отличие weak_ptr от shared_ptr?
// https://t.me/easy_c_plus/637
/*
 #include <iostream>
 #include <memory>

 class Example {
 public:
     Example() { std::cout << "Object created" << std::endl; }
     ~Example() { std::cout << "Object destroyed" << std::endl; }
 };

 int main() {
     std::shared_ptr<Example> sptr = std::make shared<Example>();
     std::weak_ptr<Example> wptr = sptr;

     std::cout << "Shared count: " << sptr.use_count() << std::endl;  // Счетчик ссылок: 1

     if (auto locked = wptr.lock()) {  // Проверка существования объекта через weak_ptr
         std::cout << "Object is still alive" << std::endl;
     } else {
         std::cout << "Object is no longer available" << std::endl;
     }

     sptr.reset();  // Освобождаем shared_ptr, объект будет удален

     if (auto locked = wptr.lock()) {
         std::cout << "Object is still alive" << std::endl;
     } else {
         std::cout << "Object is no longer available" << std::endl;
     }

     return 0;
 }

 */

 class Node {
 public:
     std::shared_ptr<Node> next;
     std::weak_ptr<Node> prev;  // Слабая ссылка на предыдущий элемент

     ~Node() {
         std::cout << "Node destroyed" << std::endl;
     }
 };

 int main() {
     auto node1 = std::make_shared<Node>();
     auto node2 = std::make_shared<Node>();

     node1->next = node2;
     node2->prev = node1;  // Используем weak_ptr, чтобы избежать циклической зависимости

     return 0;
 }

