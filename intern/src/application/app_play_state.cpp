#include "app_play_state.h"

namespace Game
{
  CPlayState::CPlayState(void)
  {
  }

  CPlayState::~CPlayState(void)
  {
  }

  bool CPlayState::InternOnEnter()
  {
    return true;
  }

  int CPlayState::InternOnRun()
  {
    return CState::Play;
  }

  bool CPlayState::InternOnLeave()
  {
    return true;
  }
} // namespace Game
