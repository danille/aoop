//
// Created by Lebediev, Danylo on 16/10/2018.
//

#include "CCommand.h"
#include "iostream"

#define DEFAULT_COMMAND_MESSAGE "Komenda domyślna"
using namespace std;

void CCommand::execute() {
    cout << DEFAULT_COMMAND_MESSAGE << endl;
}

CCommand::CCommand() {

}

CCommand::~CCommand() {

}
