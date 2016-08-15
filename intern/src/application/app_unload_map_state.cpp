#include "app_unload_map_state.h"

namespace Game
{
    CUnloadMapState::CUnloadMapState(void)
    {
    }

    CUnloadMapState::~CUnloadMapState(void)
    {
    }

    bool CUnloadMapState::InternOnEnter()
    {
        return true;
    }

    int CUnloadMapState::InternOnRun()
    {
        return CState::MainMenu;
    }

    bool CUnloadMapState::InternOnLeave()
    {
        return true;
    }
} // namespace Game
