/*
** EPITECH PROJECT, 2023
** DynamicLibraryHandler
** File description:
** DynamicLibraryHandler
*/

#ifndef DYNAMIC_LIBRARY_HANDLER_HPP
#define DYNAMIC_LIBRARY_HANDLER_HPP

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

#endif
