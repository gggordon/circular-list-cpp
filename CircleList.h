#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "Node.h"

class CircularList {
   private:
      Node* head;
      Node* tail;

   public:
      CircularList(){
          head = NULL;
          tail = NULL;
      }

      bool isEmpty(){
         return head == NULL && tail == NULL;
      }

      bool isFull(){
          Node* temp = new Node();
          if(temp == NULL){
             return true;
          }else{
             delete temp;
             return false;
          }
      }

      bool isFront(Node* n){
         return n == head;
      }

      bool isBack(Node* n){
         return n == tail;
      }

      bool isOnlyOneElement(){
         return !isEmpty() && head == tail;
      }

      void insertAtFront(string data){
          if(isFull()){
             cout <<"Unable to insert in full list" << endl;
          }else{
             Node* temp = new Node(data);
             if(isEmpty()){
                head = temp; 
                tail = temp;
                head->setNext(tail);
             }else{
                temp->setNext(head);
                head = temp;
                tail->setNext(head);
             }
          }
      }

      void insertAtBack(string data){
          if(isFull()){
          cout << "List is full, unable to insert" << endl;
          }else{
             Node* temp = new Node(data);
             if(isEmpty()){
                head = temp;
                tail = temp;
                head->setNext(tail);
             }else{
                tail->setNext(temp);
                tail = temp;
                tail->setNext(head);
             }
          }
      }

      void display(){
         if(isEmpty()){
          cout << "List is empty."<<endl;
         }else{
            head->display();
         Node * current = head->getNext();
            while(current != head){
                current->display();
             current = current->getNext();
            }
         }   
      }

      string* deleteFromFront(){
         string* data = NULL;
         if(isEmpty()){
       cout << "List is empty, nothing to delete" << endl;
         } else{
            if(isOnlyOneElement()){
               data = new string(head->getData());
               delete head;
               head = NULL; tail = NULL;
            }else{
               Node* temp = head;
               head = head->getNext();
               tail->setNext(head);
               data = new string(temp->getData());
               delete temp;
            }
         }
         return data;
      }

      string * deleteAtBack(){
          string* data = NULL;
          if(isEmpty()){
              cout << "List is empty, nothing to delete" << endl;
          }else{
              if(isOnlyOneElement()){
                 data = new string(tail->getData());
                 delete tail;
                 tail = NULL; head = NULL;
              }else{
                 Node *current = head;
                 while(current->getNext() != tail){
                    current = current->getNext();
                 }
                 current->setNext(head);
                 data = new string(tail->getData());
                 delete tail;
                 tail = current;
              }
          }
          return data;
      }
      /**
       Searches the list for a node with the search key
       if the search key is found in a node, the node
      is deleted and the value inside the node is returned
       */
      string* remove(string key){
          string * data = NULL;
          if(isEmpty()){
             cout << "Nothing to remove, list is empty" << endl;
          }else{
             if(head->getData() == key){
                data = deleteFromFront();
             }else{
             Node* prev = head;
             Node* current = head->getNext();
             while(current != head){
                //check if current node should be deleted
                if(current->getData() == key){
                    //before deleting, determine where the node is
                    if(isFront(current)){
                        data = deleteFromFront();
                    }else if(isBack(current)){
                        data = deleteFromBack();
                    }else{//node is somewhere in the middle
                        prev->setNext(current->getNext();
                        data = new string(current->getData());
                        delete current;
                    }
                }
                prev = current;
                current = current->getNext();
             }
             }
             
          }
          return data;   
      }
      /**
       Searches the list for a node with a key
       if the node with key exists,
       inserts the data in a node after the node with the search key
      */
      bool insertAfter(string key, string data){
         bool success = false;
         if(isFull()){
            cout << "List is full, unable to insert" << endl;
         }else{
            if(isEmpty()){
               cout << "List is empty, node with search key does not exist" << endl;
            }else{
                if(head->getData() == key){
                   insertAtFront(data);
                   success = true;
                }else{
                   Node *current = head->getNext();
                   while(current != head){
                      if(current->getData() == key){
                          if(isBack(current)){
                              insertAtBack(data);
                              success = true;         
                          }else{
                              Node *temp = new Node(data);
                              temp->setNext(current->getNext();
                              current->setNext(temp);
                              success = true;
                          }
                          break;
                      }
                      current = current->getNext();
                   }
                }
            }

         }

         return success;
      }
      void destroy(){
          while(deleteAtFront()!=NULL);
      }
      ~CircularList(){
          destroy();
      }
};

#endif
