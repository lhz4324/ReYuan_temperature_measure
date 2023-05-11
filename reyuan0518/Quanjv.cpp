#include "stdafx.h"
#include "Quanjv.h"


Quanjv::Quanjv()
{
}


Quanjv::~Quanjv()
{
}

//CString username_now = _T("");
//CString password_now = _T("");

user_info user_info_now;


std::vector<YangPinXinXi> vec_YPXX;//用来存储样品信息的结构体数组



int PointNum = 2;//全局变量探头数，先暂时设置为2

CString title;//设置-记录格式-热源实验记录格式-修改/新建-标题名称
CString selected_current_name;//配置程序中修改账户界面要记录当前选中的用户名

data_style data_style_now;

CString current_computer_username;//当前设备(电脑)用户名
int current_computer_username_selected=0; //是否选择登录名必须与当前设备(电脑)用户名一致

point_temperature point_temperature_now[64];//探头温度信息
point_ifstart point_ifstart_now[64];//是否开始及实验方法

//以下是设备相关变量
//CCyUSBDevice *mCCyUsbDevice;
//CCyUSBEndPoint *OutEndpt;
//CCyUSBEndPoint *InEndpt;
//
//bool bLooping;
//CWinThread *XferThread;//线程


int Protocol[40] = {1,6,11,16,21,26,31,36,2,7,12,17,22,27,32,37,3,8,13,18,23,28,33,38,4,9,14,19,24,29,34,39,5,10,15,20,25,30,35,40};//协议：字节位置与路数（探头号）对应关系


select_GSP my_select_gsp;//选择供试品与试验排程窗口之间传递消息

int current_selected_point_gspmc_button=0;//当前要被添加供试品窗口信息的探头号


HWND my_wnd;

HWND my_second_wnd_l2r;

checkbox_state checkbox_state_now;//打印预览左窗口与右窗口之间传递信息

MyDatabase  myonlydatabase;