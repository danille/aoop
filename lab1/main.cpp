#include <iostream>
#include "CTable.h"
#include "CTableManager.h"

#define END_LINE "\n"

using namespace std;

void validateMenuInput(int& indicator) {
    while ((std::cout << "Wpisz numer: " << std::endl && !(std::cin >> indicator)) || indicator < 1 || indicator > 10) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Nieprawidlowe dane; Sprobuj ponownie.\n";
    }
}

int main() {
    bool successHelper;
    int indicator;
    vector<CTable*> tables;
    CTableManager manager;

    while (true) {
        std::cout << "\n" << std::endl
                  << "1. Create CTable objects" << std::endl
                  << "2. Set length of specific CTable object" << std::endl
                  << "3. Remove specific CTable object" << std::endl
                  << "4. Remove all CTable objects" << std::endl
                  << "5. Set name of specific CTable object" << std::endl
                  << "6. Clone specific CTable object and add it to pool" << std::endl
                  << "7. Print info about specific CTable object" << std::endl
                  << "8. Insert element to specific CTable object" << std::endl
                  << "9. Exit" << std::endl
                  << "10. Execute test" << endl;

        validateMenuInput(indicator);

        switch (indicator) {
            case 1:
                manager.createTables(tables, &successHelper);
                break;

            case 2:
                manager.setTableLength(tables, &successHelper);
                break;

            case 3:
                manager.removeTable(tables, &successHelper);
                break;

            case 4:
                manager.removeTables(tables, &successHelper);
                break;

            case 5:
                manager.setTableName(tables, &successHelper);
                break;

            case 6:
                manager.cloneTable(tables, &successHelper);
                break;

            case 7:
                manager.printTableInfo(tables, &successHelper);
                break;

            case 8:
                manager.insertElementIntoTable(tables, &successHelper);
                break;

            case 9:
                manager.removeTables(tables, &successHelper);
                return 0;
            case 10:
                manager.executeTest(tables, &successHelper);
        }
        manager.validateOperation(&successHelper);
        manager.printAllTables(tables, &successHelper);
        manager.validateOperation(&successHelper);
    }


}