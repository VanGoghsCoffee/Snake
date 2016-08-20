#include "app_main.h"
#include "snake_game.h"
#include "view.h"

#include <iostream>
#include "GLUT/glut.h"

namespace Game
{
  // Sorry for global variable
  // needed for gluts display function
  SnakeGame snakeGame;
  
  void KeyEvent(int _Key, int, int)
  {
    switch (_Key)
    {
    case GLUT_KEY_LEFT:
      snakeGame.KeyEvent(Snake::LEFT);
      break;
    case GLUT_KEY_UP:
      snakeGame.KeyEvent(Snake::UP);
      break;
    case GLUT_KEY_RIGHT:
      snakeGame.KeyEvent(Snake::RIGHT);
      break;
    case GLUT_KEY_DOWN:
      snakeGame.KeyEvent(Snake::DOWN);
      break;
    }
  }

  void Display()
  {
    View v;
    glClear(GL_COLOR_BUFFER_BIT);
    snakeGame.Draw(v);
    glutSwapBuffers();
  }

  void Timer(int = 0)
  {
    snakeGame.Tick();
    Display();
    glutTimerFunc(100, Game::Timer, 0);
  }
  
  CApplication::CApplication(void)
    : m_pInputConsoleHandle(nullptr)
    , m_pCurrentState      (nullptr)
    , m_PlayState          ()
    , m_LoadMapState       ()
    , m_MainMenuState      ()
    , m_StartupState       ()
    , m_ShutdownState      ()
    , m_UnloadMapState     ()
  {
  }

  void CApplication::OnStart(int argc, char **argv)
  {
    // added couts for checking if glut loads everything
    // it's supposed to. Poor mans choice -> but it works
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
  }

  void CApplication::OnRun()
  {
    m_StartupState.OnEnter();
    m_pCurrentState = &m_StartupState;
    glutMainLoop();

    // Implemented states
    // glut comes with it's own game loop which I'm using
    // for this project
    /*for (;;)
    {
      switch (m_pCurrentState->OnRun())
      {
      case 0:
	break;

      case CState::Startup:
	OnTransition(m_StartupState);
	break;

      case CState::LoadMap:
	OnTransition(m_LoadMapState);
	break;

      case CState::MainMenu:
	OnTransition(m_MainMenuState);
	break;

      case CState::Play:
	OnTransition(m_PlayState);
	// glutMainLoop();
	break;

      case CState::UnloadMap:
	OnTransition(m_UnloadMapState);
	break;

      case CState::Shutdown:
	return;
      } 
      }*/
  }

  void CApplication::OnExit()
  {
    if (m_pCurrentState != nullptr)
    {
      m_pCurrentState->OnLeave();
    }

    m_ShutdownState.OnEnter();
    m_ShutdownState.OnRun();
    m_ShutdownState.OnLeave();
  }

  bool CApplication::OnTransition(CState& _rState)
  {
    if (m_pCurrentState->OnLeave() == false)
    {
      return false;
    }

    m_pCurrentState = &_rState;

    return m_pCurrentState->OnEnter();
  }

  void CApplication::OnInputEvent()
  {
  }
}
