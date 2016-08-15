#include "app_main.h"
#include "snake_game.h"
#include "view.h"

#include <iostream>
#include "GLUT/glut.h"

namespace Game
{ 
  void KeyEvent(int _Key, int, int)
  {
    SnakeGame snakeGame;
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
    SnakeGame snakeGame;
    glClear(GL_COLOR_BUFFER_BIT);
    View v;
    snakeGame.Draw(v);
    glutSwapBuffers();
  }

  void Timer(int = 0)
  {
    SnakeGame snakeGame;
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
    , m_SnakeGame          ()
  {
  }

  void CApplication::OnStart(int argc, char **argv)
  {
    std::cout << "OnStart::::" << std::endl;
    glutInit(&argc, argv);
    std::cout << "after glutInit" << std::endl;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    std::cout << "after glutInitDisplayMode" << std::endl;
    glutInitWindowSize(Field::WIDTH * Field::BLOCK_WIDTH, Field::HEIGHT * Field::BLOCK_HEIGHT);
    std::cout << "after glutInitWindowSize" << std::endl;
    glutInitWindowPosition(100, 780);
    std::cout << "after GlutInitWindowPosition" << std::endl;
    glutCreateWindow("Snake");
    std::cout << "after glutCreateWindow" << std::endl;
    glClearColor(0, 0, 0, 1.0);
    std::cout << "after glClearColor" << std::endl;
    glMatrixMode(GL_PROJECTION);
    std::cout << "after glMatrixMode" << std::endl;
    glLoadIdentity();
    std::cout << "after glLoadIdentity" << std::endl;
    glOrtho(0, Field::WIDTH * Field::BLOCK_WIDTH, Field::HEIGHT * Field::BLOCK_HEIGHT, 0, -1.0, 1.0);
    std::cout << "after glOrtho" << std::endl;
    glutDisplayFunc(Display);
    std::cout << "after glutDisplayFunc" << std::endl;
    glutSpecialFunc(KeyEvent);
    std::cout << "after glutSpecialFunc" << std::endl;
    Timer();
    std::cout << "after TimerInit" << std::endl;
  }

  void CApplication::OnRun()
  {
    m_StartupState.OnEnter();
    m_pCurrentState = &m_StartupState;
    glutMainLoop();
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
