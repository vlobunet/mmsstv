﻿//Copyright+LGPL

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Copyright 2000-2013 Makoto Mori, Nobuyuki Oba
//-----------------------------------------------------------------------------------------------------------------------------------------------
// This file is part of MMSSTV.

// MMSSTV is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// MMSSTV is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License along with MMTTY.  If not, see 
// <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------
#ifndef CtrBtnH
#define CtrBtnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#include "ComLib.h"
//---------------------------------------------------------------------------
class TCtrBtnWnd : public TForm
{
__published:	// IDE ЉЗ—ќ‚МѓRѓ“ѓ|Ѓ[ѓlѓ“ѓg
	TSpeedButton *SBRXStop;
	TSpeedButton *SBHist;
	TSpeedButton *SBTX;
	TSpeedButton *SBLock;
	TSpeedButton *SBSync;
	void __fastcall SBTXClick(TObject *Sender);
	void __fastcall SBRXStopClick(TObject *Sender);
	void __fastcall SBHistClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall SBLockClick(TObject *Sender);
	
	void __fastcall SBSyncClick(TObject *Sender);
	
private:	// ѓ†Ѓ[ѓUЃ[ђйЊѕ
	CAlignList  AlignView;

public:		// ѓ†Ѓ[ѓUЃ[ђйЊѕ
	__fastcall TCtrBtnWnd(TComponent* Owner);
	void __fastcall UpdateBtn(void);
	void __fastcall GetViewPos(int &x, int &y, int &w, int &h){
		x = Left;
		y = Top;
		w = ClientWidth;
		h = ClientHeight;
	};
	void __fastcall SetViewPos(int x, int y, int w, int h){
		Left = x;
		Top = y;
		ClientWidth = w;
		ClientHeight = h;
	};
};
//---------------------------------------------------------------------------
//extern PACKAGE TCtrBtnWnd *CtrBtnWnd;
//---------------------------------------------------------------------------
#endif
 
