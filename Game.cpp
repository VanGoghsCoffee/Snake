#include "Field.h"
#include "Game.h"
#include "View.h"

void Game::Tick()
{
  if (!m_Snake.Tick(m_Field))
  {
    m_Snake = Snake();
    m_Field = Field();
  }
}

void Game::Draw(View &_View) const
{
  m_Field.Draw(_View);
}

void Game::KeyEvent(Snake::Direction _D)
{
  m_Snake.KeyEvent(_D);
} 
