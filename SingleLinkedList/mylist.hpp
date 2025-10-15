#ifndef MYLIST_HPP
#define MYLIST_HPP
#include <iostream>
#include <vector>

class SingleList{
    private:
            struct Node{
                int val;
                Node* next;
                Node(int _val = 0, Node* _next = nullptr): val{_val}, next{_next}{}
            };
            Node* head;
            void copy(const SingleList& oth);
    public:
           SingleList():head{nullptr}{};
           SingleList(int count, int _val);
           SingleList(std::initializer_list<int> init);
           SingleList(const SingleList& oth);
           SingleList(SingleList&& oth);
           ~SingleList();
           void clear();
           SingleList& operator=(const SingleList& oth);
           SingleList& operator=(SingleList&& oth);
           SingleList operator+(const SingleList& oth)const;
           SingleList& operator+=(const SingleList& oth);
           bool operator==(const SingleList& oth)const;  
           bool operator!=(const SingleList& oth)const;      
           int& operator[](size_t index);
           friend std::ostream& operator<<(std::ostream& os, const SingleList& l);
           friend std::istream& operator>>(std::istream& is, SingleList& l);
           bool operator!()const;
           SingleList& operator++();
           SingleList operator++(int);
           SingleList& operator--();
           SingleList operator--(int);
           operator bool()const;
           operator std::vector<int>()const;
           void push_front(int _val);
           void push_back(int _val);
           void pop_front();
           void pop_back();
           size_t size()const;

};

#endif