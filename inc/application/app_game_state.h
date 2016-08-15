#pragma once

#include "app_state.h"

class CGameState : public Game::CState
{
  CGameState(void);
  ~CGameState(void);

  virtual bool InternOnEnter();
  virtual int  InternOnRun();
  virtual bool InternOnLeave();
};
