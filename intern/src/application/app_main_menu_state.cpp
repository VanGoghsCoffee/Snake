#include "app_main_menu_state.h"

namespace Game
{
  CMainMenuState::CMainMenuState(void)
  {
  }

  CMainMenuState::~CMainMenuState(void)
  {
  }

  bool CMainMenuState::InternOnEnter()
  {
    return true;
  }

  int CMainMenuState::InternOnRun()
  {
    return 1;
  }

  bool CMainMenuState::InternOnLeave()
  {
    return true;
  }
  
}
