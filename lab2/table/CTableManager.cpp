//
// Created by Lebediev, Danylo on 08/10/2018.
//

#include "CTableManager.h"


void CTableManager::createTables(vector<CTable *> &tablesVector, bool *success) {
    int numberOfTables = getIntValue("How many CTable should be created? Enter a number");

    if (numberOfTables > 0) {
        size = numberOfTables;
        for (int i = 0; i < numberOfTables; i++) {
            cout << "Creating table #" << i << endl;
            string name = "Table " + to_string(i);
            CTable *temp = new CTable(name, i);
            tablesVector.push_back(temp);
        }
        *success = true;
    }

}


void CTableManager::setTableLength(vector<CTable *> &tablesVector, bool *success) {
    int index, length;
    index = getIntValue("Specify index of the table");

    *success = isIndexValid(index);

    if (*success) {
        length = getIntValue("Specify new length for this table");

        *success = length >= 0;

        if (*success) {
            tablesVector[index]->setLength(length, success);
        }
    }


}

void CTableManager::removeTable(vector<CTable *> &tablesVector, bool *success) {


    int index = getIntValue("Specify index of the table you want to remove");

    *success = isIndexValid(index);

    if (*success) {
        size -= 1;
        // Explicitly delete object, if not - memory leak. Why? Does vector::erase() not execute delete?
        delete tablesVector[index];
        tablesVector.erase(tablesVector.begin() + index);

    }

}

void CTableManager::removeTables(vector<CTable *> &tablesVector, bool *success) {
    for (int i = 0; i < tablesVector.size(); i++) {
        delete tablesVector[i];
    }
    tablesVector.clear();
    size = 0;
    *success = true;
}

void CTableManager::setTableName(vector<CTable *> &tablesVector, bool *success) {
    int index = getIntValue("Specify index of the table you want to rename");

    *success = isIndexValid(index);

    if (*success) {
        std::string newName;
        std::cout << "Enter new name" << std::endl;
        std::cin >> newName;
        tablesVector[index]->setName(newName, success);
    }

}

void CTableManager::cloneTable(vector<CTable *> &tablesVector, bool *success) {
    int index = getIntValue("Specify index of table you want to clone");

    *success = isIndexValid(index);

    if (*success) {
        CTable *copy = tablesVector[index]->clone(success);
        tablesVector.push_back(copy);
        size++;
    }

}

void CTableManager::printTableInfo(vector<CTable *> &tablesVector, bool *success) {
    int index = getIntValue("Specify index of table you want to print info about");

    *success = isIndexValid(index);

    if (*success) {
        std::cout << tablesVector[index]->toString() << std::endl;
    }

}

void CTableManager::printTableElement(vector<CTable *> &tablesVector, bool *success) {
    int tableIndex = getIntValue("Specify index of table you want to print info about");

    *success = isIndexValid(tableIndex);
    if (*success) {
        CTable *specifiedTable = tablesVector[tableIndex];
        int elementIndex = getIntValue("Specify index of table element you want to print");
        *success = isIndexValid(elementIndex, specifiedTable->getLength());

        if (*success) {
            string elementString = to_string(specifiedTable->get(elementIndex, success));
            if (*success) {
                cout << "Element of " << specifiedTable->getName() << " table at " << to_string(elementIndex) << ": "
                     << elementString;
            }
        }
    }
}

void CTableManager::insertElementIntoTable(vector<CTable *> &tablesVector, bool *success) {
    int tableIndex = getIntValue("Specify index of table you want to insert element into");

    *success = isIndexValid(tableIndex);
    if (*success) {
        CTable *specifiedTable = tablesVector[tableIndex];
        int elementIndex = getIntValue("Specify index you want to insert element at");
        *success = isIndexValid(elementIndex, specifiedTable->getLength());

        if (*success) {
            int element = getIntValue("Specify element you want insert");
            specifiedTable->insert(elementIndex, element, success);
        }
    }
}

void CTableManager::executeTest(vector<CTable *> &tablesVector, bool *success) {
    int tableIndex = getIntValue("Enter index of table for test");

    *success = isIndexValid(tableIndex);

    if (*success) {
        doNothing(*tablesVector[tableIndex], success);
    }
}

void CTableManager::doNothing(CTable cTable, bool *success) {
    cTable.setLength(5, success);
}

bool CTableManager::isTableValid(CTable &table) {
    return &table != nullptr;
}

void CTableManager::validateOperation(bool *success) {
    if (*success) std::cout << "Operacja powiodla sie" << std::endl;
    else std::cout << "Operacja nie powiodla sie" << std::endl;
}

bool CTableManager::isTableValid(CTable *&table) {
    return table != NULL;
}

int CTableManager::getIntValue(std::string hint) {
    int v;
    while (std::cout << hint << std::endl && !(std::cin >> v)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Nieprawidlowa liczba; sprobuj ponownie.\n";
    }
    return v;
}

bool CTableManager::isIndexValid(int index) {
    return !(index < 0 || index > this->size - 1);
}

bool CTableManager::isIndexValid(int index, int size) {
    return !(index < 0 || index > size - 1);
}

void CTableManager::printAllTables(vector<CTable *> &tablesVector, bool *success) {
    for (int i = 0; i < size; i++) {
        cout << tablesVector[i]->toString() << endl;
    }
}
