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
	void RasterPos2f(void) { glRasterPos2f(x_, y_); }
	void setX(double x) { x_ = x; }
	void setY(double y) { y_ = y; }
};

class MenuElem
{
private:
	std::vector<MenuElem> subMenu_;
	MenuElem* parent_;
	std::string elem_;
	Position pos_;
public:
	MenuElem( MenuElem* parent, std::string elem, Position pos);
	MenuElem();
	std::vector<MenuElem> getSubMenu() { return subMenu_; }
	MenuElem* getParent() { return parent_; }
	std::string getElem() { return elem_; }
	void print();
	void addSubMenu(MenuElem elem) { subMenu_.push_back(elem); }
	void setPar(MenuElem *parent) { parent_ = parent; }
	void setElem(std::string elem) { elem_ = elem; }
	void setPos(Position pos) { pos_ = pos; }
	MenuElem operator=(MenuElem right)
	{
		this->elem_ = right.elem_;
		this->parent_ = right.parent_;
		this->pos_ = right.pos_;
		this->subMenu_ = right.subMenu_;
		return *this;
	}
};

class Menu
{
private:
	std::vector<MenuElem> elems_;
public:
	std::vector<MenuElem>& getElems()
	{
		return elems_;
	}
	void addElem(MenuElem newElem)
	{
		elems_.push_back(newElem);
	}
	void print();
};