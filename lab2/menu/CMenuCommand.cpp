//
// Created by Lebediev, Danylo on 16/10/2018.
//
#include "CMenuCommand.h"

#define EMPTY_COMMAND_TEXT "empty command"

void CMenuCommand::run() {

    if (commandToExecute == nullptr) {
        cout << EMPTY_COMMAND_TEXT << endl;
    } else {
        commandToExecute->execute();
    }

    terminate();
}

CMenuCommand::~CMenuCommand() {

}

void CMenuCommand::terminate() {
    parentItem->run();
}

string CMenuCommand::getPath() {
    if (parentItem == nullptr) {
        return getCommand();
    } else {
        return parentItem->getPath() + "->" + getCommand();
    }
}

CMenuCommand::CMenuCommand(string name, string command, CCommand *commandToExecute) {
    this->name = name;
    this->command = command;
    this->commandToExecute = commandToExecute;
}

string CMenuCommand::getName() {
    return name;
}

string CMenuCommand::getCommand() {
    return command;
}

bool CMenuCommand::isCommandValid(string command) {
    return command == this->command;
}

string CMenuCommand::getCommandFromUser() {
    string v;
    while (!(std::cin >> v) && !isCommandValid(v)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid command: " << v << " Try again.\n";
    }
    return v;
}
