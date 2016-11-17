// Copyright 2016 Alexandr

#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include "list_declaration.h"

template <typename ListDataType>
List<ListDataType>::List() {
    listSize = 0;
    currentNode = 0;
}

template <typename ListDataType>
List<ListDataType>::List(const List<ListDataType>& rhs) {
    listSize = 0;
    currentNode = 0;
    if (rhs.listSize == 0)
        return;
    Node * rTemp = rhs.currentNode;
    Node * pToTail = new Node;
    pToTail->value = rTemp->value;
    currentNode = pToTail;
    listSize++;
    rTemp = rTemp->next;
    while (rTemp != 0) {
        pToTail->next = new Node;
        pToTail = pToTail->next;
        pToTail->value = rTemp->value;
        rTemp = rTemp->next;
        ++listSize;
    }
    pToTail->next = 0;
}

template <typename ListDataType>
List<ListDataType>::~List() {
    Node * temp;
    while (currentNode != 0) {
        temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
}

template <typename ListDataType>
ListDataType & List<ListDataType>::operator[](unsigned int indx) {
    if (indx >= listSize )
        throw "Illigal indexing";
    Node * temp = currentNode;
    for (unsigned int i = 0; i < indx; i++)
        temp = temp->next;
    return temp->value;
}

template <typename ListDataType>
void List<ListDataType>::push(const ListDataType value, int indx) {
    if (indx == -1)
        indx = listSize;
    indx--;
    Node * temp = new Node;
    temp->next = currentNode;
    temp->value = value;

    if (listSize == 0 || indx == -1) {
        currentNode = temp;
        ++listSize;
        return;
    }

    if (indx >= listSize)
        throw "Bad indexating";

    Node * t = new Node;
    t->next = currentNode;

    Node * insertPos = currentNode;
    for (int i = 0; i < indx; i++)
        insertPos = insertPos->next;
    temp->next = insertPos->next;
        insertPos->next = temp;
    ++listSize;
}

template <typename ListDataType>
void List<ListDataType>::removeElem(unsigned int indx) {
    if (indx >= listSize || listSize == 0)
        throw "Illigal indexing";
    Node * willBeRemoved = currentNode;
    for (unsigned int i = 1; i < indx; i++)
        willBeRemoved = willBeRemoved->next;
    if (willBeRemoved == currentNode) {
        currentNode = currentNode->next;
    } else {
        Node * buffer = willBeRemoved;
        willBeRemoved = willBeRemoved->next;
        buffer->next = buffer->next->next;
    }
    delete willBeRemoved;
    listSize--;
}

template <typename ListDataType>
unsigned int List<ListDataType>::getSize() {
    return listSize;
}

template <typename ListDataType>
bool List<ListDataType>::isEmpty() {
    if (listSize == 0)
        return true;
    return false;
}

#endif  // INCLUDE_LIST_H_


