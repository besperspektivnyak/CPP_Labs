#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <GL/glut.h>
#include "level.h"
#include "bonus.h"
#include "brick.h"
#include "paddle.h"
#include "object.h"

TypeCollision collX = TypeCollision::X;
TypeCollision collY = TypeCollision::Y;
TypeCollision collXY = TypeCollision::XY;

Bonus activeBonus;

void Level::start()
{
  drawBorders();
	drawLives();
	drawScore();
  int row = 0;
	for (row; row < (int)field_.size(); row++)
	{
		for (auto brick : field_[row])
		{
			brick.draw();
		}
	}
}

void Level::finish()
{
	glClear(GL_COLOR_BUFFER_BIT);
	initPaddle();
	initBall();
}

Level::Level(std::string filename)
{ 
	Point centerp(320, 0);
	Point centerb(310, 20);
	Paddle paddle(centerp, 30, 100, 10);
	Ball ball(centerb, 10, 30, 3);
	std::vector<std::vector<Brick>> field;
  float x = 85, y = 270;
	std::string str;
	std::ifstream input(filename);
	while (std::getline(input, str))
	{
		std::vector<Brick> row = ParcingString(str, x, y);
		field.push_back(row);
		y += 20;
	}
	field_ = field;
	ball_ = ball;
	paddle_ = paddle;
	score_ = 0;
}

std::vector<Brick> ParcingString(std::string str, float x, float y)
{
	std::vector<Brick> row;
	Strength strength = Strength::WEAK;
	BonusType type = BonusType::NONE;
	std::string tmp;
	while (str.empty() == false)
	{
		Point p(x, y);
		std::string::size_type first = str.find_first_not_of(" ", 0);
		std::string::size_type last = str.find_first_of(" ", first);
		tmp = str.substr(first, last);
		str.erase(first, last - first);
		if (str.substr(0, 1) == " ")
			str.erase(0, 1);

		Brick brick = CreateBrick(p, row, tmp, type, strength);
		row.push_back(brick);
		x += 40;
	}
	return row;
}

Brick CreateBrick(Point p, std::vector<Brick> row, std::string tmp, BonusType type, Strength strength)
{
	if (std::stoi(tmp.substr(0, 1)) == 1)
	{
		switch (std::stoi(tmp.substr(1, 1)))
		{
		case 0:
			break;
		case 1:
			type = BonusType::SPEED_PLUS;
			break;
		case 2:
			type = BonusType::SPEED_MINUS;
			break;
		case 3:
			type = BonusType::PADDLE_PLUS;
			break;
		case 4:
			type = BonusType::PADDLE_MINUS;
			break;
		case 5:
			type = BonusType::LIFE;
			break;
		case 6:
			type = BonusType::EXTRA_POINTS;
			break;
		}
		switch (std::stoi(tmp.substr(2, 1)))
		{
		case 1:
			strength = Strength::WEAK;
			break;
		case 2:
			strength = Strength::MIDDLE;
			break;
		case 3:
			strength = Strength::HARD;
			break;
		}
		Bonus bonus(p, type);
		Brick brick(p, 0.5, 20, 40, strength, bonus, false);
		return brick;
	}
	else
	{
		Bonus bonus(p, BonusType::NONE);
		Brick brick(p, 0.5, 20, 40, strength, bonus, true);
		return brick;
	}
}


void Level::drawBorders()
{
  glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(50, 430);
	glVertex2f(60, 430);
	glVertex2f(60, 0);
	glVertex2f(50, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(50, 430);
	glVertex2f(590, 430);
	glVertex2f(590, 420);
	glVertex2f(50, 420);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(590, 430);
	glVertex2f(600, 430);
	glVertex2f(600, 0);
	glVertex2f(590, 0);
	glEnd();
}

void Level::initPaddle()
{
	paddle_.draw();
}

void Level::initBall()
{
	ball_.draw();
}

void Level::initBonus()
{
	int row = 0;
	for (row; row < (int)field_.size(); row++)
	{
		for (auto brick : field_[row])
		{
			brick.getBonus().draw();
		}
	}
}

void Level::changePaddlePos(bool right)
{
	if (!right)
	{
		if (paddle_.getCenter().getX() + paddle_.getWidth() < 220)
			return;
		else 
			paddle_.move(-(paddle_.getSpeed()), 0);
	}
	else
	{
		if (paddle_.getCenter().getX() + paddle_.getWidth()  > 620)
			return;
		else 
			paddle_.move(paddle_.getSpeed(), 0);
	}
}

void Level::deleteBrick(int row, int num)
{
	field_[row][num].setDel();
}

void Level::strengthBrick(int row, int num, Strength str)
{
  field_[row][num].setStrength(str);
}


void Level::collideBallPaddle()
{
  Point check((paddle_.getWidth()) / 2 + ball_.getRad(), (paddle_.getHeight() / 2));
  Point diff = ball_.getCenter() - paddle_.getCenter();
  if (diff.fabsP() <= check)
	  ball_.collide(TypeCollision::Y);
}

void Level::collideBonusPaddle()
{
	Point check((paddle_.getWidth()) / 2, (paddle_.getHeight() / 2));
	Point diff = activeBonus.getCenter() - paddle_.getCenter();
	if (diff.fabsP() <= check)
	{
		switch (activeBonus.getType())
		{
		  case BonusType::NONE:
			  break;
			case BonusType::SPEED_PLUS:
			  ball_.setSpeedX(10);
				ball_.setSpeedY(10);
				break;
			case BonusType::SPEED_MINUS:
				ball_.setSpeedX(-10);
				ball_.setSpeedY(-10);
				break;
			case BonusType::PADDLE_PLUS:
			  paddle_.setWidth(20);
				break;
			case BonusType::PADDLE_MINUS:
				paddle_.setWidth(-10);
				break;
			case BonusType::EXTRA_POINTS:
			  score_ += 1000;
				break;
			case BonusType::LIFE:
			  ball_.setLives(1);
				break;
	  }
	}
}

void Level::collideBallBrick()
{
  Bonus tmp;
	int row = 0;
	for (row; row < (int)field_.size(); row++)
	{
		int counter = 0;
		for (auto brick : field_[row])
		{ 
			Point check((brick.getWidth()) / 2 + ball_.getRad(), (brick.getHeight() / 2)/* + ball_.getRad()*/);
			Point diff = ball_.getCenter() - brick.getCenter();
			if (diff.fabsP() <= check && !brick.getDel())
			{
			  score_ += 100;
				switch (brick.getStrength())
				{
				case (Strength::WEAK):
					ball_.collide(TypeCollision::Y);
					if (brick.getBonus().getType() != BonusType::NONE)
					{
						activeBonus = brick.getBonus();
						activeBonus.move(0, tmp.getSpeed());
					}
					deleteBrick(row, counter);
					break;
				case (Strength::MIDDLE):
					ball_.collide(TypeCollision::XY);
					strengthBrick(row, counter, Strength::WEAK);
					break;
				case (Strength::HARD):
					ball_.collide(TypeCollision::XY);
					strengthBrick(row, counter, Strength::MIDDLE);
					break;
				}
			}
			counter++;
		}
	}
}

void Level::moveBall()
{
	if (ball_.getCenter().getX() + ball_.getRad() < 120)
	  ball_.collide(collX);
	else if (ball_.getCenter().getX() + ball_.getRad() > 590)
		ball_.collide(collX);
	else if (ball_.getCenter().getY() + ball_.getRad() > 420)
		ball_.collide(collY);
	else if (ball_.getCenter().getY() + ball_.getRad() < 0)
	{
		ball_.setLives(-1);
		if (ball_.getLives() == 0)
		{
		  drawFinal();
			return;
		}
		finish();
	}
  ball_.move(ball_.getSpeedX(), ball_.getSpeedY());
}

void Level::drawLives()
{
	glColor3f(1.0f, 1.0f, 1.0f);
  int lives = ball_.getLives();
	glRasterPos2f(60, 440);
	std::string str = "Lives ";
	for (auto c : str)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, lives+48);
}

void Level::drawScore()
{ 
  glColor3f(1.0f, 1.0f, 1.0f);
  char* s = new char[15];
	glRasterPos2f(400, 440);
	std::string str = "Score ";
	for (auto c : str)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	str = std::to_string(score_);
	for (auto c : str)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}

void Level::drawFinal()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(60, 440);
	std::string str = "You lose";
	for (auto c : str)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}