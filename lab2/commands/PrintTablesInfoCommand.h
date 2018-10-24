//
// Created by Lebediev, Danylo on 23/10/2018.
//

#ifndef LAB2_PRINTTABLESINFOCOMMAND_H
#define LAB2_PRINTTABLESINFOCOMMAND_H


#include "CCommand.h"
#include "../CTableManager.h"
#include "TableCommand.h"

class PrintTablesInfoCommand : public TableCommand {

public:
    PrintTablesInfoCommand(CTableManager *tableManager, vector<CTable *> &tablesVector, bool *successor);

    void run();
};


#endif //LAB2_PRINTTABLESINFOCOMMAND_H
