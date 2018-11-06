//
// Created by Lebediev, Danylo on 24/10/2018.
//

#ifndef LAB2_MENUAPPLICATION_H
#define LAB2_MENUAPPLICATION_H


#include "Application.h"
#include "../table/CTableManager.h"
#include "../menu/CMenu.h"
#include "../commands/CCommand.h"
#include "../commands/CreateTablesCommand.h"
#include "../commands/PrintTablesInfoCommand.h"
#include "../menu/CMenuCommand.h"

class MenuApplication : Application {
    CTableManager *tableManager;
    vector<CTable *> *tablesVector;
    bool *successor;
    CMenu *root;

public:
    MenuApplication();

    void run();

    ~MenuApplication();
};


#endif //LAB2_MENUAPPLICATION_H
