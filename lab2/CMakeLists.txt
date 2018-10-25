cmake_minimum_required(VERSION 3.12)
project(lab2)

set(CMAKE_CXX_STANDARD 98)

add_executable(lab2 main.cpp menu/CMenuItem.h menu/CMenuCommand.h commands/CCommand.h menu/CMenuCommand.cpp commands/CCommand.cpp menu/CMenu.cpp menu/CMenu.h menu/CMenuItemDelegate.h
        table/CTable.h table/CTable.cpp table/CTableManager.h table/CTableManager.cpp commands/CreateTablesCommand.cpp commands/CreateTablesCommand.h commands/PrintTablesInfoCommand.cpp commands/PrintTablesInfoCommand.h commands/TableCommand.cpp commands/TableCommand.h application/Application.h application/MenuApplication.cpp application/MenuApplication.h NavigationManager.cpp NavigationManager.h)