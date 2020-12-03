#ifndef LAB1_LINKEDLIST_H
#define LAB1_LINKEDLIST_H


typedef int value_type;

class LinkedList {
private:
    struct List {
        struct List *next;
        struct List *prev;
        value_type value{};

        List();

        explicit List(value_type &val);

        explicit List(const value_type &val);

    };

    static List *endOfList;
    int curSize = 0;

public:

    class iterator {

        friend class LinkedList;

        List *node;

        explicit iterator(List *element);

    public:
        iterator();

        iterator &operator=(const iterator &other);

        bool operator!=(const iterator &other) const;

        bool operator==(const iterator &other) const;

        //Возвращает ссылку на текущий элемент коллекции.
        value_type &operator*();

        //Возвращает указатель на текущий элемент коллекции.
        value_type *operator->();

        iterator &operator++(); //prefix

        iterator operator++(int); //postfix

        iterator &operator--(); //prefix

        iterator operator--(int); //postfix
    };

    class const_iterator {
        friend class LinkedList;

        const List *constNode;

        explicit const_iterator(List *element);


    public:
        const_iterator();

        const_iterator &operator=(const const_iterator &other);

        bool operator!=(const const_iterator &other) const;

        bool operator==(const const_iterator &other) const;

        //Возвращает ссылку на текущий элемент коллекции.
        const value_type &operator*() const;

        //Возвращает указатель на текущий элемент коллекции.
        const value_type *operator->() const;

        const_iterator &operator++();

        const_iterator operator++(int);

        const_iterator &operator--();

        const_iterator operator--(int);
    };

    /* Конструкторы */
    LinkedList();

    LinkedList(const LinkedList &other);

    LinkedList(LinkedList &&other);

    /* Деструктор */
    ~LinkedList();

    /* Оператор присваивания */
    LinkedList &operator=(const LinkedList &other);

    LinkedList &operator=(LinkedList &&other);

    /* Доступ к итераторам */
    //Возвращает итератор, указывающий на первый элемент списка.
    iterator begin();

    const_iterator begin() const;

    const_iterator cbegin() const;

    //Возвращает итератор, указывающий на элемент списка, следующий за последним
    //т.е. отсутствующий в списке.
    iterator end();

    const_iterator end() const;

    const_iterator cend() const;

    /* Размерность */
    //Возвращает размер списка.
    int size() const;

    //Возвращает истину, если список пуст.
    bool empty() const;

    /* Доступ к элементам */
    //Возвращает ссылку на первый элемент списка.
    value_type &front();

    const value_type &front() const;

    //Возвращает ссылку на последний элемент списка.
    value_type &back();

    const value_type &back() const;

    /* Модификаторы */
    //Удаляет элемент, на который указывает итератор pos.
    iterator erase(iterator position);

    //Удаляет элементы в интервале [begin, end).
    iterator erase(iterator begin, iterator end);

    //Удаляет все вхождения value в список.
    int remove(const value_type &value);

    //Очищает список.
    void clear();

    //Удаляет последний элемент списка.
    void pop_back();

    //Удаляет первый элемент списка.
    void pop_front();

    //Добавляет значение value в конец списка.
    void push_back(const value_type &value);

    //Добавляет значение value в начало списка.
    void push_front(const value_type &value);

    //Вставляет значение value перед элементом, на который указывает before
    iterator insert(iterator before, const value_type &value);

    /* Операторы внутренние */
    //Присоединяет other к списку.
    LinkedList &operator+=(const LinkedList &other);

    /* Операторы внешние */
    friend bool operator!=(const LinkedList &left, const LinkedList &right);

    friend bool operator==(const LinkedList &left, const LinkedList &right);

};

/* Операторы внешние */
//Сравнивает 2 листа
bool operator!=(const LinkedList &left, const LinkedList &right);

bool operator==(const LinkedList &left, const LinkedList &right);

//Возвращает лист объединяющий 2 листа.
LinkedList operator+(const LinkedList &left, const LinkedList &right);


#endif //LAB1_LINKEDLIST_H
