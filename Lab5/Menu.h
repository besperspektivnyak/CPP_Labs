#pragma once

#include <vector>
#include <string>
#include <GL\glut.h>

class Position
{
private:
	double x_;
	double y_;
public:
	Position() { x_ = 0.0, y_ = 0.0; }
	Position(double x, double y) { x_ = x; y_ = y; }
	void RasterPos2f(void) { glRasterPos2f(x_, y_); }
};

class MenuElem
{
private:
	std::vector<MenuElem> subMenu_;
	MenuElem* parent_;
	std::string title_;
	Position pos_;
public:
	MenuElem( MenuElem* parent, std::string elem, Position pos);
	MenuElem();
	std::vector<MenuElem>& getSubMenu() { return subMenu_; }
	MenuElem getSubMenuElem(unsigned index) { return getSubMenu()[index]; }
	MenuElem* getParent() { return parent_; }
	std::string getTitle() { return title_; }
	void print();
	void addSubMenu(MenuElem elem) { subMenu_.push_back(elem); }
	void setPar(MenuElem *parent) { parent_ = parent; }
	void setTitle(std::string elem) { title_ = elem; }
	void setPos(Position pos) { pos_ = pos; }
	MenuElem operator=(const MenuElem& right)
	{
		title_ = right.title_;
		parent_ = right.parent_;
		pos_ = right.pos_;
		subMenu_ = right.subMenu_;
		return *this;
	}
};

class Menu
{
private:
	std::vector<MenuElem> elems_;
public:
	std::vector<MenuElem>& getElems() { return elems_; }
	void addElem(MenuElem newElem) { elems_.push_back(newElem); }
	MenuElem getElement(unsigned index) { return getElems()[index]; }
	void print();
};