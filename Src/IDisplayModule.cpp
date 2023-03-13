/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Implementation of IDisplay Module interface
*/

#include "../Include/IDisplayModule.hpp"

IDisplayModule::IDisplayModule()
{
}

IDisplayModule::~IDisplayModule()
{
}

void IDisplayModule::init()
{
    std::cout << "init" << std::endl; 
}

void IDisplayModule::stop()
{
    std::cout << "stop" << std::endl;
}

const std::string &IDisplayModule::getName() const
{
    return (this->_name);
}
