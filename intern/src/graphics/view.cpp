#include "view.h"

#include "OpenGL/gl.h"

namespace Game
{  
  void View::DrawBar(int _X1, int _Y1, int _X2, int _Y2)
  {
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(_X1, _Y1);
    glVertex2f(_X2, _Y1);
    glVertex2f(_X2, _Y2);
    glVertex2f(_X1, _Y1);
    glEnd();
  }

  void View::DrawCircle(int _X, int _Y, int _Radius)
  {
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(_X + _Radius, _Y);
    glVertex2f(_X, _Y + _Radius);
    glVertex2f(_X - _Radius, _Y);
    glVertex2f(_X, _Y - _Radius);
    glEnd();
  }
} // namespace Game
