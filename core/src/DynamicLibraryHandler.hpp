/*
** EPITECH PROJECT, 2023
** DynamicLibraryHandler
** File description:
** DynamicLibraryHandler
*/

#pragma once

#include <string>
#include <dlfcn.h>

class DynamicLibraryHandler {
public:
    DynamicLibraryHandler();
    ~DynamicLibraryHandler();

    bool loadLibrary(const std::string& path);
    void* getSymbol(const std::string& name);

private:
    void closeLibrary();

    void* _handle;
};
