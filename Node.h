#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node {
    private:
        string data;
        Node* next;

    public:
        Node():Node(""){}
        Node(string data):Node(data,NULL){}

        Node(string data, Node* next){
            this->data = data;
            this->next = next;
        }

        string getData(){
            return data;
        }

        Node* getNext(){
            return next;
        }

        void setNext(Node* next){
           this->next = next;
        }

        void setData(string data){
           this->data = data;
        }

        void display(){
            cout << "Node [data='" << data << "', next=" << (next == NULL? "null" : "not null") << "]" << endl;
        }
        ~Node(){}
};

#endif
