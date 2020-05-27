#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Menu.h"

void Split(std::string& str, std::vector<std::string>& words, const std::string& delimiters);
std::string ReadMenu(std::string filename);
std::vector<std::string> Parcing(std::string str, double y, MenuElem *parent);
std::vector<std::string> Parcing(std::string str, double y);
Menu CreateMenu(std::string filename);
MenuElem FindParent(std::string par); 