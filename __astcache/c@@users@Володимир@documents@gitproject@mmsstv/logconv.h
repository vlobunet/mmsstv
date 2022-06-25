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
#ifndef LogConvH
#define LogConvH
#include "LogFile.h"

extern	const	char	*MONT1[];
extern	const	char	*MONT2[];
extern  const   char	*_BandText[];
//*************************************************************
// ѓЌѓO•ПЉ·‚МЉо–{ѓNѓ‰ѓX
//
class CLogConv
{
protected:
	int		m_Type;    		// 0-TEXT, 1-LOG200, 2-HAMLOG, 3-DBASE
	int		m_Mode;			// 0-Read, 1-Write
	FILE	*m_fp;

	AnsiString	m_FileName;		// •ПЉ·’†‚Мѓtѓ@ѓCѓ‹–ј
public:
	CLogConv();
	virtual ~CLogConv();
	virtual int IsOpen(void){return m_fp != NULL ? 1 : 0;};
	virtual int Open(LPCSTR pName)=0;
	virtual int Create(LPCSTR pName)=0;
	virtual int Close(void)=0;
	virtual int Read(SDMMLOG *sp)=0;
	virtual int Write(SDMMLOG *sp)=0;
};

#define	TEXTCONVMAX		64
typedef struct {
	int	w;
	AnsiString	Key;
}TCONV;

//*************************************************************
// ѓeѓLѓXѓgѓtѓ@ѓCѓ‹ѓAѓNѓZѓX‚МѓNѓ‰ѓX
//
class CLogText : public CLogConv
{
public:
	int		m_Double;
	int		m_Delm;
	TCONV	m_rConv[TEXTCONVMAX];
	TCONV	m_tConv[TEXTCONVMAX];
	int		m_UTC;
	int		m_err;
protected:
	char	m_bf[2048];			// ѓtѓ@ѓCѓ‹ѓoѓbѓtѓ@

private:
	int Text2MMLOG(SDMMLOG *sp, LPSTR p, int &err);
	void MMLOG2Text(LPSTR t, SDMMLOG *sp);

public:
	CLogText();
	virtual int Open(LPCSTR pName);
	virtual int Create(LPCSTR pName);
	virtual int Close(void);
	virtual int Read(SDMMLOG *sp);
	virtual int Write(SDMMLOG *sp);

};

void MMLOG2Text(LPSTR t, SDMMLOG *sp, AnsiString &Key);
int Text2MMLOG(SDMMLOG *sp, LPCSTR s, AnsiString &Key);
extern const LPCSTR ConvTbl[];
extern CLogText	LogText;

//*************************************************************
// ‚k‚n‚f‚Q‚O‚Oѓtѓ@ѓCѓ‹ѓAѓNѓZѓX‚МѓNѓ‰ѓX
//
#define	LOG200WIDTH		200
class CLog200 : public CLogConv
{
public:
	int		m_Index;
	int		m_err;
protected:
	char	m_bf[200];			// ѓtѓ@ѓCѓ‹ѓoѓbѓtѓ@
private:
public:
	CLog200();
	virtual int Open(LPCSTR pName);
	virtual int Create(LPCSTR pName);
	virtual int Close(void);
	virtual int Read(SDMMLOG *sp);
	virtual int Write(SDMMLOG *sp);
};

//*************************************************************
// ‚g‚`‚l‚k‚n‚fѓtѓ@ѓCѓ‹ѓAѓNѓZѓX‚МѓNѓ‰ѓX
//
#pragma option -a-	// ѓpѓbѓN‚МЋwЋ¦
typedef struct {
	char	Memo;		// 03h=ТУМЁ°ЩДЮ–і‚µ  83h=ТУМЁ°ЩДЮ—L‚иЃiHAMLOG‚Е‚Н 1AhЃj
	char	YY, MM, DD;	// ЌЕЏIЌXђV”NЊЋ“ъ
	long	Max;		// Ъє°ДЮЊЏђ”
	WORD	HeadLen;	// НЇАЮ‚М’·‚іЃiHAMLOG.DBS‚Н 449Ѓj
	WORD	DataLen;	// Ъє°ДЮ‚М’·‚іЃiHAMLOG.DBS‚Н 58Ѓj
	char	dummy[20];	// 00h
}DBSHD;

typedef struct {
	char	Memo;		// 03h=ТУМЁ°ЩДЮ–і‚µ  83h=ТУМЁ°ЩДЮ—L‚иЃiHAMLOG‚Е‚Н 1AhЃj
	char	YY, MM, DD;	// ЌЕЏIЌXђV”NЊЋ“ъ
	long	Max;		// Ъє°ДЮЊЏђ”
	char	dm1;
	char	m1;			// 01h
	char	dm2;
	char	dummy[21];	// 00h
	char	dummy2[255-32];	// 00h
	char	term;		// 1ah
}DBRHD;

typedef struct {
	char	Name[11];
	BYTE	Type;
	BYTE	dm1[4];
	BYTE	Len;
	BYTE	dm2[15];
}DBSLOT;

typedef struct {
	char	del[1];		/*	ЌнЏњѓ}Ѓ[ѓN	*/
	char	calls[7];	/*	є°Щ»ІЭ		*/
	char	potbl[3];	/*	€Ъ“®ґШ±		*/
	char	code[6]; 	/*	JCCє°ДЮ		*/
	char	glid[6];	/*	ёЮШЇДЮЫ№°А°	*/
	char	freq[4]; 	/*	Ћь”gђ”		*/
	char	mode[3]; 	/*	У°ДЮ		*/
	char	name[12]; 	/*	ЋЃ–ј		*/
	char	qsl [1]; 	/*	QSL via		*/
	char	send[1]; 	/*	QSL SEND	*/
	char	rcv[1]; 	/*	QSL RCV    	*/
	char	date[3]; 	/*	“ъ•t		*/
	char	time[2]; 	/*	ЋћЉФ		*/
	char	hiss[2]; 	/*	HIS RST		*/
	char	myrs[2]; 	/*	MY  RST		*/
	long	ofs;		/*	HAMLOG.DBR µМѕЇД±ДЮЪЅ	*/
}SDHAMLOG;

typedef struct {		/* DBR‚МѓtѓBЃ[ѓ‹ѓh€К’uѓfЃ[ѓ^	*/
	BYTE	LenQTH;
	BYTE	LenREM1;
	BYTE	LenREM2;
}FHDDBR;
#pragma option -a.	// ѓpѓbѓN‰рЏњ‚МЋwЋ¦

class CHamLog : public CLogConv
{
public:
	int		m_Index;
	int		m_err;
protected:
	DBSHD		m_hd;			// DBSѓwѓbѓ_
	SDHAMLOG	m_RecBuf;		// ѓЊѓRЃ[ѓhѓoѓbѓtѓ@

	AnsiString	m_DBRName;		// DBRѓtѓ@ѓCѓ‹‚М–ј‘O
	FILE		*m_dbrfp;		// DBRѓtѓ@ѓCѓ‹‚Мѓtѓ@ѓCѓ‹ѓ|ѓCѓ“ѓ^
	DBRHD		m_dbrhd;		// DBRѓwѓbѓ_
private:
	int 		Seek(DWORD Index);
	BOOL 		MakeHD(void);

public:
	CHamLog();
	virtual int Open(LPCSTR pName);
	virtual int Create(LPCSTR pName);
	virtual int Close(void);
	virtual int Read(SDMMLOG *sp);
	virtual int Write(SDMMLOG *sp);
};

void HAMLOGtoMMLOG(SDMMLOG *sp, SDHAMLOG *hp, FILE *dbrfp);
int MMLOGtoHAMLOG(SDHAMLOG *hp, SDMMLOG *sp, FILE *dbrfp);
void AddMMLOGKey(AnsiString &REM1, AnsiString &REM2, LPCSTR s, LPCSTR pKey);
void SetMMLOGKey(SDMMLOG *sp, LPSTR bf);

//*************************************************************
// ADIFѓAѓNѓZѓX‚МѓNѓ‰ѓX
//
class CLogADIF : public CLogConv
{
public:
protected:
	char	m_bf[1024];			// ѓtѓ@ѓCѓ‹ѓoѓbѓtѓ@
	LPSTR	m_p;
	int		m_conv;
private:
	void MMLOG2ADIF(LPSTR t, SDMMLOG *sp);
	void SetData(SDMMLOG *sp, LPCSTR pKey, LPSTR pData);
	void AdjustData(SDMMLOG *sp);
	void OutF(int &col, FILE *fp, LPCSTR fmt, ...);

public:
	CLogADIF();
	virtual int Open(LPCSTR pName);
	virtual int Create(LPCSTR pName);
	virtual int Close(void);
	virtual int Read(SDMMLOG *sp);
	virtual int Write(SDMMLOG *sp);

};

//*************************************************************
// Cabrillo ѓAѓNѓZѓX‚МѓNѓ‰ѓX
//
class CLogCabrillo : public CLogConv
{
public:
protected:
	char	m_bf[1024];			// ѓtѓ@ѓCѓ‹ѓoѓbѓtѓ@
	LPSTR	m_p;
	AnsiString	m_SNR;
private:
	void MMLOG2Cabrillo(LPSTR t, SDMMLOG *sp);
	void AdjustData(SDMMLOG *sp);

public:
	CLogCabrillo();
	virtual int Open(LPCSTR pName);
	virtual int Create(LPCSTR pName);
	virtual int Close(void);
	virtual int Read(SDMMLOG *sp);
	virtual int Write(SDMMLOG *sp);
};

#endif
