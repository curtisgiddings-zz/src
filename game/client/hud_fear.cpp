//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
//
// battery.cpp
//
// implementation of CHudFear class
//
#include "cbase.h"
#include "c_baseplayer.h"
#include "c_basehlplayer.h"
#include "hud.h"
#include "hudelement.h"
#include "hud_macros.h"
#include "hud_numericdisplay.h"
#include "iclientmode.h"

#include "vgui_controls/AnimationController.h"
#include "vgui/ILocalize.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"


//-----------------------------------------------------------------------------
// Purpose: Displays suit power (armor) on hud
//-----------------------------------------------------------------------------
class CHudFear : public CHudNumericDisplay, public CHudElement
{
	DECLARE_CLASS_SIMPLE( CHudFear, CHudNumericDisplay );

public:
	CHudFear( const char *pElementName );
	void Init( void );
	void Reset( void );
	void VidInit( void );
	void OnThink( void );
};

DECLARE_HUDELEMENT( CHudFear );

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
CHudFear::CHudFear( const char *pElementName ) : BaseClass(NULL, "HudFear"), CHudElement( pElementName )
{
	SetHiddenBits( HIDEHUD_HEALTH /*| HIDEHUD_NEEDSUIT*/ );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudFear::Init( void )
{
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudFear::Reset( void )
{

	wchar_t *tempString = g_pVGuiLocalize->Find("#Hud_Fear");

	if (tempString)
	{
		SetLabelText(tempString);
	}
	else
	{
		SetLabelText(L"FEAR");
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudFear::VidInit( void )
{
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudFear::OnThink( void )
{
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();

	if ( pPlayer )
		SetDisplayValue(pPlayer->GetFear());
}