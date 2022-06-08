#include <iostream>

using namespace std;

struct Node{
    string value;
    Node* next;

    Node(string val) : value(val), next(nullptr) {}
};

class SinglyLinkedList{
    Node* first;
    Node* last;
    public:
    SinglyLinkedList() : first(nullptr), last(nullptr) {}

    bool isEmpty(){
        return first==nullptr;
    }
    void push_back(string value){
        Node* current = new Node(value);
        if(isEmpty()){
            first = current;
            last = current;
            return;
        }
        last->next=current;
        last=current;
    }
    void print()
    {
        if(isEmpty()) 
        {
            cout << "Список пустой!" << endl;
            return;
        }
        Node* current = first;
        while(current)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;

    }
    void moveThirdElementToFirst(){
        if(isEmpty()) {
            cout << "Список пустой!" << endl;
            return;
        }
        cout << "Перенос третьего элемента\n";
        
        int count = 0;
        bool isFound = false;
        Node* thirdElement = nullptr;
        Node* nextElement = nullptr;
        Node* current = first;
        
        while(current && !isFound){            //Поиска самого элемента и все сопутствующих данных: ссылка на этот элемент и ссылка, которую хранит сам элемент
            count++;
            if(count == 3)
            {
                isFound = true;
                thirdElement = current;
                nextElement = current->next;
                break;
            }
            current = current->next;
        }
        if(!isFound){
            cout << "Третий элемент отсутствует\n";
            return;
        }
        //Начинаем переносить элемент
        //Для этого делаем первым элементом третий, который мы и искали
        //и сохраняем предыдущий первый элемент, чтобы на него установить ссылку, и он уже станет вторым
        current = first;
        first = thirdElement;           
        first->next=current;

        current = first;  //теперь мы начинаем с начала нового списка, доходим до третьего элемента(бывшего второго) и ставим ссылку на след. элемент
        count = 0;
        while(current)
        {
            count++;
            if(count==3){
                current->next=nextElement;
                break;
            }
            current = current->next;
        }
        cout << "Успешно" << endl;
        return;
    } 
};
int main()
{
    cout << "Заполнения списка... \nВведите '-', чтобы остановиться\n";
    // При желании оформишь тут все покрасивее, но вроде нормально
    // В самом списке у нас стринги, так что вводить можешь все, что угодно: цифры, числа, слова и тд.
    //вводить каждый элемент на отдельной строке, то есть элемент, затем enter и так до победного
    string value;
    SinglyLinkedList list;
    
    do{
        getline(cin,value); 
        if(value=="-") break;
        if(value!= " ") list.push_back(value);        
    }while(true);
    cout << "Заполнение завершено" << endl;

    list.print();
    list.moveThirdElementToFirst();
    list.print();
    
    return 0;
}