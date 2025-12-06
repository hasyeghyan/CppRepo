#include "lib.hpp"

int main() {
    Library lib;

    lib.add();
    lib.add();

    lib.add(0, 1, "Poems", "Tumanyan");
    lib.add(0, 2, "Fairy Tales", "Tumanyan");
    lib.add(0, 3, "Adventures", "Dyuma");

    lib.add(1, 4, "Novels", "Dyuma");

    lib.count("Tumanyan");
    lib.count("Dyuma");

    Book* b = lib.find("Poems");
    if (b) std::cout << "Found book: " << b->getTitle() << std::endl;

    lib.movebook(1, "Poems");

    lib.replace(3);

    lib.remove("Fairy Tales");

    lib.remove(0);
    std::cout << "Program finished" << std::endl;
    return 0;
}
