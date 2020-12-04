
#include "LinkedList.h"


LinkedList::List::List() {
    value = value_type();
    next = nullptr;
    prev = nullptr;
}

LinkedList::List::List(value_type &val) {
    value = val;
    next = nullptr;
    prev = nullptr;
}

LinkedList::List::List(const value_type &val) {
    value = val;
    next = nullptr;
    prev = nullptr;

}


LinkedList::LinkedList() {
    listEnd = new List();
    listEnd->next = listEnd;
    listEnd->prev = listEnd;
}

LinkedList::LinkedList(const LinkedList &other) {

    listEnd = new List();
    for (List *i = other.listEnd->next; i != other.listEnd->prev; i = i->next) {
        push_back(i->value);
    }
    curSize = other.curSize;

}

LinkedList::LinkedList(LinkedList &&other) {
    listEnd = new List();

    *this = other;
    curSize = other.curSize;

    other.listEnd->next = nullptr;
    other.listEnd->prev = nullptr;
    other.curSize = 0;
}

LinkedList::~LinkedList() { // нужно зациклить
    while (listEnd != listEnd->next) {
        List *temp = listEnd->next;
        delete listEnd;
        listEnd = temp;
    }
}

LinkedList &LinkedList::operator=(const LinkedList &other) {

    this->clear();

    for (auto i = other.listEnd->next; i != other.listEnd; i = i->next)
        this->push_back(i->value);

    return *this;
}

LinkedList &LinkedList::operator=(LinkedList &&other) {
    this->clear();

    this->listEnd = other.listEnd;

    other.listEnd = nullptr;
    other.curSize = 0;

    return *this;

}

int LinkedList::size() const {
    return (curSize);
}

bool LinkedList::empty() const {
    return (curSize == 0);
}

value_type &LinkedList::front() {
    return *begin();
}

const value_type &LinkedList::front() const {
    return *cbegin();
}

value_type &LinkedList::back() {
    end()--;
    return *end();
}

const value_type &LinkedList::back() const {
    cend()--;
    return *cend();
}


int LinkedList::remove(const value_type &value) {
    for (iterator i = begin(); i != end(); i++)
        if (*i == value) {
            erase(i);
            curSize--;
        }

    return 0;
}

void LinkedList::clear() {
    for (iterator i = begin(); i != end(); i++) {
        erase(i);
        curSize--;
    }
}

void LinkedList::pop_back() {
    LinkedList::iterator i = end();
    end()--;

    erase(i);
}

void LinkedList::pop_front() {
    LinkedList::iterator i = begin();
    erase(i);
}

void LinkedList::push_back(const value_type &value) {
    LinkedList::iterator i = end();
    insert(i, value);
}

void LinkedList::push_front(const value_type &value) {
    LinkedList::iterator i = begin();
    insert(i, value);
}

LinkedList &LinkedList::operator+=(const LinkedList &other) {
    for (auto cur = other.listEnd->next; cur != other.listEnd; cur = cur->next)
        push_back(cur->value);

    return (*this);
}

/*
bool operator!=(const LinkedList &left, const LinkedList &right) {
    LinkedList::const_iterator curLeft = left.begin();
    LinkedList::const_iterator curRight = right.begin();

    while (curLeft-> value == curRight -> value) {
        if (curLeft == left.end() && curRight == right.end())
            return false;
        curLeft++;
        curRight++;
    }

    return true;
}
*/

bool operator!=(const LinkedList &left, const LinkedList &right) {
    auto curLeft = left.listEnd->next;
    auto curRight = right.listEnd->next;

    while (curLeft->value == curRight->value) {
        if ((curLeft == left.listEnd && curRight == right.listEnd)) return false;
        curLeft++;
        curRight++;
    }
    return true;
}

bool operator==(const LinkedList &left, const LinkedList &right) {
    return !(left != right);
}

LinkedList operator+(const LinkedList &left, const LinkedList &right) {
    auto *newList = new LinkedList(left);
    *newList += right;
    return *newList;
}










