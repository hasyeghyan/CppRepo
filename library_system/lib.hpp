#ifndef LIB_HPP
#define LIB_HPP

#include <iostream>
#include <vector>
#include <string>
#include "u_ptr.hpp"
#include "sh_ptr.hpp"

class Author{
    private:
        std::string name;
    public:
        Author(std::string n = "Isahakyan") noexcept : name{n} {}
        std::string getname()const noexcept{return name;}
};

class Book{
    private:
        int id;
        std::string title;
        std::vector<sh_ptr<Author>> authors;
    public:
        Book(int id, std::string title, const sh_ptr<Author>& author) noexcept;
        std::vector<sh_ptr<Author>>& getauthors()noexcept{return authors;}
        std::string getTitle()const noexcept{return title;}
        int getid()const noexcept{return id;}
};

class Shelf{
    private:
        std::vector<u_ptr<Book>> books;
    public:
        std::vector<u_ptr<Book>>& getbooks(){return books;}
};

class Library{
    private:
        std::vector<u_ptr<Shelf>> shelves;
    public:
        void add();
        void remove(size_t index);
        void add(size_t index,int id, std::string title, std::string name);
        void remove(std::string title);
        Book* find(std::string title);
        void movebook(int index,std::string title);
        void replace(int id);
        void count(std::string name);
};

#endif