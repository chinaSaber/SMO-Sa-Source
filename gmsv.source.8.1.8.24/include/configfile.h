#ifndef __CONFIGFILE_H__
#define __CONFIGFILE_H__

#include "common.h"

#undef EXTERN
#ifdef __CONFIGFILE_C__
#define EXTERN
#else  /*  __CONFIGFILE_C__  */
#define EXTERN extern
#endif /*  __CONFIGFILE_C__  */

// Arminius 7.12 login announce
extern char announcetext[8192];
void AnnounceToPlayer(int charaindex);
// Robin 0720
void AnnounceToPlayerWN(int fd);
void LoadAnnounce(void);

#ifdef _PET_TALKPRO
	#define PETTALK_MAXID 8
	typedef struct {
		int ID;
		char DATA[10240*10];	//1M
	}PTALK;
	extern PTALK pettalktext[PETTALK_MAXID];
	void LoadPetTalk(void);
#else
	
extern char pettalktext[4096];
void LoadPetTalk(void);
#endif

#ifdef _GAMBLE_BANK
#define GAMBLEBANK_ITEMSMAX 100
#define DEFEND_ITEMSMAX 40
typedef struct	REGAMBLEBANKITEMS	{
	char name[128];
	int Gnum;
	int ItemId;
	int type;
}GAMBLEBANK_ITEMS;

extern GAMBLEBANK_ITEMS GB_ITEMS[GAMBLEBANK_ITEMSMAX];

void Load_GambleBankItems( void);
#endif

#ifdef _CFREE_petskill
#define PETSKILL_CODE 300
typedef struct	REPETSKILL_CODES	{
	char name[128];
	int TempNo;
	int PetId;
	char Code[256];
}PETSKILL_CODES;

extern PETSKILL_CODES Code_skill[PETSKILL_CODE];
void Load_PetSkillCodes( void);
#endif

#ifdef _BLACK_MARKET
struct BlackMarketItem {
	char iName[128];
	int  iGraphicsNum;
	int  iId[4][3];
	int  iCondition[4];
	int  GCondition;
};
#define BMIMAX 1000
struct  BlackMarketItem BMItem[BMIMAX];
int     BMINum;
int     BMSellList[12];
#endif

#ifdef _GMRELOAD
#define GMMAXNUM	100
struct GMINFO
{
	char cdkey[24];
	int  level;
};
extern struct GMINFO gminfo[GMMAXNUM];
#endif

BOOL readconfigfile( char* filename );

void  defaultConfig( char* argv0 );
char* getProgname( void );
char* getConfigfilename( void );
void setConfigfilename( char* newv );

unsigned int getDebuglevel( void );
unsigned int setDebuglevel( unsigned int newv );
unsigned int getMemoryunit( void );
unsigned int getMemoryunitnum( void );
char*   getAccountservername( void );
unsigned short   getAccountserverport( void );
char*   getAccountserverpasswd( void );
char*   getGameservername( void );

#ifdef _M_SERVER
char* getmservername(void);
void setmservername( char *msname);
unsigned int getmserverport(void);
void setmserverport( int port);
#endif

#ifdef _NPCSERVER_NEW
char *getnpcserveraddr(void);
unsigned int getnpcserverport(void);
void NS_setAddressAndPort( char *address, int nport);
#endif

unsigned short getPortnumber( void );

int getServernumber( void );
int getReuseaddr( void );
int getNodelay( void );
int getLogWriteTime(void);
int getLogIOTime( void);
int getLogGameTime(void);
int getLogNetloopFaster(void);
int getSaacwritenum( void );
void setSaacwritenum( int num );
int getSaacreadnum( void );
void setSaacreadnum( int num );

#ifdef _HELP_NEWHAND
int getCreatePitem( int num );
#endif
#ifdef _JZ_NEW_CONF
int getCreatePpet(int num);
int getgetridepet(void);
int getPexp(void);
int getPupexp(void);
int getCreatePgold(void);
int getridets(void);
int getCreatePpetlevel(void);
char getping(void);
char getwatcallmap(void);
char getgetpetup(void);
int getwatchmap(int num);
int getunwarpmap(int num);
int getjz_maxlevel(void);
int gettransmaxlevel(void);
char *getexpfile(void);
int getmaxchar(void);
#endif

#ifdef _JZ_BASE_IF
int getbaseif(void);
#endif

#ifdef _JZ_CIRC_AN
int getloopantime(void);
char *getloopanfile(void);
#endif

#ifdef _JZ_ANGELOPEN
char getAngelOpen(void);
#endif

int getmaxcharor(void);
int getipconn(void);
int getevsls(void);
int getrecvbuffer(void);
int getreadbuffer(void);
int getacwritebuf(void);
int getrunlevel(void);

int getsorecvbuf(void);
int getsorecvlowat(void);
int getsosendlowat(void);

#ifdef _JZ_RIDE
char *getRidefile(void);
#endif

char *getMemberWord(void);

#ifdef _JZ_CAPTURE_FREES
char *getCapFreeFile(void);
#endif

int getHouFightWarTime(void);
int getHouConWarTime(void);
int getFMTimeLimit(void);
int getNowEvent(int Num);
int getEndEvent(int Num);

#ifdef _JZ_CF_DELPETITEM
int getDelPet(int Num);
int getDelItem(int Num);
#endif

#ifdef _JZ_VIPCODE
int getSaveNumberMultiple(void);
#endif

unsigned int getFdnum( void );
unsigned int getPetcharnum( void );
unsigned int getOtherscharnum( void );
unsigned int getObjnum( void );
unsigned int getItemnum( void );
unsigned int getBattlenum( void );

char* getTopdir( void );
char* getMapdir( void );
char* getMaptilefile( void );
char* getBattleMapfile( void );
char* getItemfile( void );
char* getInvfile( void );
char* getAppearfile( void );
char* getEffectfile( void );
char* getTitleNamefile( void );
char* getTitleConfigfile( void );
char* getLsgenlogfilename( void );
char* getStoredir( void );
#ifdef _STORECHAR
char* getStorechar( void );
#endif
char* getNpcdir( void );
char* getLogdir( void );
char* getLogconffile( void );
char* getChatMagicPasswd( void );
unsigned int getChatMagicCDKeyCheck( void );


unsigned int getFilesearchnum( void );
unsigned int getNpctemplatenum( void );
unsigned int getNpccreatenum( void );
unsigned int getWalksendinterval( void );
void		 setWalksendinterval( unsigned int );
unsigned int getCAsendinterval_ms( void );
void 		 setCAsendinterval_ms( unsigned int );
unsigned int getCDsendinterval_ms( void );
void		 setCDsendinterval_ms( unsigned int );
unsigned int getOnelooptime_ms( void );
void		 setOnelooptime_ms( unsigned int );
unsigned int getCharSavesendinterval( void );
void setCharSavesendinterval( unsigned int interval);
unsigned int getAddressbookoffmsgnum( void );
unsigned int getProtocolreadfrequency( void );
unsigned int getAllowerrornum( void );
unsigned int getLogHour( void );
unsigned int getBattleDebugMsg( void );
void setBattleDebugMsg( unsigned int );

char* getEncountfile( void );
char* getEnemyfile( void );
char* getGroupfile( void );
char* getEnemyBasefile( void );
char* getMagicfile( void );
#ifdef __ATTACK_MAGIC

char* getAttMagicfileName( void );

#endif

char* getPetskillfile( void );
char *getItematomfile( void );
char *getQuizfile( void );

#ifdef _PROFESSION_SKILL			// WON ADD 人物職業技能
char* getProfession( void );
#endif

unsigned int getPetdeletetime( void );
void setPetdeletetime( unsigned int interval );

unsigned int getItemdeletetime( void );
void setItemdeletetime( unsigned int interval );
//ttom add this because the second have this function
//unsigned int getAcwriteSize( void );

#ifdef _DEL_DROP_GOLD
unsigned int getGolddeletetime( void );
void setGolddeletetime( unsigned int interval );
#endif

unsigned int setEncodeKey( void );
unsigned int setAcWBSize( void );
//ttom end

// CoolFish: +2 2001/4/18
unsigned int getAcwriteSize( void );
unsigned int getErrUserDownFlg( void );

// Arminius 7.24 manor pk
char* getGameserverID( void );
unsigned short getAllowManorPK( void );

// Terry 2001/10/03 service ap
char* getApID(void);
unsigned short getApPort(void);
int getLoopTime(void);
int getEnableService(void);

#ifdef _GMRELOAD
char* getGMSetfile(void);
BOOL LoadGMSet(char *filename);
#endif

#ifdef _ITEM_QUITPARTY
char* getitemquitparty( void );
#endif
#ifdef _BLACK_MARKET
char* getBMItemFile(void);
BOOL LoadBMItem( char* filename );
#endif

#ifdef _AUCTIONEER
char* getAuctiondir(void);
#endif

#ifdef _MUSEUM
int getMuseum(void);
#endif

#endif
