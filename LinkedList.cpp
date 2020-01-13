#include <iostream>
using namespace std;

class LinkedList {
    struct person {
        struct person* next;
        int val;
    };

    struct person* head;
    public:

    LinkedList(int data){
        head = createPerson(data);
    }

    void printList(){
        struct person* temp = head;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp ->next;
        }
        cout << endl;
        cout << "====================" << endl;
    }

    struct person* createPerson(int value) {
        struct person *temp=new person;
        temp->val=value;
        temp->next=NULL;
        return temp;
    };

    void appendPerson(int data){
        struct person *temp = createPerson(data);
        struct person *curr = head; // Pointer to head

        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    };

    void insertBeginning(int data){
        struct person* temp = createPerson(data);
        temp->next = head;
        head = temp; // This step is important
    };

    void insertPosition(int pos, int value) {

        struct person *pre = new person;

        struct person *cur = new person;

        struct person *temp= createPerson(value);

        cur=head;

        for(int i = 1; i < pos; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = temp;
        temp->next = cur;
    };

    void deleteBeginning(){

        struct person* temp = new person;

        temp = head;

        head = head->next;

        delete temp;
    };

    void deleteLast() {

        struct person *current=new person;

        struct person *previous = new person;

        current = head;

        while(current->next!=NULL) {

            previous=current;

            current=current->next;

        }
        previous->next=NULL;

        delete current;
    };

    void deletePos(int pos){

        struct person *current = new person;

        struct person *previous = new person;

        current = head;

        for(int i = 1; i < pos; i++) {

            previous = current;

            current = current->next;

        }

        previous->next=current->next;

        delete current;

    };

    void reverse(){

        struct person *current = head;

        struct person *prev = NULL;

        struct person *next = NULL;           

        while (current != NULL) {

            next = current->next;

            current->next = prev;

            prev = current;             

            current = next;         

        }         
        head = prev; //Move head to the end of the list     
};

};
int main() {
    LinkedList* list = new LinkedList(8);
    
    return 0;
}
