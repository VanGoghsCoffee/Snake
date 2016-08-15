#pragma once

#include "field.h"
#include "snake.h"

namespace Game
{
  class View;
  
  class SnakeGame
  {
  public:
    void Tick();
    void Draw(View &) const;
    void KeyEvent(Snake::Direction);

  private:
    Field m_Field;
    Snake m_Snake;
  };
}
