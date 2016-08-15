#include "field.h"
#include "view.h"
#include <cstdlib>

namespace Game
{
  Field::Field()
  {
    for (int y = 0; y < HEIGHT; ++y)
    {
      for (int x = 0; x < WIDTH; ++x)
      {
	m_[y][x] = EMPTY;
      }
    }
    NewFruit();
  }

  void Field::SetBlock(Type _Type, int _X, int _Y)
  {
    m_[_Y][_X] = _Type;
  }

  Field::Type Field::GetBlock(int _X, int _Y) const
  {
    return m_[_Y][_X];
  }

  void Field::Draw(View &p) const
  {
    for (int y = 0; y < HEIGHT; ++y)
    {
      for (int x = 0; x < WIDTH; ++x)
      {
	switch (m_[y][x])
	{
	case EMPTY:
	  break;
	case SNAKE_BLOCK:
	  p.DrawBar(x * BLOCK_WIDTH,
		    y * BLOCK_HEIGHT,
		    (x + 1) * BLOCK_WIDTH - 1,
		    (y + 1) * BLOCK_HEIGHT -1);
	  break;
	case FRUIT:
	  p.DrawCircle(x * BLOCK_WIDTH + BLOCK_WIDTH / 2,
		       y * BLOCK_HEIGHT + BLOCK_HEIGHT / 2,
		       BLOCK_WIDTH / 2 - 1);
	  break;
	}
      }
    }
  }


  void Field::NewFruit()
  {
    int x;
    int y;
    
    do
    {
      x = rand() % WIDTH;
      y = rand() % HEIGHT;
    } while (GetBlock(x, y) != EMPTY);
    SetBlock(FRUIT, x, y);
  }
} // namespace Game
