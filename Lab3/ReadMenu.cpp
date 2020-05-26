#include "ReadMenu.h"

Menu menu;

void Split(std::string& str, std::vector<std::string>& words, const std::string& delimiters)
{
	std::string::size_type last = str.find_first_not_of(delimiters, 0);
	std::string::size_type first = str.find_first_of(delimiters, last);
	words.push_back(str.substr(last, first - last));
	if(last > 0)
	  last = last - 1;
	str.erase(last, first - last);
	words.push_back(str.substr(0, str.size()));
}

std::string ReadMenu(std::string filename)
{
	std::string str;
	std::ifstream input(filename);
	std::getline(input, str);
	return str;
}

std::vector<std::string> Parcing(std::string str, double y)
{
	MenuElem tmp;
	double x = 0, deltay = -0.5;
	y += deltay;
	Position pos(x, y);
	std::vector<std::string> s, submenu;
	Split(str, submenu, ",()");
	tmp.setTitle(submenu.front());
	tmp.setPos(pos);
	tmp.setPar(NULL);
	menu.addElem(tmp);
	return submenu;
}

std::vector<std::string> Parcing(std::string str, double y, MenuElem* parent)
{
  std::vector<MenuElem>::iterator it;
	MenuElem tmp;
	double x = 0, deltay = -0.5;
	y += deltay;
	Position pos(x, y);
	std::vector<std::string> s, submenu;
	Split(str, submenu, ",()");
	tmp.setTitle(submenu.front());
	tmp.setPos(pos);
	tmp.setPar(parent);
	for (unsigned i = 0; i < menu.getElems().size(); i++)
	{
		if (menu.getElement(i).getTitle() == (*parent).getTitle())
		{
			menu.getElement(i).addSubMenu(tmp);
			return submenu;
		}
		for (unsigned j = 0; j < menu.getElement(i).getSubMenu().size(); j++)
		{
			if (menu.getElement(i).getSubMenuElem(j).getTitle() == (*parent).getTitle())
			{
				menu.getElement(i).getSubMenuElem(j).addSubMenu(tmp);
				return submenu;
			}
		}
	}
	return submenu;
}

MenuElem FindParent(std::string par)
{
  MenuElem parent;
  std::vector<MenuElem> elems = menu.getElems();
	for (unsigned i = 0; i < elems.size(); i++)
	{
		if (elems[i].getTitle() == par)
		{
			parent = elems[i];
		  return parent;
		}
		std::vector<MenuElem> sub = elems[i].getSubMenu();
		for (unsigned j = 0; j < sub.size(); j++)
		{
			if (sub[j].getTitle() == par)
			{
				return sub[j];
			}
		}
	}
	return parent;
}

Menu CreateMenu(std::string filename)
{
	std::vector<std::string> subMenu;
	MenuElem elem;
	MenuElem parent;
  double y = 1;
	std::string str = ReadMenu(filename);
	subMenu = Parcing(str, y);
	str = subMenu.back();
	parent = menu.getElement(0);
	while (str.size() != 0)
	{
		if (subMenu.size() != 0)
		{
			if (subMenu.back()[0] == ',')
			{
				subMenu = Parcing(str, y, &parent);
				str = subMenu.back();
				y += -0.25;
			}
			else if (subMenu.back()[0] == '(')
			{
				parent = FindParent(subMenu.front());
				subMenu = Parcing(str, y, &(parent));
				str = subMenu.back();
				y += -0.25;
			}
			else if (subMenu.back()[0] == ')')
			{
				str.erase(0, 1);
				subMenu.back().erase(0, 1);
				parent.setPar(&(FindParent(parent.getTitle())));
			}
		}
	}
	return menu;
}