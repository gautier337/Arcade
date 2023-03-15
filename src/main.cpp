/*
** EPITECH PROJECT, 2023
** main_function
** File description:
** main
*/

#include "../include/lib/lib.hpp"

bool is_file(const std::string &path)
{
    struct stat info;
    if (stat(path.c_str(), &info) != 0)
        return false;
    if ((info.st_mode & S_IFREG) == 0)
        return false;
    return true;
}

bool is_dynamic_library(const std::string &path)
{
    if (!is_file(path))
        return false;
    void *lib = dlopen("./libsharedtest.so", RTLD_LAZY);
    if (!lib) {
        std::cout << "dlopen() failed: " << dlerror() << std::endl;
        return false;
    }
    dlclose(lib);
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./arcade ./lib/{arcade_ncurses ??}.so" << std::endl;
        return 84;
    }
    std::string path = argv[1];
    if (is_file(path) && is_dynamic_library(path))
        std::cout << "Chemin valide : " << path << "le fichier choisi n'est pas pris en compte, le fichier a été écrit en dur dans le code .. à changer"  << std::endl;
    else {
        std::cout << "Chemin invalide ou ne pointant pas vers une librairie partage : " << path << std::endl;
        return 84;
    }
    return 0;
}
