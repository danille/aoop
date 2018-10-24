//
// Created by Lebediev, Danylo on 23/10/2018.
//

#include "PrintTablesInfoCommand.h"


void PrintTablesInfoCommand::run() {
    tableManager->printTableInfo(*tablesVector, successor);
}

PrintTablesInfoCommand::PrintTablesInfoCommand(CTableManager *tableManager, vector<CTable *> &tablesVector,
                                               bool *successor) : TableCommand(tableManager, tablesVector, successor) {

}
