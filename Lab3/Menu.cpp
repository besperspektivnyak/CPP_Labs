#include "Menu.h"

MenuElem::MenuElem()
{
  Position pos;
	parent_ = NULL;
	elem_ = "0";
	pos_ = pos;
}

MenuElem::MenuElem( MenuElem* parent, std::string elem, Position pos)
{
	parent_ = parent;
	elem_ = elem;
	pos_ = pos;
}

void MenuElem::print()
{
	pos_.RasterPos2f();
	for (auto c : elem_)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}

void Menu::print()
{
	for (MenuElem elem : elems_)
	{
		elem.print();
	}
}