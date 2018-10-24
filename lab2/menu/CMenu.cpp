//
// Created by Lebediev, Danylo on 16/10/2018.
//

#include "CMenu.h"

void CMenu::addMenuItem(CMenuItem *menuItem) {
    if (commands != nullptr && menuItem != nullptr) {

        commands->push_back(menuItem);

    }
}

void CMenu::runMenuItem(CMenuItem *menuItem) {
    menuItem->parentItem = this;
    menuItem->run();
}

void CMenu::run() {
    cout << getName() << endl;

    for (int i = 0; i < commands->size(); i++) {
        string itemName = (*commands)[i]->getName();
        string itemCommand = (*commands)[i]->getCommand();
        cout << itemName  << "\t" << itemCommand << endl;
//        cout << getPath() << endl;
    }

    string command = getCommandFromUser();
    if (command == BACK_COMMAND) {
        terminate();
    } else {
        CMenuItem *menuItem = getMenuItemByCommand(command);
        runMenuItem(menuItem);
    }
}

string CMenu::getCommandFromUser() {
    string v;
    while (!(std::cin >> v) && !isCommandValid(v)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid command: " << v << " Try again.\n";
    }
    return v;
}

bool CMenu::isCommandValid(string command) {
//    this solution is borrowed from https://stackoverflow.com/a/5489827
//    return find(commands->begin(), commands->end(), command) != commands->end();
    bool isValid = false;
    for (int i = 0; i < commands->size(); i++) {
        string menuItemCommand = (*commands)[i]->getCommand();
        if (menuItemCommand == command) {
            isValid = true;
        }
    }
    return isValid;
}

CMenuItem *CMenu::getMenuItemByCommand(string command) {
    int menuItemPosition = 0;
    for (int i = 0; i < commands->size(); i++) {
        string menuItemCommand = (*commands)[i]->getCommand();
        if (menuItemCommand == command) {
            menuItemPosition = i;
        }
    }

    return (*commands)[menuItemPosition];
}

void CMenu::terminate() {
//    if (parentItem = nullptr) {
//        cout << "Shutting down..." << endl;
//        cout << "Goodbye!" << endl;
//
//        return 0;
//
//    }
    parentItem->run();
}

CMenu::~CMenu() {
    for (int i = 0; i < commands->size(); i++) {
        delete ((*commands)[i]);
    }
    delete (commands);
}

string CMenu::getPath() {
    if (parentItem == nullptr) {
        return getCommand();
    } else {
        return parentItem->getPath() + getCommand();
    }
}

string CMenu::getName() {
    return name;
}

string CMenu::getCommand() {
    return command;
}

CMenu::CMenu(string name, string command) {
    commands = new vector<CMenuItem *>;
    this->name = name;
    this->command = command;
}


