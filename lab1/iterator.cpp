#include "LinkedList.h"

LinkedList::iterator::iterator() {
    this->node = nullptr;
}

LinkedList::iterator::iterator(LinkedList::List *element) {
    this->node = element;
}

LinkedList::iterator &LinkedList::iterator::operator=(const LinkedList::iterator &other) {
    this->node = other.node;
    return *this;
}

bool LinkedList::iterator::operator!=(const LinkedList::iterator &other) const {
    return (this->node != other.node);
}

bool LinkedList::iterator::operator==(const LinkedList::iterator &other) const {
    return (this->node == other.node);
}

value_type &LinkedList::iterator::operator*() {
    return this->node->value;
}

value_type *LinkedList::iterator::operator->() {
    return &(this->node->value);
}

LinkedList::iterator &LinkedList::iterator::operator++() {
    this->node = node->next;
    return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int) {
    LinkedList::iterator iterator1 = LinkedList::iterator(this->node);
    this->node = node->next;
    return iterator1;
}

LinkedList::iterator &LinkedList::iterator::operator--() {
    this->node = node->prev;
    return *this;
}

LinkedList::iterator LinkedList::iterator::operator--(int) {
    LinkedList::iterator iterator1 = LinkedList::iterator(this->node);
    this->node = node->prev;
    return iterator1;
}

LinkedList::iterator LinkedList::begin() {
    return LinkedList::iterator(LinkedList::endOfList->next);
}

LinkedList::iterator LinkedList::end() {
    return LinkedList::iterator(endOfList);
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator position) {
    LinkedList::iterator temp;

    temp = LinkedList::iterator(position.node->next);
    temp.node->prev = position.node->prev;
    temp.node->prev->next = temp.node;

    delete position.node;
    curSize--;

    return temp;
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {
    while (begin != end)
        begin = erase(begin);

    return begin;
}

LinkedList::iterator LinkedList::insert(LinkedList::iterator before, const value_type &value) {

    List *tempList = new List(value);
    tempList->next = before.node;
    tempList->prev = before.node->prev;
    tempList->prev->next = tempList;
    curSize++;

    before.node->prev = tempList;

    return LinkedList::iterator(tempList);
}













