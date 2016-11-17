// Copyright 2016 Alexandr

#ifndef INCLUDE_LIST_DECLARATION_H_
#define INCLUDE_LIST_DECLARATION_H_

template<typename ListDataType>
class List {
 protected:
    struct Node {
        ListDataType value;
        Node * next;
    };
    Node * currentNode;
    unsigned int listSize;
 public:
    List();
    List(const List & rhs);
    ~List();

    ListDataType & operator[](unsigned int indx);
    List & operator=(const List & rhs);

    unsigned int getSize();
    bool isEmpty();

    void push(const ListDataType value, int indx = -1);
    void removeElem(unsigned int indx);
};
#endif  // INCLUDE_LIST_DECLARATION_H_
