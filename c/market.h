/*
    market����
    mode1: ���ڽ��׺Ͱ�����ҵ������˾�����ٲ��ҽ��д���
    
    mode2:ͳ�����ǿ�ȷ�ʽ�ĳɹ����Լ����������
    	1--�򵥰���ǿ�Ȱ��ձ������ڶ��پ����룬С�ڶ��پ����������ɹ���
*/

#ifndef _MARKET_H_
#define _MARKET_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <strstrea.h>
#include <direct.h>

#include "publicfunc.h"
#include "macro_define.h"
#include "baocunshuju.h"
#include "gongsi.h"


#define MARKET_MAXGONGSI  4000

typedef struct {
	char 	HY[8][MAX_HANGYE];
  	int     HY_size;
} ut_cm1;


typedef struct {
	char 	hycode[16];
	int 	date;
	int 	is_new;
	int 	num;

	float 	t_sy;
	float 	t_lr;
	float 	t_gdqy;

	float 	dwsr;
	float 	dwlr;
	float 	lrl;
}UT_fin_stat;

class uc_Market {
public:
    uc_GongSi   gongsi[MARKET_MAXGONGSI];
    int         gongsi_size;
	uc_GongSi   *phead;			//best gongsi for QD
	
    uc_GongSi   zs_jz_duo;	




	void 		Init(void);
	void 		cHYF(void);				
	void   		rFinList(void);
    void		saveBinData(void);

	void	readCm1(void);
	void	Cal_m1(void);
	void    out_m1(void);
	void	out_m1_hangye(void);
	void	out_m1_one(void);	
	void	out_m1_czg(void);	
	void	out_m1_hangye_s(void);
	void	out_m1_one_s(void);	
	void	out_m1_czg_s(void);	

	int   	is_m1_in_one(uc_GongSi *pgongsi);
	

	void 		Cal_Paiming(void);
    void		Cal_HY(uc_GongSi*);
	void 		Cal_HY_Fin(uc_GongSi *phy);
    
	uc_GongSi *GetGongsi_byCode(char* code);
    uc_GongSi *GetHY_by_GSCode(char* code);

	int			m0(void);
    int         m1(void);
    int         m2(void);   


};

#endif

