#include "linked_list.hpp"
#include <iostream>
int main()
{
    LinkedList<int> linked_list;
    linked_list.insert(0, 1);
    linked_list.insert(0, 2);
    linked_list.insert(0, 3);
    std::cout << linked_list.get(0) << std::endl;
    std::cout << linked_list.get(1) << std::endl;
    std::cout << linked_list.get(2) << std::endl;
    try {
        std::cout << linked_list.get(3);
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
    linked_list.erase(2);
    std::cout << linked_list.get(1) << std::endl;
}