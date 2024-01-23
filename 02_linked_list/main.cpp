#include "linked_list.hpp"
#include <iostream>
int main(){
    put_first_data(1);
    std::cout << get_first_data()<<std::endl;
    put_first_data(2);
    std::cout << get_first_data()<<std::endl;
    put_first_data(3);
    std::cout << get_first_data()<<std::endl;
    delete_first_data();
    std::cout << get_first_data()<<std::endl;
    // 정상적으로 출력되면 1이 나와야 하지만 지금은 첫번째 데이터인 2 가 나와요
    std::cout << get_data(1)<<std::endl;
}
