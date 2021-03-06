#ifndef __NPC_QUIZ_H__
#define __NPC_QUIZ_H__

typedef struct NPC_Quiz{

	int 	no;				//  題の  号
	int 	type;			//  題のタイプ  ゲーム    �bスポーツ)	
	int		level;  		//  題のレベル
	int 	answertype;		//答えの選びかた(２  �b３  �b単語マッチ  
	int 	answerNo;		//  題の答え
	char	question[512]; 	//  題
	char	select1[128]; 	//選  枝1
	char	select2[128]; 	//選  枝2
	char	select3[128]; 	//選  枝3

}NPC_QUIZ;


void NPC_QuizTalked( int meindex , int talkerindex , char *msg ,
                     int color );
BOOL NPC_QuizInit( int meindex );
void NPC_QuizWindowTalked( int meindex, int talkerindex, int seqno, int select, char *data);

BOOL QUIZ_initQuiz( char *filename);


#endif 

/*__NPC_QUIZ_H__*/
