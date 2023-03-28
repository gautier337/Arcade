/*
** EPITECH PROJECT, 2023
** DynamicLibraryHandler
** File description:
** DynamicLibraryHandler
*/

#include "DynamicLibraryHandler.hpp"

DynamicLibraryHandler::DynamicLibraryHandler() : _handle(nullptr) {}

DynamicLibraryHandler::~DynamicLibraryHandler()
{
    closeLibrary();
}

bool DynamicLibraryHandler::loadLibrary(const std::string& path)
{
    closeLibrary();
    _handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!_handle) {
        std::cerr << "Error loading library: " << dlerror() << std::endl;
        return false;
    }
    return true;
}

void* DynamicLibraryHandler::getSymbol(const std::string& name)
{
    if (!_handle)
        return nullptr;

    void *symbol = dlsym(_handle, name.c_str());
    if (!symbol)
        std::cerr << "Error loading symbol: " << dlerror() << std::endl;
    return symbol;
}

void DynamicLibraryHandler::closeLibrary()
{
    if (_handle) {
        dlclose(_handle);
        _handle = nullptr;
    }
}
