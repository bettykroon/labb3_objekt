#ifndef header_h
#define header_h
#include <iostream>
#include <new>

using namespace std;

class linked_list {
    public:
    linked_list();
    linked_list(const linked_list& src);

    ~linked_list();

    linked_list& operator=(const linked_list& rhs);
    linked_list& operator+=(const linked_list& rhs);

    void insert(double value, size_t pos);
    void push_front(double value);
    void push_back(double value);
    double front() const;
    double back() const;
    double at(size_t pos) const;

    void remove(size_t pos);
    double pop_front();
    double pop_back();

    size_t size() const;
    bool is_empty() const;

    void print() const;
    void print_reverse() const;
    
    //användna funktioner
	friend void print_list(linked_list &lista) {lista.print();}
	linked_list merge(linked_list &lista1, linked_list &lista2);
	void sort(linked_list lista1);
    

    private:
    struct node_t
    {
        node_t(double value, node_t* next=0, node_t* prev=0);
        double value;
        node_t* next;
        node_t* prev;
    };
    node_t* head;
    node_t* tail;
};
#endif 
