//
// Created by Lebediev, Danylo on 24/10/2018.
//

#include "TableCommand.h"

TableCommand::TableCommand(CTableManager *tableManager, vector<CTable *> &tablesVector, bool *successor) {
    this->tableManager = tableManager;
    this->tablesVector = &tablesVector;
    this->successor = successor;
}

void TableCommand::validateOperation() {
    if (!*successor) {
        cout << "Operation failed! Please, try again!" << endl;
    }
}
