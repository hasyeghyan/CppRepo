#include "mylist.hpp"

void SingleList::copy(const SingleList& oth){
     Node* tmp = oth.head;
     Node dummy;
     Node* tmp2 = &dummy;
     while(tmp){
      tmp2->next = new Node(tmp->val);
      tmp2 = tmp2->next;
      tmp = tmp->next;
     }
     head = dummy.next;
}

void SingleList::clear(){
     while(head){
          Node* tmp = head;
          head = head->next;
          delete tmp;
     }
}

SingleList::SingleList(int count, int _val){
            head = new Node(_val);
            --count;
            Node* tmp = head;
               for(int i {}; i < count; ++i){
                  tmp->next = new Node(_val);
                  tmp = tmp->next;
               }
} 

SingleList::SingleList(std::initializer_list<int> init){
   Node dummy;
   Node* tmp = &dummy;
   for (int x : init) {
      tmp->next = new Node(x);
      tmp = tmp->next;
   }

   head = dummy.next;
}

SingleList::SingleList(const SingleList& oth) {
         copy(oth);
}

SingleList::SingleList(SingleList&& oth): head(oth.head) {
          oth.head = nullptr;
}

SingleList::~SingleList(){
         clear();
}

SingleList& SingleList::operator=(const SingleList& oth){
         if(this != &oth){ 
           clear();
           copy(oth);
         }
         return *this;
}

SingleList& SingleList::operator=(SingleList&& oth){
          if(this != &oth){
            clear();
            head = oth.head;
            oth.head = nullptr;
          }
          return *this;
}

SingleList SingleList::operator+(const SingleList& oth)const{
   SingleList l(*this);
   if(!oth.head){
      return l;
   }
   if(!l.head){
      l.copy(oth);
      return l;
   } 
   Node* tmp1 = oth.head;
   Node* tmp = l.head;
   while(tmp->next){
       tmp = tmp->next;
   } 
   while(tmp1){
      tmp->next = new Node(tmp1->val);
      tmp = tmp->next;
      tmp1 = tmp1->next;
   }
   return l;
}

SingleList& SingleList::operator+=(const SingleList& oth){
   if(!oth.head){
      return *this;
   }
   if(!head){
      copy(oth);
      return *this;
   }
   Node* tmp = head;
   while(tmp->next) {
      tmp = tmp->next;
   }
   Node* tmp1 = oth.head;
   while(tmp1){
      tmp->next = new Node(tmp1->val);
      tmp = tmp->next;
      tmp1 = tmp1->next;
   }
   return *this;
}      

bool SingleList::operator==(const SingleList& oth)const{
     Node* tmp = head;
     Node* tmp1 = oth.head;
     while(tmp && tmp1){
           if(tmp->val != tmp1->val){
             return false;
           }
           tmp = tmp->next;
           tmp1 = tmp1->next;
     }
     if(tmp || tmp1){
      return false;
     }
     return true;
}      

bool SingleList::operator!=(const SingleList& oth)const{
     return !(*this == oth);
}

int&  SingleList::operator[](size_t index){
      if(!head){
         std::cout << "List is empty.";
         std::exit(1); 
      }
      size_t count = 0;
      Node* tmp = head;
      while(tmp){
         if(index == (count++)){
            return tmp->val;
         }
         tmp = tmp->next;
      }
      std::cout << "Invalid index.";
      std::exit(1);     
}

std::ostream& operator<<(std::ostream& os, const SingleList& l){
     os << "Your list is [";
     SingleList::Node* tmp = l.head;
     while(tmp){
      os << tmp->val;
      if(tmp->next) os << ",";
      tmp = tmp->next;
     }
     os << "]";
     os << std::endl;
     return os;
}

std::istream& operator>>(std::istream& is, SingleList& l){
   int count;
   is >> count;

   for(int i{}; i < count; ++i){
      int value;
      is >> value;
      l.push_back(value);
   }   
   return is;
}

bool SingleList::operator!()const{
     return !head;// or return head == nullptr
}

SingleList& SingleList::operator++(){
          push_back(7);
          return *this;
}
SingleList SingleList::operator++(int){
           SingleList tmp = *this;
           push_back(7);
           return tmp;
}

SingleList& SingleList::operator--(){
          pop_back();
          return *this;
}

SingleList SingleList::operator--(int){
           SingleList tmp = *this;
           pop_back();
           return tmp;
}

SingleList::operator bool()const{
         return head != nullptr;
}

SingleList::operator std::vector<int>()const{
         Node* tmp = head;
         std::vector<int> v;
         while(tmp){
            v.push_back(tmp->val);
            tmp = tmp->next;
         }
         return v;
}

void SingleList::push_front(int _val){
         Node* tmp = new Node(_val);
         tmp->next = head;
         head = tmp;
}

void SingleList::push_back(int _val){
   Node* tmp1 = new Node(_val);
   if(!head){
      head = tmp1;
   }
   else{
       Node* tmp = head;
       while(tmp->next){
            tmp = tmp->next;
       }
      tmp->next = tmp1;  
   }
}

void SingleList::pop_front(){
     if(!head){
      std::cout << "No element to pop,list is empty.";
      std::exit(1);
     }
     Node* tmp = head;
     head = head->next;
     delete tmp;
}

void SingleList::pop_back(){
     if(!head){
      std::cout << "No element to pop,list is empty.";
      std::exit(1);
     }
     if(!head->next){
      delete head;
      head = nullptr;
      return;
     }
     Node* tmp = head;
     while(tmp->next->next) tmp = tmp->next;
     Node* tmp1 = tmp->next;
     tmp->next = nullptr;
     delete tmp1;
}

size_t SingleList::size()const{
   size_t count = 0;
   Node* tmp = head;
   while(tmp){
      ++count;
      tmp = tmp->next;
   }
   return count;
}
