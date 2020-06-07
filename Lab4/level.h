#pragma once
#include <vector>
#include <string>
#include "brick.h"
#include "paddle.h"
#include "ball.h"

class Level 
{
  private:
    std::vector<std::vector<Brick>> field_;
    Ball ball_;
    Paddle paddle_;
    int score_;
  public:
    Level(std::string filename);
    void start();
    void changePaddlePos(bool right);
    void initPaddle();
    void initBall();
    void initBonus();
    void moveBall();
    void collideBallBrick();
    void collideBallPaddle();
    void collideBonusPaddle();
  protected:
    void finish();
    int getLives() { return ball_.getLives(); }
    void deleteBrick(int row, int num);
    void strengthBrick(int row, int num, Strength str);
    void drawLives();
    void drawScore();
    void drawFinal();
    void drawBorders();
};

Brick CreateBrick(Point p, std::vector<Brick> row, std::string tmp, BonusType type, Strength strength);
std::vector<Brick> ParcingString(std::string str, float x, float y);
