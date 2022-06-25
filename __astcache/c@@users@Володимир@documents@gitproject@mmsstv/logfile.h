//Copyright+LGPL

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
#ifndef LogFileH
#define LogFileH

#include "ComLib.h"
//---------------------------------------------------------------------------
#define	MMLOGID	"MMLOG DATA Ver1.00\032"

typedef struct {	// Log‚М“®ЌмѓIѓvѓVѓ‡ѓ“
	char	m_TimeZone;				// •\Ћ¦—pѓ^ѓCѓЂѓ]Ѓ[ѓ“

	int		m_UpperName;			// ‘е•¶Ћљ‚Ц‚М•ПЉ·
	int		m_UpperQTH;				// ‘е•¶Ћљ‚Ц‚М•ПЉ·
	int		m_UpperREM;				// ‘е•¶Ћљ‚Ц‚М•ПЉ·
	int		m_UpperQSL;				// ‘е•¶Ћљ‚Ц‚М•ПЉ·

	int		m_DefMyRST;				// 0-OFF, 1-ON

	int		m_CopyFreq;				// 0-Band, 1-Freq
	int		m_CopyHis;				// 0-599, 1-599001, 2-599UTC
	int		m_CopyName;				// 0-OFF, 1-ON
	int		m_CopyQTH;				// 0-OFF, 1-ON
	int		m_CopyREM;				// 0-OFF, 1-ON
	int		m_CopyQSL;				// 0-OFF, 1-ON
	int		m_CopyREMB4;			// 0-OFF, 1-ON

	int		m_AutoSave;				// Ћ©“®ѓZЃ[ѓu

	int		m_QSOMacroFlag;			// 0-OFF, 1-ON
	int		m_CheckBand;			// “Ї€кѓoѓ“ѓh‚Е‚МЏd•Ў‚рѓ`ѓFѓbѓN
	int		m_QSOMacro[5];			// 0-Run 1st, 1-Run 2nd, 2-Run Dupe, 3-S&P 1st, 4-S&P 2nd
	WORD	m_QSOMacroKey[5];
	AnsiString	m_QSOMacroStr[5];

	AnsiString	m_THRTTY;
	AnsiString	m_THSSTV;
	int     m_THTZ;
	int		m_ClipRSTADIF;
	int		m_DateType;

    int		m_FSKNR;				// ѓRѓ“ѓeѓXѓgNR‚рFSKID‚ЙЉЬ‚Я‚й
    int		m_Backup;				// ѓoѓbѓNѓAѓbѓvЌмђ¬

	BYTE	m_Hamlog5Len[17];
}LOGSET;

#define	MLCALL	16		/* є°Щ»ІЭ‚М’·‚і		*/
#define	MLRST	20		/* RSTѓiѓ“ѓo‚М’·‚і	*/
#define	MLREM	56		/* ‹LЋ–‚М’·‚і		*/
#define	MLNAME	16		/* –ј‘O‚М’·‚і		*/
#define	MLQTH	28		/* ‚p‚s‚g‚М’·‚і		*/
#define	MLQSL	54		/* ‚p‚r‚k‚М’·‚і		*/
#define	MLPOW	4		/* “d—Н				*/
#define	MLOPT	8		/* ѓIѓvѓVѓ‡ѓ“		*/

#define MODEMAX	48

#define	YEAR(c)	(((c)<50)?(2000+(c)):(1900+(c)))

#pragma option -a-	// ѓpѓbѓN‚МЋwЋ¦
typedef struct {			/* ‚l‚l‚k‚n‚fѓfЃ[ѓ^Њ`Ћ®	*/
	BYTE	year;		/* ”N		*/
	WORD	date;			/* “ъ•t		*/
	WORD	btime;			/* ЉJЋnЋћЌЏ	*/
	WORD	etime;			/* ЏI—№ЋћЌЏ	*/
	char	call[MLCALL+1];	/* є°Щ»ІЭ	*/
	char	ur[MLRST+1];	/* T ШОЯ°Д	*/
	char	my[MLRST+1];	/* R ШОЯ°Д	*/
	BYTE	band;		/* КЮЭДЮ	*/
	SHORT	fq;				/* Ћь”gђ”	*/
	BYTE	mode;		/* У°ДЮ		*/
	char	pow[MLPOW+1];	/* “d—Н		*/
	char	name[MLNAME+1];	/* –ј‘O		*/
	char	qth[MLQTH+1];	/* QTH		*/
	char	qsl[MLQSL+1];	/* QSL		*/
	char	send;			/* QSL ‘—ђM	*/
	char	recv;			/* QSL ЋуђM	*/
	char	cq;				/* cq/call	*/
	WORD	env;			/* Ћ©‹ЗЉВ‹«	*/
	char	rem[MLREM+1];	/* ‹LЋ–		*/
	char	opt1[MLOPT+1];	/* µМЯј®Э	*/
	char	opt2[MLOPT+1];	/* µМЯј®Э2	*/
}SDMMLOG;

#define	FHDOFF	256			/* ђж“Є‚Мѓwѓbѓ_‚МѓIѓtѓZѓbѓg		*/
#define	UMODEMAX	32
typedef struct {
	char	id[20];			/* ѓtѓ@ѓCѓ‹ѓoЃ[ѓWѓ‡ѓ“			*/
	char	dmy[4];			/* ѓ_ѓ~Ѓ[—М€ж					*/
	USHORT	mlt;			/* ѓ}ѓ‹ѓ`Џо•с‚МѓTѓCѓY			*/
	char	td;				/* ЋћЌ·ѓRЃ[ѓh					*/
	char	hash;			/* ѓnѓbѓVѓ…ѓfЃ[ѓ^Љi”[ѓtѓ‰ѓO		*/
	long	size;			/* ѓfЃ[ѓ^ѓTѓCѓY					*/
	char	master;			/* ѓ}ѓXѓ^Ѓ[ѓtѓ@ѓCѓ‹ѓtѓ‰ѓO		*/
	char	dm2[15];		/* ѓ_ѓ~Ѓ[‚Q						*/
	char	mode[UMODEMAX][6];	/* ѓ†Ѓ[ѓU’и‹`ѓ‚Ѓ[ѓh				*/
}FHD;
#pragma option -a.	// ѓpѓbѓN‰рЏњ‚МЋwЋ¦

class CIndex
{
private:
	int		m_IndexMax;		// Љm•Ы’†‚МѓCѓ“ѓfѓbѓNѓX‚Мђ”
	int		m_IndexCnt;		// Њ»ЌЭ‚МѓCѓ“ѓfѓbѓNѓX‚Мђ”
	LPSTR	pIndex;			// ѓCѓ“ѓfѓbѓNѓX—М€ж‚Мѓ|ѓCѓ“ѓ^(16ѓoѓCѓgѓCѓ“ѓfѓbѓNѓX)
	BYTE	*pMult;			// ѓ}ѓ‹ѓ`Џо•с‚Мѓ|ѓCѓ“ѓ^
public:
	CIndex();
	~CIndex();
	void AllocIndex(int n);
	void ClearIndex(void);
	void WriteIndex(LPCSTR pCall, int n);
	void ReadIndex(LPSTR pCall, int n);
	LPSTR PointIndex(int n);
	void AddBlock(LPCSTR p, int len);
	int ReadIndex(int handle, FHD *hp);
	void MakeIndex(int handle, FHD *hp);
	int WriteIndex(int handle, FHD *hp);


};

#define	FINDMAX		32768
class CLogFind
{
public:
	int			m_FindCnt;
	int			m_FindCmp1Max;
	int			m_FindCmp2Max;
	int			m_FindStr1Max;
	int			m_FindStr2Max;

	int			*pFindTbl;
	AnsiString	m_FindStr;
public:
	CLogFind();
	~CLogFind();
	inline int GetCount(void){return m_FindCnt;};
	inline void Clear(void){
		m_FindCnt = m_FindCmp1Max = m_FindCmp2Max = m_FindStr1Max = m_FindStr2Max = 0;
	};
	int Add(int n);
	void Ins(int n);

	inline void Write(int n){
		pFindTbl[m_FindCnt] = n;
		m_FindCnt++;
	};
	inline void SetText(LPCSTR p){
		if( p != m_FindStr.c_str() ){
			m_FindStr = p;
		}
	};
	inline LPCSTR GetText(void){
		return m_FindStr.c_str();
	};
	inline void ClearText(void){
		m_FindStr = "";
	};
};

class CLogFile
{
private:
	int		m_Open;			// ѓIЃ[ѓvѓ“ѓtѓ‰ѓO
	int		m_EditFlag;		// •ТЏWѓtѓ‰ѓO
	int		m_Handle;		// ѓtѓ@ѓCѓ‹ѓnѓ“ѓhѓ‹
	CIndex	m_Index;		// Њ»ЌЭѓIЃ[ѓvѓ“’†‚МѓCѓ“ѓfѓbѓNѓX
	FHD		m_fhd;			// Њ»ЌЭѓIЃ[ѓvѓ“’†‚Мѓtѓ@ѓCѓ‹ѓwѓbѓ_
	AnsiString	m_Name;		// ѓЌѓOѓtѓ@ѓCѓ‹‚М–ј‘O
	char	m_modebuf[8];
public:
	AnsiString	m_FileName;	// ѓЌѓOѓtѓ@ѓCѓ‹‚М–ј‘OЃiѓtѓ‹ѓpѓXЃj

	int		m_CurNo;
	int		m_CurChg;
	SDMMLOG	m_sd;
	SDMMLOG	m_bak;
	SDMMLOG	m_asd;

	CLogFind	m_Find;		// ѓJѓЊѓ“ѓgЊџЌхѓfЃ[ѓ^
	LOGSET		m_LogSet;
private:
	void SetHisRST(SDMMLOG *sp);
	void InitHeader(void);

public:
	CLogFile();
	~CLogFile();

	void DoBackup(void);

	int Open(LPCSTR pName, BOOL fNew);
	int Close(void);

	void ReadIniFile(LPCSTR pKey, TMemIniFile *pIniFile);
	void WriteIniFile(LPCSTR pKey, TMemIniFile *pIniFile);

	void MakeIndex(void);

	inline IsEdit(void){return m_EditFlag;};
	void MakePathName(LPCSTR pName);
	void MakeName(LPCSTR pName);
	inline LPCSTR GetName(void){return m_Name.c_str();};

	inline int GetCount(void){return m_fhd.size;};
	inline int IsOpen(void){return m_Open;};
	int GetData(SDMMLOG *sp, int n);
	int PutData(SDMMLOG *sp, int n);

	LPCSTR GetDateString(SDMMLOG *sp, int sw);
	inline LPCSTR GetDateString(SDMMLOG *sp){ return GetDateString(sp, m_LogSet.m_DateType); };
	LPCSTR GetTimeString(WORD d);


	LPCSTR GetModeString(BYTE m);
	void SetMode(SDMMLOG *sp, LPCSTR s);

	LPCSTR GetFreqString(BYTE b, short fq);
	void SetFreq(SDMMLOG *sp, LPCSTR p);
	LPCSTR GetOptStr(int n, SDMMLOG *sp);
	void SetOptStr(int n, SDMMLOG *sp, LPCSTR pOpt);

	void CopyAF(void);

	void SortDate(int bb, int eb);
	int FindSameBand(void);
	int FindSameDate(void);

	void FindStrSet(CLogFind *fp, LPCSTR pCall);
	int FindCmpSet(CLogFind *fp, LPCSTR pCall);
	int FindClipSet(CLogFind *fp, LPCSTR pCall);
	int FindSet(CLogFind *fp, LPCSTR pCall);
	int Find(LPCSTR pCall, int b, int dir);
	int IsAlready(LPCSTR pCall);
	void DeleteAll(void);
	void DeleteLast(void);
	void Delete(int top, int end);
	void Insert(int n, SDMMLOG *sp);

	void InitCur(void);
	void SetLastPos(void);

	int ReadAscii(SDMMLOG *sp, LPSTR p);

};

void JSTtoUTC(int &Year, int &Mon, int &Day, int &Hour);
void JSTtoUTC(SDMMLOG *sp);
void UTCtoJST(int &Year, int &Mon, int &Day, int &Hour);
void UTCtoJST(SDMMLOG *sp);
void UTCtoJST(SYSTEMTIME *tp);
void mBandToBand(SDMMLOG *sp, LPCSTR p);
LPCSTR FreqTomBand(SDMMLOG *sp);
int GetLMode(BYTE m);

extern	CLogFile	Log;
extern	const char	MONN[];
extern	const char	MONU[];
#endif

