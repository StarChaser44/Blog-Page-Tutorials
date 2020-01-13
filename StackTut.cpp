#include <iostream>
using namespace std;

class Stack {
    struct book {
        struct book* next;
        int val;
    };
    struct book *top;
    public:
    Stack(int num){
        top = createNode(num);
    }

    struct node* createNode(int num){
        struct book* newBook = new book;
        book->val = num;
        book->next = NULL;
        return newBook;
    }

    void push(int num){
        struct newNode = createNode(num);
        newNode->next = top; // point to the top of the stack
        top = newNode; // Update top
    }
    void pop(){
        struct book* temp = top;
        top = top->next; // Advance top 
        delete temp; // remove the old top
    }
    void peek() {
        return top->val;
    }
};

int main(){


    return 0;
}
