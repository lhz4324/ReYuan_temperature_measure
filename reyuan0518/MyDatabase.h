#pragma once
#include "stdafx.h"
#include "./mysql/mysql.h"
#include<string>
#include<vector>
#include <string>
#include "reyuan0518.h"
#include "afxdialogex.h"

//#include "Quanjv.h"

class MyDatabase
{
public:
	MyDatabase();
	~MyDatabase();

public:
	bool ConnectDB_orcreate();//�������ݿ⣬��û���򴴽�
	void change_account_password_mydatabase(char* new_password, char*  username_now);//�����˻�����

	void add_account( struct user_info user_info_now);//����-����˻�
	void change_account(struct user_info user_info_now);//����-�޸��˻�

	void add_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY);//�����Ʒ��Ϣ
	void change_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY); //������Ʒ��Ϣ
	void delete_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC); //ɾ����Ʒ��Ϣ

	void add_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF);//������Ʒ������Ϣ
	void change_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF);//������Ʒ������Ϣ
	void delete_yangpinduilie_mydatabase(char* YPDL_gspmc);//ɾ����Ʒ������Ϣ
	
	void add_point_BD_info(char* strDate, char* strTime, struct point_temperature point_temperature_info, int point_number);//����̽ͷ�궨�¶���Ϣ
	void add_SYPC_info(int pointnum, CString tuhao, CString tizhong, CString jiliang, CString qbsj, CString zshsj, CString sswd, CString jw, CString wc, CString ssff, CString gspmc, CString ypbh, CString ph);//���������ų���Ϣ

public:
	MYSQL m_sqlCon;
	MYSQL_RES *res;
	MYSQL_ROW row;

	

};

