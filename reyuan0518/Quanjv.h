#pragma once
#include <vector>

#include "./CyAPI.h"//����ͷ�ļ���

#include "MyDatabase.h"
//#include <timeapi.h>
#pragma comment(lib,"./CyAPI.lib")//ָ��·�������뾲̬���ӿ�

#define WM_CHILDFRAMEDBCLK  WM_USER+10086  //������Ϣ
#define WM_LEFTPREVIEW  WM_USER+10087  //������Ϣ






//using namespace std;
class Quanjv
{
public:
	Quanjv();
	~Quanjv();
};

//extern CString username_now; //��ǰ�û���
//extern CString password_now;//��ǰ����


struct user_info//�û���Ϣ
{
	CString username_now; //��ǰ�û���
	CString password_now;//��ǰ����
	CString juese_now;
	CString quanxian_now;
	int ccdlggmm_now;
	int zhsd_now;
	int wdcd_now;
	int ypxxsz_now;
	int jlgssz_now;
	int ckttbdjg_now;
	int ckxttxjg_now;
	int cxdyryjg_now;
	int sjbf_now;
	int bdtt_now;
	int sdsscwqxsf_now;
	int gzsjsj_now;
	int sjgssz_now;
	int cklxjt_now;
	int sjwh_now;
	int zhgl_now;
};

extern user_info user_info_now;

struct YangPinXinXi{
	CString YPXX_YPMC;
	CString YPXX_GG;
	CString YPXX_JL;
	CString YPXX_GSRY;
};

extern std::vector<YangPinXinXi> vec_YPXX;//�����洢��Ʒ��Ϣ�Ľṹ������

extern	int PointNum;//̽ͷ����

extern CString title;//����-��¼��ʽ-��Դʵ���¼��ʽ-�޸�/�½�-��������

extern CString selected_current_name;//���ó������޸��˻�����Ҫ��¼��ǰѡ�е��û���

struct data_style//�û���Ϣ
{
	CString tz_style; //���ظ�ʽ
	CString jl_style;//������ʽ
	CString wd_style;//�¶ȸ�ʽ
	int wcs;
	int sswr;
};
extern data_style data_style_now;


extern CString current_computer_username;//��ǰ�豸(����)�û���
extern int current_computer_username_selected;//�Ƿ�ѡ���¼�������뵱ǰ�豸(����)�û���һ��



struct point_temperature//̽ͷ�¶���Ϣ
{
	CString first_t;
	CString second_t;
	CString third_t;
	CString fourth_t;
	CString fifth_t;

	CString first_voltage;//���ֵ�ѹ
	CString second_voltage;
	CString third_voltage;
	CString fourth_voltage;
	CString fifth_voltage;

	double first_regress;//�ع��¶�
	double second_regress;
	double third_regress;
	double fourth_regress;
	double fifth_regress;

	double a;//a + b * x;
	double b;//a + b * x;

	CString qualified;
};
extern point_temperature point_temperature_now[64];//


struct point_ifstart//�Ƿ�ʼ��ʵ�鷽��
{
	int syff;

	int ifstart;//�Ƿ�ʼ
	int ifconfirm;//�Ƿ�ȷ��

	double t_real;

	//CString str_ifstart;//��ʼ��ť�Ƿ��Ϊ�ѿ�ʼ����¼��ť�ı���

	double t_all[3 * 60 * 3];
	int j = 0;//��¼�¶ȵ���һ����ʮ��


	int after_time = 0;//��¼ע���ʱ��

	double t_avereage;
	double t_maxdif;

};
extern point_ifstart point_ifstart_now[64];//�Ƿ�ʼ��ʵ�鷽��


//�������豸��ر���
//extern CCyUSBDevice *mCCyUsbDevice;
//extern CCyUSBEndPoint *OutEndpt;
//extern CCyUSBEndPoint *InEndpt;
//extern bool bLooping;
//extern CWinThread *XferThread;//�߳�



extern	int Protocol[40];//Э�飺�ֽ�λ����·����̽ͷ�ţ���Ӧ��ϵ


struct select_GSP//ѡ����Ʒ�������ų̴���֮�䴫����Ϣ
{
	CString str_gsp;//����Ʒ����
	CString str_ypbh;//��Ʒ���
	CString str_ph;//����
	CString str_yptgdw;//��Ʒ�ṩ��λ
	CString str_gg;//���
	CString str_cqswzh;//��ǰ�����ܺ�
	CString str_cqcwzs;//��ǰ����ֻ��
};


extern select_GSP my_select_gsp;//ѡ����Ʒ�������ų̴���֮�䴫����Ϣ

extern int current_selected_point_gspmc_button;//��ǰҪ����ӹ���Ʒ������Ϣ��̽ͷ��

extern HWND my_wnd;;//���洰�ھ��


extern HWND my_second_wnd_l2r;
struct checkbox_state//��ӡԤ���󴰿����Ҵ���֮�䴫����Ϣ
{
	int jlbt;//��¼����

	int basic_info_gspmc;
	int basic_info_ypbh;
	int basic_info_ph;
	int basic_info_yptgdw;
	int basic_info_gg;
	int basic_info_jl;
	int basic_info_syff;
	int basic_info_syrq;
	int basic_info_gsrydpz;
	int basic_info_gjwdsjdkz;

	int wdsjb;
	int wdsjb_sjxx;

	int wdqx;

	int fzx_wb1_yqmc;
	int fzx_wb2_yqxh;
	int fzx_wb3_sbbh;
	int fzx_wb4_czr;
	int fzx_wb5_fhr;
	int fzx_wb6_shr;
	int fzx_wb7_jyyj;
	int fzx_wb8_sw;
	int fzx_xd1;
	int fzx_xd2;
	int fzx_xd3;
	int fzx_dybgrq;


};


extern checkbox_state checkbox_state_now;//��ӡԤ���󴰿����Ҵ���֮�䴫��


extern MyDatabase  myonlydatabase;