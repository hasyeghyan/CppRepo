#include "mylist.hpp"

int main() {
    SingleList list1;                 
    SingleList list2(3, 10);          
    SingleList list3{1, 2, 3, 4};     

    std::cout << "Initial lists:\n";
    std::cout << "list1: " << list1;
    std::cout << "list2: " << list2;
    std::cout << "list3: " << list3;

    SingleList list4(list3);
    std::cout << "\nAfter copying list3 to list4:\n" << list4;


    SingleList list5(std::move(list4));
    std::cout << "\nAfter moving list4 to list5:\nlist5: " << list5;

    SingleList list6 = list2 + list3;
    std::cout << "\nConcatenation list2 + list3:\nlist6: " << list6;

    list2 += list3;
    std::cout << "\nAfter list2 += list3:\nlist2: " << list2;

    std::cout << "\nComparison:\n";
    std::cout << "list2 == list6? " << (list2 == list6 ? "true" : "false") << "\n";
    std::cout << "list3 != list5? " << (list3 != list5 ? "true" : "false") << "\n";

    std::cout << "\nIndexing:\n";
    for (size_t i = 0; i < list3.size(); ++i) {
        std::cout << "list3[" << i << "] = " << list3[i] << "\n";
    }

    ++list3;
    std::cout << "\nAfter prefix ++ list3:\n" << list3;

    SingleList tmpList = list3++;
    std::cout << "\nAfter postfix ++ list3:\nold copy (tmpList): " << tmpList;
    std::cout << "list3 now: " << list3;

    --list3;
    std::cout << "\nAfter prefix -- list3:\n" << list3;

    tmpList = list3--;
    std::cout << "\nAfter postfix -- list3:\nold copy (tmpList): " << tmpList;
    std::cout << "list3 now: " << list3;

    SingleList list7;
    std::cin >> list7;
    std::cout << "You entered:\n" << list7;

    SingleList emptyList;
    std::cout << "\nEmpty list check:\n";
    std::cout << "Is emptyList empty? " << (!emptyList ? "yes" : "no") << "\n";

    SingleList singleElemList(1, 42);
    std::cout << "\nSingle-element list:\n" << singleElemList;

    singleElemList.pop_back();
    std::cout << "After pop_back, singleElemList size: " << singleElemList.size() << "\n";

    singleElemList.push_back(99);
    singleElemList.pop_front();
    std::cout << "After push_back and pop_front, singleElemList size: " << singleElemList.size() << "\n";

    return 0;
}
