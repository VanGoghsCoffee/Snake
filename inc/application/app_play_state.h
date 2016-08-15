#pragma once

#include "app_state.h"

namespace Game
{
  class CPlayState : public CState
  {
  public:
    CPlayState(void);
    ~CPlayState(void);

    virtual bool InternOnEnter();
    virtual int InternOnRun();
    virtual bool InternOnLeave();

  private:
    // implement ticker here
  };
}
