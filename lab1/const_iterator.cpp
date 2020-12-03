#include "LinkedList.h"

LinkedList::const_iterator::const_iterator() {
    this->constNode = nullptr;
}

LinkedList::const_iterator::const_iterator(LinkedList::List *element) {
    this->constNode = element;
}

LinkedList::const_iterator &LinkedList::const_iterator::operator=(const LinkedList::const_iterator &other) {
    this->constNode = other.constNode;
    return *this;
}

bool LinkedList::const_iterator::operator!=(const LinkedList::const_iterator &other) const {
    return (this->constNode->value != other.constNode->value);
}

bool LinkedList::const_iterator::operator==(const LinkedList::const_iterator &other) const {
    return (this->constNode->value == other.constNode->value);
}

const value_type &LinkedList::const_iterator::operator*() const {
    return this->constNode->value;
}

const value_type *LinkedList::const_iterator::operator->() const {
    return &((*this).constNode->value);
}

LinkedList::const_iterator &LinkedList::const_iterator::operator++() {
    this->constNode = constNode->next;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int) {
    LinkedList::const_iterator iterator1;
    iterator1.constNode = (*this).constNode;
    this->constNode = constNode->next;
    return iterator1;

}

LinkedList::const_iterator &LinkedList::const_iterator::operator--() {
    this->constNode = constNode->prev;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int) {
    LinkedList::const_iterator iterator1;
    iterator1.constNode = this->constNode;
    this->constNode = constNode->prev;
    return iterator1;
}

LinkedList::const_iterator LinkedList::begin() const {
    return LinkedList::const_iterator(endOfList->next);
}

LinkedList::const_iterator LinkedList::cbegin() const {
    return LinkedList::const_iterator(endOfList->next);
}

LinkedList::const_iterator LinkedList::end() const {
    return LinkedList::const_iterator(endOfList);
}

LinkedList::const_iterator LinkedList::cend() const {
    return LinkedList::const_iterator(endOfList);
}
















