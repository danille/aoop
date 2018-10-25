#include <iostream>
#include "table/CTableManager.h"
#include "menu/CMenu.h"
#include "menu/CMenuCommand.h"
#include "commands/CCommand.h"
#include "commands/CreateTablesCommand.h"
#include "commands/PrintTablesInfoCommand.h"
#include "application/Application.h"
#include "application/MenuApplication.h"

using namespace std;


int main() {
    MenuApplication application = MenuApplication();
//    CTableManager* tableManager = new CTableManager();
//    bool successor;
//    vector<CTable*> tables;
//    CCommand* defaultCommand =  new CCommand();
//    CCommand* createTablesCommand = new CreateTablesCommand(tableManager, tables, &successor);
//    CCommand* printTablesCommand = new PrintTablesInfoCommand(tableManager, tables, &successor);
//
//    cout << "Commands have been successfully created" << endl;
//
//    CMenu* rootMenu = new CMenu("Root", "root");
//    CMenu* childMenu = new CMenu("Table management", "tables");
//
//    cout << "Menus have been successfully created" << endl;
//
//    CMenuCommand* defaultMenuCommand = new CMenuCommand("Default", "default", defaultCommand);
//    CMenuCommand* createTablesMenuCommand = new CMenuCommand("Create tables", "create", createTablesCommand);
//    CMenuCommand* printTablesMenuCommand = new CMenuCommand("Print tables", "print", printTablesCommand);
//
//    cout << "Menu commands have been successfully created" << endl;
//
//    childMenu->addMenuItem(createTablesMenuCommand);
//    childMenu->addMenuItem(printTablesMenuCommand);
//    rootMenu->addMenuItem(childMenu);
//    rootMenu->addMenuItem(defaultMenuCommand);
//    cout << "Added menus item" << endl;
//
//    rootMenu->execute();
//
//    delete tableManager;
    application.run();
    return 0;
}