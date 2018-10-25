//
// Created by Lebediev, Danylo on 23/10/2018.
//

#include "CreateTablesCommand.h"

void CreateTablesCommand::execute() {
    tableManager->createTables(*tablesVector, successor);
}

CreateTablesCommand::CreateTablesCommand(CTableManager *tableManager, vector<CTable *> &tablesVector, bool *successor)
        : TableCommand(tableManager, tablesVector, successor) {
    
}

