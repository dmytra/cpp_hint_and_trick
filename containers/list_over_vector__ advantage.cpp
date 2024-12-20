  #include <list>
  #include <iostream>

//  Какое преимущество у list перед vector?
// https://t.me/easy_c_plus/721

/*
 Основные преимущества `std::list`

 🟠Эффективные вставка и удаление элементов в середине контейнера
 std::list реализован как двусвязный список, что позволяет эффективно вставлять и удалять элементы в любом месте контейнера за постоянное время O(1), если у вас уже есть итератор на нужное место.
 
 🟠Нет необходимости в перемещении элементов при вставке или удалении
 В std::vector при вставке или удалении элементов в середине контейнера происходит сдвиг элементов, что может быть дорогостоящей операцией (сложность O(n)). В std::list этого не происходит, так как элементы не хранятся в смежных блоках памяти.

 🟠Постоянное время для операций вставки и удаления в произвольной позиции
 Операции вставки и удаления в произвольной позиции в std::list всегда выполняются за O(1) (при условии, что у вас есть итератор на эту позицию), в то время как в std::vector они могут занимать до O(n) из-за необходимости сдвига элементов.

 🟠Итераторы не инвалидируются при вставке или удалении элементов
 В std::vector итераторы могут быть инвалидированы (становятся недействительными) при вставке или удалении элементов. В std::list итераторы остаются валидными, что делает работу с итераторами более безопасной и предсказуемой.

 🚩Примеры, когда `std::list` предпочтительнее

 🟠Частые вставки и удаления в середине контейнера
 Если ваша задача предполагает частые операции вставки и удаления в середине контейнера, std::list будет предпочтительнее из-за своей эффективности в этих операциях.

 🟠Работа с большим количеством итераторов
 Если вам нужно работать с множеством итераторов, которые должны оставаться валидными даже после вставки или удаления элементов, std::list будет лучше подходить для таких задач.

 🚩Ограничения `std::list`

 🟠Доступ по индексу
 В отличие от std::vector, в std::list нет возможности быстрого доступа к элементам по индексу. Для доступа к элементу необходимо пройти весь список от начала до нужного элемента (сложность O(n)).

 🟠Высокие накладные расходы на память
 std::list требует больше памяти на хранение элементов, так как для каждого элемента хранится два дополнительных указателя (на следующий и предыдущий элементы).

 
 */


  int main() {
      std::list<int> myList = {1, 2, 3, 4, 5};
      auto it = myList.begin();
      std::advance(it, 2); // Переместить итератор на третий элемент

      myList.insert(it, 10); // Вставка за O(1)
      myList.erase(it);      // Удаление за O(1)

      for (int n : myList) {
          std::cout << n << " ";
      }

      return 0;
  }

