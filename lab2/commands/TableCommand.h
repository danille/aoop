//
// Created by Lebediev, Danylo on 24/10/2018.
//

#ifndef LAB2_TABLECOMMAND_H
#define LAB2_TABLECOMMAND_H


#include "CCommand.h"
#include "../CTableManager.h"
#include "../CTable.h"

class TableCommand: public CCommand {
protected:
    CTableManager* tableManager;
    vector<CTable*>* tablesVector;
    bool* successor;
public:
    TableCommand(CTableManager* tableManager, vector<CTable*> &tablesVector, bool* successor);
};


#endif //LAB2_TABLECOMMAND_H
