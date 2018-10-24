//
// Created by Lebediev, Danylo on 23/10/2018.
//

#ifndef LAB2_CREATETABLESCOMMAND_H
#define LAB2_CREATETABLESCOMMAND_H


#include "CCommand.h"
#include "../CTableManager.h"
#include "TableCommand.h"

class CreateTablesCommand: public TableCommand {
    CTableManager* tableManager;
    vector<CTable*>* tablesVector;
    bool* successor;
public:
    CreateTablesCommand(CTableManager* tableManager, vector<CTable*> &tablesVector, bool* successor);
    void run();
};


#endif //LAB2_CREATETABLESCOMMAND_H
