
#include <stdexcept>

typedef struct _node{
    int data;
    struct _node* next;
}node;

node* head = new node{0,NULL};

bool is_empty(){
    return head == NULL;
}

int get_data(int index){
    node* cur_node = head;
    cur_node = cur_node->next;
    for (int i = 0; i < index; i++){    
    // 구현해보세용
    
    }
    int data = cur_node->data;
    return data;
}
void put_data(int index){

    node* pre_node = head;
    node* next_node = head -> next;
    for (int i = 0; i < index; i++){    
    // 구현해보세용
    }
}
void delete_data(int index){
    // 구현해보세요
}


int get_first_data(){
    node* cur_node = head;
    // head 다음에 오는 데이터가 첫번째 데이터
    cur_node = cur_node->next;
    if (cur_node == NULL){
        throw std::out_of_range("error");
    }
    int data = cur_node->data;
    return data;
}

void put_first_data(int data){
    node* pre_node = head;
    node* next_node = head -> next;
    // 새로운 노드 생성 하고 데이터 넣기
    node* cur_node = new node();
    cur_node->data = data;
    // 첫 노드를 새 노드의 다음 노드로 변경하기
    cur_node->next = next_node;
    // 새 노드를 첫 노드로 만들기
    pre_node->next = cur_node;
}

void delete_first_data(){
    node* pre_node = head;
    node* cur_node = head -> next;
    node* next_node = cur_node -> next;
    // 두번째 노드를 첫노드로 변경하기
    // 헤드의 다음 노드로 만들면 됨!
    pre_node->next = next_node;
    // 메모리 지우기
    delete cur_node;
}
