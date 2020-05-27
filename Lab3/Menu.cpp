#include "Menu.h"

MenuElem::MenuElem()
{
  Position pos;
	parent_ = NULL;
	title_ = "0";
	pos_ = pos;
}

MenuElem::MenuElem( MenuElem* parent, std::string title, Position pos)
{
	parent_ = parent;
	title_ = title;
	pos_ = pos;
}

void MenuElem::print()
{
	pos_.RasterPos2f();
	for (auto c : title_)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}

void Menu::print()
{
	for (MenuElem elem : elems_)
	{
		elem.print();
	}
}