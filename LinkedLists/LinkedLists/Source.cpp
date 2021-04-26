#include <iostream>
#include "LinkedList.h"

using namespace std;

void main() {
    // create linked list
    LinkedList<int> list = LinkedList<int>();

    // add values to linked list
    list.add(1);
    list.add(56);
    list.add(2);
    list.add(15);
    list.add(18);
    list.add(27);

    // print linked list
    list.print(std::cout);

    // output the location of 2's node
    cout<< endl << "Pointer to Node containing 2: " << list.find(2) << endl;

    // check for a non existant value in the node
    cout << endl << "Check if 10 exists in the list: " << list.find(10) << endl;

    // remove list
    list.remove(list.find(2));
    // print the info
    list.print(cout);

    // print the min and max values
    cout << endl << "Max value in the list: " << list.max()->value << endl;
    cout << "Min value in the list: " << list.min()->value << endl;

    return;
}