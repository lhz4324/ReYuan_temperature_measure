#pragma once
#include <vector>

#include "./CyAPI.h"//导入头文件，

#include "MyDatabase.h"
//#include <timeapi.h>
#pragma comment(lib,"./CyAPI.lib")//指定路径，导入静态链接库

#define WM_CHILDFRAMEDBCLK  WM_USER+10086  //传递消息
#define WM_LEFTPREVIEW  WM_USER+10087  //传递消息






//using namespace std;
class Quanjv
{
public:
	Quanjv();
	~Quanjv();
};

//extern CString username_now; //当前用户名
//extern CString password_now;//当前密码


struct user_info//用户信息
{
	CString username_now; //当前用户名
	CString password_now;//当前密码
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

extern std::vector<YangPinXinXi> vec_YPXX;//用来存储样品信息的结构体数组

extern	int PointNum;//探头总数

extern CString title;//设置-记录格式-热源实验记录格式-修改/新建-标题名称

extern CString selected_current_name;//配置程序中修改账户界面要记录当前选中的用户名

struct data_style//用户信息
{
	CString tz_style; //体重格式
	CString jl_style;//剂量格式
	CString wd_style;//温度格式
	int wcs;
	int sswr;
};
extern data_style data_style_now;


extern CString current_computer_username;//当前设备(电脑)用户名
extern int current_computer_username_selected;//是否选择登录名必须与当前设备(电脑)用户名一致



struct point_temperature//探头温度信息
{
	CString first_t;
	CString second_t;
	CString third_t;
	CString fourth_t;
	CString fifth_t;

	CString first_voltage;//数字电压
	CString second_voltage;
	CString third_voltage;
	CString fourth_voltage;
	CString fifth_voltage;

	double first_regress;//回归温度
	double second_regress;
	double third_regress;
	double fourth_regress;
	double fifth_regress;

	double a;//a + b * x;
	double b;//a + b * x;

	CString qualified;
};
extern point_temperature point_temperature_now[64];//


struct point_ifstart//是否开始及实验方法
{
	int syff;

	int ifstart;//是否开始
	int ifconfirm;//是否确认

	double t_real;

	//CString str_ifstart;//开始按钮是否变为已开始（记录按钮文本）

	double t_all[3 * 60 * 3];
	int j = 0;//记录温度到哪一个二十秒


	int after_time = 0;//记录注射后时间

	double t_avereage;
	double t_maxdif;

};
extern point_ifstart point_ifstart_now[64];//是否开始及实验方法


//以下是设备相关变量
//extern CCyUSBDevice *mCCyUsbDevice;
//extern CCyUSBEndPoint *OutEndpt;
//extern CCyUSBEndPoint *InEndpt;
//extern bool bLooping;
//extern CWinThread *XferThread;//线程



extern	int Protocol[40];//协议：字节位置与路数（探头号）对应关系


struct select_GSP//选择供试品与试验排程窗口之间传递消息
{
	CString str_gsp;//供试品名称
	CString str_ypbh;//样品编号
	CString str_ph;//批号
	CString str_yptgdw;//样品提供单位
	CString str_gg;//规格
	CString str_cqswzh;//从前升温总和
	CString str_cqcwzs;//从前超温只数
};


extern select_GSP my_select_gsp;//选择供试品与试验排程窗口之间传递消息

extern int current_selected_point_gspmc_button;//当前要被添加供试品窗口信息的探头号

extern HWND my_wnd;;//保存窗口句柄


extern HWND my_second_wnd_l2r;
struct checkbox_state//打印预览左窗口与右窗口之间传递信息
{
	int jlbt;//记录标题

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


extern checkbox_state checkbox_state_now;//打印预览左窗口与右窗口之间传递


extern MyDatabase  myonlydatabase;