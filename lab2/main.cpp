#include <iostream>
#include "CTableManager.h"
#include "menu/CMenu.h"
#include "menu/CMenuCommand.h"
#include "commands/CCommand.h"
#include "commands/CreateTablesCommand.h"
#include "commands/PrintTablesInfoCommand.h"

using namespace std;


int main() {
    CTableManager* tableManager = new CTableManager();
    bool successor;
    vector<CTable*> tables;
    CCommand* defaultCommand =  new CCommand();
    CCommand* createTablesCommand = new CreateTablesCommand(tableManager, tables, &successor);
    CCommand* printTablesCommand = new PrintTablesInfoCommand();

    cout << "Commands have been successfully created" << endl;

    CMenu* rootMenu = new CMenu("Root", "root");
    CMenu* childMenu = new CMenu("Table management", "tables");

    cout << "Menus have been successfully created" << endl;

    CMenuCommand* defaultMenuCommand = new CMenuCommand("Default", "default", defaultCommand);
    CMenuCommand* createTablesMenuCommand = new CMenuCommand("Create tables", "create", createTablesCommand);
    CMenuCommand* printTablesMenuCommand = new CMenuCommand("Print tables", "print", printTablesCommand);

    cout << "Menu commands have been successfully created" << endl;

    childMenu->addMenuItem(createTablesMenuCommand);
    childMenu->addMenuItem(printTablesMenuCommand);
    rootMenu->addMenuItem(childMenu);
    rootMenu->addMenuItem(defaultMenuCommand);
    cout << "Added menus item" << endl;

    rootMenu->run();
    return 0;
}