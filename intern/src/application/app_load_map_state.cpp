#include "app_load_map_state.h"

namespace Game
{
    CLoadMapState::CLoadMapState(void)
    {
    }

    CLoadMapState::~CLoadMapState(void)
	{
	}

	bool CLoadMapState::InternOnEnter()
	{
	    return true;
	}

	int CLoadMapState::InternOnRun()
	{
        return CState::Play;
	}

	bool CLoadMapState::InternOnLeave()
	{
	    return true;
	}
} // namespace Game
