#pragma once

#include <list>

namespace Game
{
  class Field;
  
  class Snake
  {
  public:
    enum Direction { LEFT, UP, RIGHT, DOWN };
    Snake();
    bool Tick(Field &);
    void KeyEvent(Direction);
    
  private:
    typedef   std::list<std::pair<int, int>> Blocks;
    Blocks    m_Blocks;
    Direction m_Direction;
    Direction m_LastMove;
  };
} // namespace Game
