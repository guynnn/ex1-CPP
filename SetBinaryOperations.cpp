#include <iostream>
#include "MySet.h"

/**
 * A simple example for the operator I implemented.
 * @return 0 iff success
 */
int main()
{
    MySet set1;
    set1.add("Guy", 1);
    set1.add("Niv", 2);
    set1.add("David", 3);
    set1.add("Avi", 4);

    MySet set2;
    set2.add("Shira", 6);
    set2.add("Galya", 7);
    set2.add("Avi", 8);
    set2.add("Hana", 9);

    if (set1 > set2)
    {
        std::cout << "set1 is bigger" << std::endl;
    }
    else if (set1 < set2)
    {
        std::cout << "set2 is bigger" << std::endl;
    }
    else
    {
        std::cout << "equals" << std::endl;
    }

    set1.remove("Niv");
    set2.remove("Galya");
    set2.remove("Not in the set");

    std::cout << std::endl;

    std::cout << "set1 is:" << std::endl;
    set1.printSet();
    std::cout << std::endl;
    std::cout << "set2 is:" << std::endl;
    set2.printSet();
    std::cout << std::endl;

    std::cout << "The sum of set1 is: " << set1.sumSet() << std::endl;
    std::cout << "The sum of set2 is: " << set2.sumSet() << std::endl;
    std::cout << std::endl;

    MySet set3 = set1 & set2;
    std:: cout << "set1 & set2: ";
    std::cout << std::endl;
    set3.printSet();
    std::cout << std::endl;

    set3 = set1 - set2;
    std:: cout << "set1 - set2: ";
    std::cout << std::endl;
    set3.printSet();
    std::cout << std::endl;

    set3 = set1 | set2;
    std:: cout << "set1 | set2: ";
    std::cout << std::endl;
    set3.printSet();
    std::cout << std::endl;

    set3 = (set1 | set2) | (set1 & set2);
    std::cout << "Some complex operator usage:";
    std::cout << std::endl;
    set3.printSet();
    std::cout << std::endl;
    return 0;
}