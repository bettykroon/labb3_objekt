#include "header.h"

using namespace std;

linked_list::linked_list()
{
    head = nullptr;
    tail = nullptr;
}

linked_list::~linked_list()
{
	node_t *nuvarande = head;
	
    while (nuvarande != nullptr)
    {
        pop_front();
        nuvarande = nuvarande->next;
    }
}

linked_list::linked_list(const linked_list& src)
{
	head = nullptr;
	tail = nullptr;

	for (node_t *ptr = src.head; ptr != nullptr; ptr = ptr->next)
		push_back(ptr->value);	
}

linked_list& linked_list::operator=(const linked_list &rhs)
{
	size_t i = 1;
	
	if (this == &rhs)
		return *this;

	for (node_t* tmp = rhs.head; tmp != nullptr; tmp = tmp->next)
	{
		this->push_back(rhs.at(i));
		i++;
	}
	return *this;
}

linked_list& linked_list::operator+=(const linked_list& rhs)
{
	size_t  i = 1;
	for (node_t* tmp = rhs.head; tmp != nullptr; tmp = tmp->next)
	{
		tmp->value += rhs.at(i);
		this->push_back(tmp->value);
		i++;
	}
	return *this;
}

linked_list::node_t::node_t(double value, node_t *next, node_t *prev)
{
    this->value = value;
    this->next = next;
    this->prev = prev;
}

void linked_list::push_back(double value)
{
    node_t *pBack = new node_t(value);

    if (head == nullptr)
    {
        head = pBack;
        tail = pBack;
    }

    else
    {
        tail->next = pBack;
        pBack->prev = tail;
        tail = pBack;
        tail->next = nullptr;
    }
}

void linked_list::push_front(double value)
{
	node_t *pFront = new node_t(value);
    
	if (head == nullptr)
    {
        head = pFront;
        tail = pFront;
		return;
    }
	head->prev = pFront;
	pFront->next = head;
	head = pFront;
	return;
}

void linked_list::insert(double value, size_t pos)
{
    node_t *tmp = head;

    if (is_empty() == true)
    {
        push_front(value);
        return;
    }
    else
    {
        for (size_t i = 1; i <= size(); i++)
        {
            if (i == pos)
            {
                if (pos == 1)
                {
                    push_front(value);
                    return;
                }
                else if (i == size())
                {
                    push_back(value);
                    return;
                }
                else
                {
                    node_t *newnode = new node_t(value);
                    node_t *left = tmp->prev;

                    newnode->prev = left;
                    left->next = newnode;

                    tmp->prev = newnode;
                    newnode->next = tmp;
					return;
                }
            }
            tmp = tmp->next;
        }
    }
}

double linked_list::at(size_t pos) const
{
   node_t *ptr = head;
   double  thatValue = 0;
   size_t counter = 1;
   
   if (is_empty() == true)
	   return 0;
   else
   {
	   while (ptr != nullptr)
	   {
		   if (pos == counter)
		   {
			   linked_list tmp;
			   thatValue = ptr->value;
			   return thatValue;
		   }
		   ptr = ptr->next;
		   counter++;
	   }
   }
   return 0;
}

double linked_list::back() const
{
	double sistaVärdet = 0;

	if (size() == 0)
	{
		return 0;
	}
	node_t* b_value = tail;
	sistaVärdet = b_value->value;  

    return sistaVärdet;
}

double linked_list::front() const
{
	double förstaVärdet = 0;

	if (size() == 0)
		return 0;

    node_t *f_value = head;
	förstaVärdet = f_value->value;

    return förstaVärdet;
}

size_t linked_list::size() const
{
    node_t *storlek = head;
    size_t count = 0;

    while (storlek != nullptr)
    { 		
        storlek = storlek->next;
       count++;
    }
    return count;
}

bool linked_list::is_empty() const
{
    if (size() == 0)
        return true;
    return false;
}

void linked_list::remove(size_t pos)
{
    node_t *advance = head;
    if (size() == 0)
        cout << "Error" << endl;

    else if (size() != 0)
    {
        for (size_t i = 1; i <= size(); i++)
        {
            if (i == pos)
            {
                node_t *left = advance->prev;
                node_t *right = advance->next;

                advance->next = nullptr;
                advance->prev = nullptr;

                left->next = right;
                right->prev = left;

                delete advance;
                return;
            }
            advance = advance->next;
        }
    }
}

double linked_list::pop_front()
{
	node_t* first = head;
	double förstaVärdet = 0;

    if (is_empty() == true)
    {
		cout << "Hittade ingen lista..." << endl;
		return 0;
    }
	
	förstaVärdet = front();
	
	head = head->next;
	delete first;

	return förstaVärdet;
}

double linked_list::pop_back()
{
	double SistaVärdet = 0;
	node_t* last = tail;

	if (is_empty() == true)
		return SistaVärdet;
    
	SistaVärdet = last->value;
	
	tail = tail->prev;
	tail->next = nullptr;
	delete last;
    return SistaVärdet;
}

void linked_list::print()const
{
    if (is_empty() == true)
    {
        cout << "Hittade ingen lista.." << endl;
        return;
    }
	else
	{
		for (node_t* tmp = head; tmp != nullptr; tmp = tmp->next)
		{
			cout << tmp->value << " ";
		}
	}
}

linked_list linked_list::merge(linked_list &lista1, linked_list &lista2)
{
		while (!lista1.is_empty() && !lista2.is_empty())
		{
			if (lista1.front() <= lista2.front())
				push_back(lista1.pop_front());
			else if (lista1.front() >= lista2.front())
				push_back(lista2.pop_front());
		}
		while (!lista1.is_empty())
			push_back(lista1.pop_front());
		while (!lista2.is_empty())
			push_back(lista2.pop_front());
	return *this;
}

void linked_list::sort(linked_list lista)
{	
	bool sorterad = true;
	double nuvarande;
	
	for (size_t i=1; i<=size(); i++)
	{
		nuvarande = lista.at(i);
		
		if (nuvarande < lista.at(i++))
		{
			sorterad = true;
			break;
		}	
	}
	if (sorterad == true)
		cout << "Listan är sorterad!" << endl;
	else
		cout << "Listan är inte sorterad!" << endl;
}