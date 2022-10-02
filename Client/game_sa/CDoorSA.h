/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CDoorSA.h
 *  PURPOSE:     Header file for vehicle door entity class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include <game/CDoor.h>
#include <CVector.h>
#include "Common.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// 006f47e0      public: FLOAT __thiscall CDoor::GetAngleOpenRatio()const
#define FUNC_GetAngleOpenRatio      0x6f47e0
// 006f4800      public: bool __thiscall CDoor::IsClosed()const
#define FUNC_IsClosed               0x6f4800
// 006f4820      public: bool __thiscall CDoor::IsFullyOpen()const
#define FUNC_IsFullyOpen            0x6f4820
// 006f4790      public: void __thiscall CDoor::Open(FLOAT)
#define FUNC_Open                   0x6f4790

class CDoorSAInterface
{
public:
    float m_fOpenAngle;
    float m_fClosedAngle;
    // got 2 8bit vars next so might as well make this 16bit and get more flags
    WORD m_nDirn;
    BYTE m_nAxis;
    BYTE m_nDoorState;
    // simulation variables
    float m_fAngle;
    float m_fPrevAngle;
    float m_fAngVel;
};
static_assert(sizeof(CDoorSAInterface) == 0x18, "Invalid size for CDoorSAInterface");

/**
 * \todo Why are some of these Get and some Ret, is there a difference?
 */
class CDoorSA : public CDoor
{
private:
    CDoorSAInterface* internalInterface;

public:
    // constructor
    CDoorSA(CDoorSAInterface* doorInterface = 0) { internalInterface = doorInterface; };

    void              SetInterface(CDoorSAInterface* doorInterface) { internalInterface = doorInterface; }
    CDoorSAInterface* GetInterface() { return internalInterface; };

    float      GetAngleOpenRatio();
    BOOL       IsClosed();
    BOOL       IsFullyOpen();
    void       Open(float fOpenRatio);
    eDoorState GetDoorState() { return (eDoorState)this->GetInterface()->m_nDoorState; };
};
