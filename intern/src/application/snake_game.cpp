#include "field.h"
#include "snake_game.h"
#include "view.h"

#include "GLUT/glut.h"

namespace Game
{
  void SnakeGame::Tick()
  {
    if (!m_Snake.Tick(m_Field))
      {
	m_Snake = Snake();
	m_Field = Field();
      }
  }
  
  void SnakeGame::Draw(Game::View &_View) const
  {
    m_Field.Draw(_View);
  }
  
  void SnakeGame::KeyEvent(Snake::Direction _D)
  {
    m_Snake.KeyEvent(_D);
  }
} // namspace Game
