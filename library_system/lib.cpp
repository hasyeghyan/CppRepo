#include "lib.hpp"

Book::Book(int id, std::string title, const sh_ptr<Author>& author) noexcept: id{id}, title{title}{
   authors.push_back(author);
}


void Library::add(){
   shelves.push_back(std::move(u_ptr<Shelf>(new Shelf)));
}

void Library::remove(size_t index){
    if(index >= shelves.size()){ 
        std::cout << "Invalid index." << std::endl; 
        return;
    }
    shelves.erase(shelves.begin() + index);      
}

void Library::add(size_t index, int id, std::string title, std::string name){
   if(index >= shelves.size()){ 
        std::cout << "Invalid index." << std::endl; 
        return;
    }   
    Shelf* sh = shelves[index].get();    
    for(int i{}; i < shelves.size(); ++i){
       for(int j{}; j < shelves[i].get()->getbooks().size(); ++j){
        for(int k{}; k < shelves[i].get()->getbooks()[j].get()->getauthors().size(); ++k){
            if(shelves[i].get()->getbooks()[j].get()->getauthors()[k].get()->getname() == name){
               u_ptr<Book> b (new Book(id,title,shelves[i].get()->getbooks()[j].get()->getauthors()[k])); 
               sh->getbooks().push_back(std::move(b));
               return;
            }
        }
       }
    }
    sh_ptr<Author> a (new Author(name));
    u_ptr<Book> b (new Book(id,title,a)); 
    sh->getbooks().push_back(std::move(b));
}

void Library::remove(std::string title){
   bool flag = false;
   for(int i{}; i < shelves.size(); ++i){
      for(int j{}; j < shelves[i].get()->getbooks().size(); ++j){
         if(shelves[i].get()->getbooks()[j].get()->getTitle() == title){
            shelves[i].get()->getbooks().erase(shelves[i].get()->getbooks().begin() + j);
            --j;
            flag = true;
         }
      }
   }
   if(!flag){
      std::cout << "No book with that title" << std::endl;
      return;
   }
}

Book* Library::find(std::string title){
   for(int i{}; i < shelves.size(); ++i){
      for(int j{}; j < shelves[i].get()->getbooks().size(); ++j){
         if(shelves[i].get()->getbooks()[j].get()->getTitle() == title){
            return shelves[i].get()->getbooks()[j].get();
         }
      }
   }
   std::cout << "No book with that title" << std::endl;
   return nullptr;
} 

void Library::movebook(int index,std::string title){
   for(int i{}; i < shelves.size(); ++i){
      for(int j{}; j < shelves[i].get()->getbooks().size(); ++j){
         if(shelves[i].get()->getbooks()[j].get()->getTitle() == title){
            if(i != index){
               Book* tmp = shelves[i].get()->getbooks()[j].release();
               shelves[i].get()->getbooks().erase(shelves[i].get()->getbooks().begin() + j);
               shelves[index].get()->getbooks().push_back(u_ptr<Book>(tmp));
               --j; 
            }
         }
      }
   }
}

void Library::replace(int id){
   for(int i{}; i < shelves.size(); ++i){
      for(int j{}; j < shelves[i].get()->getbooks().size(); ++j){
         if(shelves[i].get()->getbooks()[j].get()->getid() == id){
            sh_ptr<Author> a (new Author("Dyuma"));
            shelves[i].get()->getbooks()[j].reset(new Book(id,"Koms Mote Qristo", a));
         }
      }
   }
}

void Library::count(std::string name){
   for(int i{}; i < shelves.size(); ++i){
      for(int j{}; j < shelves[i].get()->getbooks().size(); ++j){
         for(int k{}; k < shelves[i].get()->getbooks()[j].get()->getauthors().size(); ++k){
            if(shelves[i].get()->getbooks()[j].get()->getauthors()[k].get()->getname() == name){      
               std::cout  << shelves[i].get()->getbooks()[j].get()->getauthors()[k].use_count() << "books have the same author" << std::endl;
            }
         }
      }
   }
}
