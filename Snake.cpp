#include "Field.h"
#include "Snake.h"
#include  <cstdlib>

Snake::Snake()
  :m_Direction(static_cast<Direction>(rand() % 4))
  ,m_LastMove(m_Direction)
{
  m_Blocks.push_back(std::pair<int, int>(Field::WIDTH / 2, Field::HEIGHT / 2));
}

bool Snake::Tick(Field &_Field)
{
  m_LastMove = m_Direction;
  std::pair<int, int> p = m_Blocks.front();
  switch (m_Direction)
  {
  case LEFT:
    --p.first;
    break;
  case UP:
    --p.second;
    break;
  case RIGHT:
    ++p.first;
    break;
  case DOWN:
    ++p.second;
    break;
  }
  if (p.first < 0 || p.first >= Field::WIDTH || p.second < 0 || p.second >= Field::HEIGHT)
    return false;

  if (_Field.GetBlock(p.first, p.second) == Field::SNAKE_BLOCK)
    return false;
  
  m_Blocks.push_front(p);

  if (_Field.GetBlock(p.first, p.second) != Field::FRUIT)
  {
    _Field.SetBlock(Field::SNAKE_BLOCK, p.first, p.second);
    std::pair<int ,int> p = m_Blocks.back();
    _Field.SetBlock(Field::EMPTY, p.first, p.second);
    m_Blocks.pop_back();
  }
  else
  {
    _Field.SetBlock(Field::SNAKE_BLOCK, p.first, p.second);
    _Field.NewFruit();
  }
  
  if (m_Blocks.size() >= Field::WIDTH * Field::HEIGHT - 1)
    return false;

  return true;
}

void Snake::KeyEvent(Direction _D)
{
  if (_D == m_Direction)
    return;

  switch (_D)
  {
  case LEFT:
    if (m_LastMove == RIGHT)
      return;
    break;
  case UP:
    if (m_LastMove == DOWN)
      return;
    break;
  case RIGHT:
    if (m_LastMove == LEFT)
      return;
    break;
  case DOWN:
    if (m_LastMove == UP)
      return;
    break;
  }

  m_Direction = _D;
}
