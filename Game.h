#pragma once

#include "Field.h"
#include "Snake.h"

class View;

class Game
{
 public:
  void Tick();
  void Draw(View &) const;
  void KeyEvent(Snake::Direction);

 private:
  Field m_Field;
  Snake m_Snake;
};
