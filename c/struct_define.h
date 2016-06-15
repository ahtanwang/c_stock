#ifndef    _STRUCT_DEFINE_
#define	    _STRUCT_DEFINE_

#define MAX_JY_RECORD 						512

//fin for gongsi and HY
typedef struct {
	int   	date;				//ʱ��yyyymm������ͳ��
	float 	shouru;			//����			
	float 	lirun;			//������
	float 	gdqy;				//�ɶ�Ȩ��
	int 	dw;				//��λ
	
	float 	tb_shouru;		//����ͬ������
	float 	tb_lirun;		//����ͬ������
	float 	gdqyl;			//�ɶ�Ȩ����

	int  	gongsi_num_in_hangye;		//��ҵ�еĹ�˾����������ҵ��ʹ��, invalid in gongsi fin
}ut_Shouru_lirun;


//do not consider RongQuan
typedef struct {
	char 			code[10];
	char			hy_code[10];
	char			name[16];	
	int				type;
	int  			state; 					//״̬
	int     		is_exist_today;		//����ÿ������ļ���ʱ����б��
	int 			is_caozuo_today;		//�����Ƿ�����˲��������ڽ�����������
	int				days_hold;

	//�������
	unsigned int 	buy_date;
	int				buy_type;
	float 			buy_money;
	float			buy_price;				//��Ȩ�۸�close�۸�
	float			buy_price2;

	unsigned int 	sale_date;	
	float			sale_money;	
	float			sale_price;			//��Ȩ�۸�close�۸�
	float			sale_price2;	

	//��ֵ �������ȯ�����Ǹ�ֵ���������ڸ�ծ����
	float 			value_gongsi;
	float   		syl;

	float 			next_index;
}ut_JY_record;


typedef struct {
	unsigned int 	date;
	int 			jzzs_index;

	//�ʲ���ծ���
	float			zong_zi_chan;					//���ʲ�
	float 			jing_zi_chan;					//���ʲ�
	float   		jing_zi_chan_max;				//����ʲ������ڼ������س�
	float			rong_zi_fu_zhai;				//���ʸ�ծ			
	float			rong_quan_fu_zhai;			//��ȯ��ծ�����ڼ�����Ϣ��ע����ȯ��ծ������Ϣ�����Ǹ��ݵ�һ����ȯ�۸���㣬���Ƕ�̬�۸����
													//���ǴӼ��㷽��ĽǶȣ���ʱ����ͳһ���㣬���Ӧ�ò���ܴ�	
	float 			ke_yong_cash;					//�����ֽ𣬰��������ֽ������ֽ���ȯ�ֽ��
	float			jin_zii_chan_fu_zhai_bi;		//���ʲ���ծ��
	float			ke_rong_zi_jin;				//�����ʽ�
	float			ke_rong_zheng_quan;			//����֤ȯ


	//�ֹɺ��������	
	int   			num_hold_stock_normal;			//�ֳ��й�Ʊ��Ŀ��������ȯ�Ĺ�Ʊ����ȯ�Ĺ�Ʊ���з������
	int   			num_hold_stock_rq;				//�ֳ��й�Ʊ��Ŀ��������ȯ�Ĺ�Ʊ����ȯ�Ĺ�Ʊ���з������
	ut_JY_record stock[MAX_JY_RECORD];
	int				stock_wait_head;
	int				stock_wait_tail;
	

	//�������
	float			zdhc;							//���س�
	float			nh_syl;							//�껯������


	//����ͳ��
	int 			times_jy;						//���״�������������һ����һ��
	int				total_hold_days;				//�ܳ��н�������
	float			total_syl;

	//ӯ������ͳ��
	int 			times_jy_1;						//���״�������������һ����һ��
	int				total_hold_days_1;				//�ܳ��н�������
	float			total_syl_1;
	

	//������ͳ��
	int 			times_jy_0;						//���״�������������һ����һ��
	int				total_hold_days_0;				//�ܳ��н�������
	float			total_syl_0;



	int 			times_jy_k;					//���״�������������һ����һ��
	int				total_hold_days_k;			//�ܳ��н�������
	float 			total_syl_k;

	float			zj_syxl_duo;						//�ʽ�ʹ��Ч��
	float			zj_syxl_kong;						//�ʽ�ʹ��Ч��	
	int				moni_days;

	int  			times_sale;					//Ӧ����������
	int 			times_buy;						//Ӧ���������
	int 			times_sale_fail;			
	int				times_buy_fail;
	int 			times_sale_succ_xjd;			//�ɹ���������
	int				times_buy_succ;			//�ɹ��������	
	int 			times_sale_bcaus_p120;
	int				times_sale_bcaus_QD;
	
}ut_JY_info;


// stock for selected
typedef struct {
	int 	version;
	int 	type;
	char 	code[8];
	char 	name[16];	
	int		ok_jsm;
	int		ok_yc;
	int		ok_stoplong;
	int 	ok_blacklist;
	float 	qd;
	float 	deal_money;
	char 	hy_code[8];
	int 	ok_hy;

	int 	flag;
} ut_StockSelect;			


#endif
