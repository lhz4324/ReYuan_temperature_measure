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


std::vector<YangPinXinXi> vec_YPXX;//�����洢��Ʒ��Ϣ�Ľṹ������



int PointNum = 2;//ȫ�ֱ���̽ͷ��������ʱ����Ϊ2

CString title;//����-��¼��ʽ-��Դʵ���¼��ʽ-�޸�/�½�-��������
CString selected_current_name;//���ó������޸��˻�����Ҫ��¼��ǰѡ�е��û���

data_style data_style_now;

CString current_computer_username;//��ǰ�豸(����)�û���
int current_computer_username_selected=0; //�Ƿ�ѡ���¼�������뵱ǰ�豸(����)�û���һ��

point_temperature point_temperature_now[64];//̽ͷ�¶���Ϣ
point_ifstart point_ifstart_now[64];//�Ƿ�ʼ��ʵ�鷽��

//�������豸��ر���
//CCyUSBDevice *mCCyUsbDevice;
//CCyUSBEndPoint *OutEndpt;
//CCyUSBEndPoint *InEndpt;
//
//bool bLooping;
//CWinThread *XferThread;//�߳�


int Protocol[40] = {1,6,11,16,21,26,31,36,2,7,12,17,22,27,32,37,3,8,13,18,23,28,33,38,4,9,14,19,24,29,34,39,5,10,15,20,25,30,35,40};//Э�飺�ֽ�λ����·����̽ͷ�ţ���Ӧ��ϵ


select_GSP my_select_gsp;//ѡ����Ʒ�������ų̴���֮�䴫����Ϣ

int current_selected_point_gspmc_button=0;//��ǰҪ����ӹ���Ʒ������Ϣ��̽ͷ��


HWND my_wnd;

HWND my_second_wnd_l2r;

checkbox_state checkbox_state_now;//��ӡԤ���󴰿����Ҵ���֮�䴫����Ϣ

MyDatabase  myonlydatabase;