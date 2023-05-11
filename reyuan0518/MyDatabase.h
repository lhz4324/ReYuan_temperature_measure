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
	bool ConnectDB_orcreate();//连接数据库，若没有则创建
	void change_account_password_mydatabase(char* new_password, char*  username_now);//更改账户密码

	void add_account( struct user_info user_info_now);//配置-添加账户
	void change_account(struct user_info user_info_now);//配置-修改账户

	void add_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY);//添加样品信息
	void change_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY); //更改样品信息
	void delete_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC); //删除样品信息

	void add_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF);//插入样品队列信息
	void change_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF);//更改样品队列信息
	void delete_yangpinduilie_mydatabase(char* YPDL_gspmc);//删除样品队列信息
	
	void add_point_BD_info(char* strDate, char* strTime, struct point_temperature point_temperature_info, int point_number);//插入探头标定温度信息
	void add_SYPC_info(int pointnum, CString tuhao, CString tizhong, CString jiliang, CString qbsj, CString zshsj, CString sswd, CString jw, CString wc, CString ssff, CString gspmc, CString ypbh, CString ph);//插入试验排程信息

public:
	MYSQL m_sqlCon;
	MYSQL_RES *res;
	MYSQL_ROW row;

	

};

