#include "Game.h"
#include "View.h"

#include "GLUT/glut.h"

Game game;

void Display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  View v;
  game.Draw(v);
  glutSwapBuffers();
}

void Timer(int = 0)
{
  game.Tick();
  Display();
  glutTimerFunc(100, Timer, 0);
}

void KeyEvent(int _Key, int, int)
{
  switch (_Key)
  {
  case GLUT_KEY_LEFT:
    game.KeyEvent(Snake::LEFT);
    break;
  case GLUT_KEY_UP:
    game.KeyEvent(Snake::UP);
    break;
  case GLUT_KEY_RIGHT:
    game.KeyEvent(Snake::RIGHT);
    break;
  case GLUT_KEY_DOWN:
    game.KeyEvent(Snake::DOWN);
    break;
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(Field::WIDTH * Field::BLOCK_WIDTH, Field::HEIGHT * Field::BLOCK_HEIGHT);
  glutInitWindowPosition(100, 780);
  glutCreateWindow("Snake");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, Field::WIDTH * Field::BLOCK_WIDTH, Field::HEIGHT * Field::BLOCK_HEIGHT, 0, -1.0, 1.0);
  glutDisplayFunc(Display);
  glutSpecialFunc(KeyEvent);
  Timer();

  glutMainLoop();
}
