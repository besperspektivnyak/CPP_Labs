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
  public:
    Level(std::string filename);
    void start();
    void finish();
};