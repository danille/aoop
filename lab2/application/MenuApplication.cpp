//
// Created by Lebediev, Danylo on 24/10/2018.
//

#include "MenuApplication.h"

MenuApplication::MenuApplication() {
    tableManager = new CTableManager();
    tablesVector = new vector<CTable*>();
    successor = new bool;
    root = new CMenu("Root", "");
}

MenuApplication::~MenuApplication() {
    delete tableManager;
    delete successor;
    delete root;
    for (int i = 0; i < tablesVector->size(); i++){
        delete (*tablesVector)[i];
    }
}

void MenuApplication::run() {
    CCommand* defaultCommand =  new CCommand();
    CCommand* createTablesCommand = new CreateTablesCommand(tableManager, *tablesVector, successor);
    CCommand* printTablesCommand = new PrintTablesInfoCommand(tableManager, *tablesVector, successor);

    cout << "Commands have been successfully created" << endl;

    CMenu* childMenu = new CMenu("Table management", "tables");

    cout << "Menus have been successfully created" << endl;

    CMenuCommand* defaultMenuCommand = new CMenuCommand("Default", "default", defaultCommand);
    CMenuCommand* createTablesMenuCommand = new CMenuCommand("Create tables", "create", createTablesCommand);
    CMenuCommand* printTablesMenuCommand = new CMenuCommand("Print tables", "print", printTablesCommand);

    cout << "Menu commands have been successfully created" << endl;

    childMenu->addMenuItem(createTablesMenuCommand);
    childMenu->addMenuItem(printTablesMenuCommand);
    root->addMenuItem(childMenu);
    root->addMenuItem(defaultMenuCommand);
    cout << "Added menus item" << endl;

    root->run();
}
