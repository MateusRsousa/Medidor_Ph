
#include "List.h"
#include "Display.h"


#include <Arduino.h>

List::List() {
   head = 0;
}

List::~List() {
  Node* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}



void List::insertAfterLast(float dat, const String& timestamp) {
    Node* p = head;

    if (head == nullptr) {
        // Lista está vazia, o novo nó será a cabeça
        head = new Node(dat, timestamp, nullptr);
    } else {
        // Percorre a lista até o final
        while (p->getNext() != nullptr) {
            p = p->getNext();
        }
        // Insere o novo nó no final
        p->setNext(new Node(dat, timestamp, nullptr));
    }
}


void List::removeAll() {
    while (head != nullptr) { // Enquanto a lista não estiver vazia
        Node* temp = head;     // Armazena o nó atual
        head = head->getNext(); // Avança para o próximo nó
        delete temp;            // Remove o nó atual
    }
}


void List::listAll(Display &display, Clock &clock) {
    Node* aux = head;

    display.clear();

    display.setCursor(8, 0); // Ajuste conforme necessário
         display.print("(lista)");

    while (aux != nullptr) {
        display.setCursor(0, 0);
        display.print(aux->getVal(), 1);


        display.setCursor(0, 1); // Ajuste conforme necessário
        display.print(aux->getTimestamp().c_str());

         

         while (digitalRead(35) == LOW) {
            

            if (digitalRead(18) == HIGH) {
            // Se o botão de saída foi pressionado, sai da função
            return;  // Interrompe a execução da função
             
        }
        }
      delay(500);
        aux = aux->getNext();
       
    }
}