#include <iostream>

using namespace std;
class PrintItem {
public:
    string fileName;
    float fileSize;
    PrintItem(string fileName, float fileSize) {
        this->fileSize = fileSize;
        this->fileName = fileName;
    }
    void print() {

        cout << fileName << " " << endl;
        cout << fileSize<< " " << endl;
    }
    ~PrintItem(){
        fileName = "";
        fileSize = 0;
    }


};

template <typename T> class Node {
public:
    T *data;
    Node<T> *nextNode;


    Node(T *data) {
        this->data = data;
        nextNode = nullptr;
    }
    void print() { data->print();}
    ~Node(){
        delete data;
        delete nextNode;
    }

};

template <typename T> class LLStack{
private:
    int stackSize;
    const int SMAXITEMS =10;
    //Node<T> *tail; //do i need this?
    Node<T>* top;
public:
    LLStack(T *value) {
        Node<T> *newNode = new Node<T>(value);
        top = newNode;
        stackSize = 1;
    }

    LLStack(){
        top = nullptr;
        stackSize = 0;
    }

    //LLStack(int max) : top(nullptr),stackSize(0), SMAXITEMS(max){}

    ~LLStack() {
        while (top) {
            Node<T> *temp = top;
            top = top->nextNode;
            delete temp;
        }
    }

    bool IsFull(){
        if (stackSize >= SMAXITEMS){

            return true;
        }
        else{
            return false;
        }
    }
    bool IsEmpty(){
        if (stackSize <=0){

            return true;
        }
        else{
            return false;
        }
    }
    void push(T* item){
        if (stackSize < SMAXITEMS){
            Node<T> *temp = new Node<T>(item);
            temp->nextNode = top;
            top = temp;
            stackSize++;
        }
        else{
            cout<<"Error: The stack is full you cannot add anymore items."<<endl;
        }
    }
    void pop(){
        if(stackSize > 0){
            Node<T>* temp = top;
            top = top->nextNode;
            stackSize--;

        }
        else{
            cout<<"Error: The stack is empty, there is nothing to pop."<<endl;
        }

    }
    T* peek(){
        if(stackSize > 0 && stackSize < SMAXITEMS){
            T *val = top->data;
            return val;
        }else{
            cout<<"Error: There is nothing to display";
        }
    }
    void print(){
        Node<T>* curr = top;
        while(curr != nullptr){
            curr->print();
            curr = curr->nextNode;
        }
    }

    Node<T> *getTop(){
        return top;
    }

};
template <typename T> class StackQ {
private:

    LLStack<T> enQStack;
    LLStack<T> deQStack;
    int queueSize;
    const int QMAXITEMS = 10;

public:
    StackQ() {
        queueSize = 0;
        enQStack = new LLStack<T>(QMAXITEMS);
        deQStack = new LLStack<T>(QMAXITEMS);

    }

    StackQ(T *item){
        queueSize = 1;
        enQStack.push(item);
    }

    ~StackQ(){
        delete enQStack;
        delete deQStack;
    }

    bool IsFull() {
        if ( queueSize == QMAXITEMS) {
            return true;
        } else {
            cout<<"The Queue is not full."<<endl;
            return false;
        }
    }
    bool IsEmpty(){
        if(queueSize == 0){

            return true;
        }
        else
            return false;
    }
    void enqueue(T *item){

        if(queueSize ==QMAXITEMS){
            cout<<"Error: The queue is full."<<endl;
        } else{
            enQStack.push(item);
            queueSize++;
        }
    }

    int getQueueSize(){
        return queueSize;
    }
/*    void dequeue(){
        if(IsEmpty()){

            return;
        }
        if (deQStack.IsEmpty()){
            while(!enQStack.IsEmpty()){
                T* value = enQStack.peek();
                enQStack.pop();
                deQStack.push(value);
            }

        }
        deQStack.pop();
        queueSize--;
    }*/
    void dequeue(){
        if(queueSize > 0){
            if(deQStack.IsEmpty()) {
                while (!enQStack.IsEmpty()) {
                    T *value = enQStack.peek();
                    enQStack.pop();
                    deQStack.push(value);
                }
                deQStack.pop();
                queueSize--;
            }

            else{
                cout<<"Error: The enQStack is empty, there is nothing to dequeue."<<endl;
            }
        }
    }
    T* peek() {
        if(queueSize >  0){
            if (deQStack.IsEmpty()) {
                while (!enQStack.IsEmpty()) {
                    //PrintItem *val = enQStack.peek(); // similar problem with dequeue
                    //enQStack.pop();
                    //deQStack.push(val);// returning reference
                    T *value = enQStack.peek();

                    enQStack.pop();
                    deQStack.push(value);
                }
            }
            return deQStack.peek();
        }
        else{
            cout<<"Error: There is nothing to peek."<<endl;
            return nullptr;
        }
    }


    void printQ(){
    cout<<"Here is the full queue: "<<endl;
    enQStack.print();
    deQStack.print();
    }


/*    void printQ(){
        cout << "Here is the current queue: " << endl;
        Node<T>* current = deQStack.getTop();
        while (current != nullptr) {
            current->data->print();
            current = current->nextNode;
        }
        current = enQStack.getTop();
        while (current != nullptr) {
            current->data->print();
            current = current->nextNode;
        }
    }*/

/*    void printEQandDQ(){
        cout << "This is the enQStack: " << endl;
        Node<T>* current = enQStack.getTop();
        while (current != nullptr) {
            current->data->print();
            current = current->nextNode;
        }

        cout << "This is the deQStack:"  << endl;
        current = deQStack.getTop();
        while (current != nullptr) {
            current->data->print();
            current = current->nextNode;
        }
    }*/
    void printEQandDQ() {
        cout << "This is the enQStack: " << endl;
        enQStack.print();
        cout<<"This is the deQStack: "<<endl;
        deQStack.print();
    }



};

int main() {
    PrintItem *p1 = new PrintItem("AXO", 1);
    PrintItem *p2 = new PrintItem("APHI", 2);
    PrintItem *p3 = new PrintItem("GPHI", 3);
    PrintItem *p4 = new PrintItem("DG", 4);
    PrintItem *p5 = new PrintItem("PIPHI", 5);
    PrintItem *p6 = new PrintItem("PIKE", 6);
    PrintItem *p7 = new PrintItem("SIGEP", 7);
    PrintItem *p8 = new PrintItem("KSIG", 8);
    PrintItem *p9 = new PrintItem("PHIPSI", 9);
    PrintItem *p10 = new PrintItem("SAE", 10);

/*    LLStack<PrintItem> *stack1 = new LLStack(p1);


    stack1->push(p2); //works
    stack1->push(p3); //works
    stack1->push(p4); //works
    stack1->push(p5);*/ //works

    //stack1->IsFull(); //works
    //cout<<stack1->peek(); //works
/*
    stack1->IsEmpty(); //works
    stack1->print(); //works
    stack1->pop(); // works
    stack1->pop(); //works
    stack1->pop(); //works */
    //stack1->print(); //works



    //StackQ<PrintItem> *printQueue = new StackQ(p1);
    //printQueue->IsEmpty(); //works
    //printQueue->IsFull(); //works
    //cout<<printQueue->getQueueSize(); // works
    //printQueue->enqueue(p2); // works
    //printQueue->enqueue(p3); // works

    //printQueue->dequeue(); //works
    //printQueue->printQ(); // works
    //cout<<printQueue->peek(); // works


    //main method for user

    StackQ<PrintItem> *printQueue = new StackQ(p1);
    printQueue->enqueue(p2);
    printQueue->enqueue(p3);
    printQueue->enqueue(p4);
    printQueue->enqueue(p5);

    int input = 0;
    cout<<"Hello, you can edit this queue as you would like."<<endl
    <<"The queue is already preloaded with 5 items and it has a max capacity of 10 items."<<endl;
    printQueue->printQ();
    cout<<"Read the given options and type an integer in the given ranges to perform its function."<<endl;


    cout<<"1 -> Add an item to the print queue."<<endl
    <<"2 -> Delete an item from the print queue."<<endl
    <<"3 -> Peek from the print queue."<<endl
    <<"4 -> Display the print queue." <<endl
    <<"5 -> Display the print queue size." <<endl
    <<"6 -> Display enQStack and deQStack." <<endl
    <<"7 -> To exit the program."<<endl
    <<endl;

    int numToAdd = 0;
    bool con = true;
    while(con){
        cin>>input;
        switch(input){
            case 1:
                cout<<"Choose a number between 1-5 to add some data into the queue."<<endl;
                cin >>numToAdd;
                if(numToAdd == 1) {
                    printQueue->enqueue(p6);
                    cout<<"Item has been enqueued."<<endl;
                }else if(numToAdd == 2) {
                    printQueue->enqueue(p7);
                    cout<<"Item has been enqueued."<<endl;
                }else if(numToAdd == 3) {
                    printQueue->enqueue(p8);
                    cout<<"Item has been enqueued."<<endl;
                }else if(numToAdd == 4) {
                    printQueue->enqueue(p9);
                    cout<<"Item has been enqueued."<<endl;
                }
                else if(numToAdd == 5) {
                    printQueue->enqueue(p10);
                    cout<<"Item has been enqueued."<<endl;
                }else
                    cout<<"You did not enter a number between 1-5 to add data into the queue."<<endl;
                break;
            case 2:
                printQueue->dequeue();
                //printQueue->printQ();
                cout<<"Item has been dequeued."<<endl;
                break;
            case 3:
                cout<<"Here is the peek of the Queue: "<<endl;
                cout<<printQueue->peek()->fileName<<endl;
                cout<<printQueue->peek()->fileSize<<endl;
                break;
            case 4:
                printQueue->printQ();
                break;
            case 5:
                cout<< "The queue size is: "<<printQueue->getQueueSize()<<endl;
                break;
            case 6:
                printQueue->printEQandDQ();
                break;
            case 7:
                cout<<"Goodbye, the program has ended."<<endl;
                con = false;
                break;
            default:
                cout<<"Enter a valid number within the range."<< endl;
                break;
        }
    }
    return 0;
};
