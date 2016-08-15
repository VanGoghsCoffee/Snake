#pragma once

class View;

class Field
{

 public:
  enum { WIDTH = 40, HEIGHT = 40 };
  enum { BLOCK_WIDTH = 15, BLOCK_HEIGHT = 15 };
  enum Type { EMPTY, SNAKE_BLOCK, FRUIT };

 public:  
  Field();
  void SetBlock(Type _Type, int _X, int _Y);
  Type GetBlock(int _X, int _Y) const;
  void Draw(View &) const;
  void NewFruit();

 private:
  Type m_[HEIGHT][WIDTH];
};
