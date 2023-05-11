#include "stdafx.h"
#include "MyDatabase.h"
#include "Quanjv.h"



MyDatabase::MyDatabase()
{
}


MyDatabase::~MyDatabase()
{
}

std::string			CS2S(CString cs) {
	int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;
	int nlen = WideCharToMultiByte(codepage, 0, cs, -1, 0, 0, 0, 0);
	if (nlen > 1020)
	{
		CHAR* pBuf = new CHAR[nlen];
		WideCharToMultiByte(codepage, 0, cs, -1, pBuf, nlen, 0, 0);
		delete[] pBuf;
		return std::string(pBuf);
	}
	CHAR pBuf[1024];
	WideCharToMultiByte(codepage, 0, cs, -1, pBuf, nlen, 0, 0);
	return std::string(pBuf);
}


bool MyDatabase::ConnectDB_orcreate()//连接数据库
{

	

	const char user[] = "root";
	const char pswd[] = "root";
	const char host[] = "localhost";
	unsigned int port = 3306;

	CString dbname = L"reyuan_mydatabase";
	
	//MYSQL m_sqlCon;
	// 1.初始化数据库句柄
	mysql_init(&m_sqlCon);
	res = nullptr;
	// 2.设置字符编码
	mysql_options(&m_sqlCon, MYSQL_SET_CHARSET_NAME, "gbk");
	
	//char value = 1;
	//mysql_options(&m_sqlCon, MYSQL_OPT_RECONNECT, &value);



	if (mysql_real_connect(&m_sqlCon, host, user, pswd, "mysql", port, NULL, 0)) {

	

		std::string create_db = "CREATE DATABASE IF NOT EXISTS " + CS2S(dbname) + " DEFAULT CHARACTER SET utf8";
		if (0 != mysql_query(&m_sqlCon, create_db.c_str()))
		{	
			AfxMessageBox(_T("数据库创建时连接失败"));
			return false;
		}
		mysql_close(&m_sqlCon);

		

		mysql_init(&m_sqlCon);//这里就初始化了myonlydatabase的m_sqlCon
		res = nullptr;
		mysql_options(&m_sqlCon, MYSQL_SET_CHARSET_NAME, "gbk");
	/*	char value = 1;
		mysql_options(&m_sqlCon, MYSQL_OPT_RECONNECT, &value);*/
	}




	if (!mysql_real_connect(&m_sqlCon, host, user, pswd, CStringA(dbname), port, NULL, 0)) {
		return false;
		AfxMessageBox(_T("数据库连接失败"));

	}


	//1.创建 探头标定信息  表格
	CString table_str1 = _T("\
	CREATE TABLE  IF NOT EXISTS `探头标定信息` (\
		`Date` VARCHAR(45) NOT NULL,\
		`Time` VARCHAR(45) NOT NULL,\
		`point_Num` INT(11) NOT NULL,\
		`First_t_real` VARCHAR(45) NULL,\
		`First_t_regress` FLOAT NULL,\
		`Second_t_real` VARCHAR(45) NULL,\
		`Second_t_regress` FLOAT NULL,\
		`Third_t_real` VARCHAR(45) NULL,\
		`Third_t_regress` FLOAT NULL,\
		`Fourth_t_real` VARCHAR(45) NULL,\
		`Fourth_t_regress` FLOAT NULL,\
		`Fifth_t_real` VARCHAR(45) NULL,\
		`Fifth_t_regress` FLOAT NULL,\
		`Conclusion` VARCHAR(45) NULL,\
		PRIMARY KEY(`Date`, `Time`, `point_Num`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str1).c_str()))
	{
		
			return false;
	}


	//2.创建  样品队列   表格
	CString table_str2 = _T("\
	CREATE TABLE  IF NOT EXISTS `样品队列` (\
		`供试品名称sql` VARCHAR(45) NOT NULL,\
		`样品编号sql` VARCHAR(45) NULL,\
		`批号sql` VARCHAR(45) NULL,\
		`样品提供单位sql` VARCHAR(45) NULL,\
		`规格sql` VARCHAR(45) NULL,\
		`剂量sql` VARCHAR(45) NULL,\
		`试验方法sql` VARCHAR(45) NOT NULL,\
		`从前升温总和sql` VARCHAR(45) NULL,\
		`从前超温只数sql` VARCHAR(45) NULL,\
		PRIMARY KEY(`供试品名称sql`, `试验方法sql`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str2).c_str()))
	{

		return false;
	}

	//PRIMARY KEY(`供试品名称sql`, `试验方法sql`, `从前升温总和sql`, `从前超温只数sql`, `样品编号sql`, `样品提供单位sql`, `批号sql`)\
	
	//3.创建  样品信息   表格
	CString table_str3 = _T("\
	CREATE TABLE  IF NOT EXISTS `样品信息` (\
		`YPMC_sjk` VARCHAR(45) NOT NULL,\
		`GG_sjk` VARCHAR(45) NULL,\
		`JL_sjk` VARCHAR(45) NULL,\
		`GSRYPZ_sjk` VARCHAR(45) NULL,\
		PRIMARY KEY(`YPMC_sjk`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str3).c_str()))
	{

		return false;
	}


	//4.创建  用户账号密码   表格
	CString table_str4 = _T("\
	CREATE TABLE  IF NOT EXISTS `用户账号密码` (\
		`name` VARCHAR(45) NOT NULL,\
		`password` VARCHAR(45) NULL,\
		`juese` VARCHAR(45) NULL,\
		`quanxiandengji` VARCHAR(45) NULL,\
		`初次登录更改密码` INT(11) NULL,\
		`账户锁定` INT(11) NULL,\
		`温度测定` INT(11) NULL,\
		`样品信息设置` INT(11) NULL,\
		`记录格式设置` INT(11) NULL,\
		`查看探头标定结果` INT(11) NULL,\
		`查看新兔挑选结果` INT(11) NULL,\
		`查询、打印热原结果` INT(11) NULL,\
		`数据备份` INT(11) NULL,\
		`标定探头` INT(11) NULL,\
		`设定实时测温曲线缩放` INT(11) NULL,\
		`跟踪审计数据` INT(11) NULL,\
		`数据格式设置` INT(11) NULL,\
		`查看落选家兔` INT(11) NULL,\
		`数据维护` INT(11) NULL,\
		`账户管理` INT(11) NULL,\
		PRIMARY KEY(`name`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str4).c_str()))
	{

		return false;
	}


	//5.创建  试验排程   表格
	CString table_str5 = _T("\
	CREATE TABLE  IF NOT EXISTS `试验排程` (\
		`探头号sql` INT NOT NULL,\
		`兔号sql` VARCHAR(45) NULL,\
		`体重sql` VARCHAR(45) NULL,\
		`剂量sql` VARCHAR(45) NULL,\
		`全部时间sql` VARCHAR(45) NULL,\
		`注射后时间sql` VARCHAR(45) NULL,\
		`实时温度sql` VARCHAR(45) NULL,\
		`均温sql` VARCHAR(45) NULL,\
		`温差sql` VARCHAR(45) NULL,\
		`试验方法sql` VARCHAR(45) NULL,\
		`供试品名称sql` VARCHAR(45) NULL,\
		`样品编号sql` VARCHAR(45) NULL,\
		`批号sql` VARCHAR(45) NULL,\
		PRIMARY KEY(`探头号sql`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str5).c_str()))
	{

		return false;
	}


	//6.创建  选择供试品  表格
	CString table_str6 = _T("\
	CREATE TABLE  IF NOT EXISTS `选择供试品` (\
		`供试品名称sql` VARCHAR(45) NOT NULL,\
		`样品编号sql` VARCHAR(45) NULL,\
		`批号sql` VARCHAR(45) NULL,\
		`样品提供单位sql` VARCHAR(45) NULL,\
		`规格sql` VARCHAR(45) NULL,\
		`从前升温总和sql` VARCHAR(45) NULL,\
		`从前超温只数sql` VARCHAR(45) NULL,\
		PRIMARY KEY(`供试品名称sql`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str6).c_str()))
	{

		return false;
	}

	return true;
}







void MyDatabase::add_account(user_info user_info_now){


	USES_CONVERSION;

	char insert[1000];
	sprintf_s(insert, "insert into 用户账号密码(name, password,juese,quanxiandengji,初次登录更改密码,账户锁定,温度测定,样品信息设置,记录格式设置,查看探头标定结果,查看新兔挑选结果,查询、打印热原结果,数据备份,标定探头,设定实时测温曲线缩放,跟踪审计数据,数据格式设置,查看落选家兔,数据维护,账户管理) values (\'%s\',  \'%s\', \'%s\',  \'%s\', %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d)",
		T2A(user_info_now.username_now), T2A(user_info_now.password_now), T2A(user_info_now.juese_now), "erji", user_info_now.ccdlggmm_now, user_info_now.zhsd_now, user_info_now.wdcd_now, user_info_now.ypxxsz_now, user_info_now.jlgssz_now, user_info_now.ckttbdjg_now, user_info_now.ckxttxjg_now, user_info_now.cxdyryjg_now, user_info_now.sjbf_now, user_info_now.bdtt_now, user_info_now.sdsscwqxsf_now, user_info_now.gzsjsj_now, user_info_now.sjgssz_now, user_info_now.cklxjt_now, user_info_now.sjwh_now, user_info_now.zhgl_now);//插入数据


	// 执行 sql 语句。  
	// mysql_query() 的返回值份很多情形， 进行判断使要注意。  
	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		AfxMessageBox(_T("添加账户信息成功!"));
	}
	else {
		AfxMessageBox(_T("添加账户信息失败!"));
	}

}


void MyDatabase::change_account(struct user_info user_info_now){



	USES_CONVERSION;

	char insert2[1000];
	sprintf_s(insert2, "UPDATE 用户账号密码 SET password='%s',juese='%s',初次登录更改密码=%d,账户锁定=%d,温度测定=%d,样品信息设置=%d,记录格式设置=%d,查看探头标定结果=%d,查看新兔挑选结果=%d,查询、打印热原结果=%d,数据备份=%d,标定探头=%d,设定实时测温曲线缩放=%d,跟踪审计数据=%d,数据格式设置=%d,查看落选家兔=%d,数据维护=%d,账户管理=%d WHERE name='%s'",
		T2A(user_info_now.password_now), T2A(user_info_now.juese_now), user_info_now.ccdlggmm_now, user_info_now.zhsd_now, user_info_now.wdcd_now, user_info_now.ypxxsz_now, user_info_now.jlgssz_now, user_info_now.ckttbdjg_now, user_info_now.ckxttxjg_now, user_info_now.cxdyryjg_now, user_info_now.sjbf_now, user_info_now.bdtt_now, user_info_now.sdsscwqxsf_now, user_info_now.gzsjsj_now, user_info_now.sjgssz_now, user_info_now.cklxjt_now, user_info_now.sjwh_now, user_info_now.zhgl_now, T2A(user_info_now.username_now));//更新数据;

	if (mysql_query(&m_sqlCon, insert2) == 0)
	{
		AfxMessageBox(_T("修改成功！"));

	}
	else {
		AfxMessageBox(_T("修改失败!"));

	}


}


void MyDatabase::change_account_password_mydatabase(char* new_password, char*  username_now){//更改账户密码



	char insert2[1000];
	sprintf_s(insert2, "UPDATE 用户账号密码 SET password='%s' WHERE name='%s'", new_password, username_now);

	if (mysql_query(&m_sqlCon, insert2) == 0)
	{
		AfxMessageBox(_T("修改成功！"));

	}
	else {
		AfxMessageBox(_T("修改失败!"));

	}


}



void MyDatabase::add_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY)//添加样品信息
{
	
	char insert3[1000];
	sprintf_s(insert3, "insert into 样品信息(YPMC_sjk, GG_sjk,JL_sjk,GSRYPZ_sjk) values (\'%s\',  \'%s\',  \'%s\',  \'%s\')", SET_YPXX_YPMC, SET_YPXX_GG, SET_YPXX_JL, SET_YPXX_GSRY);//插入数据

	// 执行 sql 语句。  
	// mysql_query() 的返回值份很多情形， 进行判断使要注意。  

	if (mysql_query(&m_sqlCon, insert3) == 0)
	{
		AfxMessageBox(_T("添加样品信息成功!"));
	}
	else {
		AfxMessageBox(_T("添加样品信息失败!"));
	}
}

void MyDatabase::change_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY) //更改样品信息
{



	char insert4[1000];
	sprintf_s(insert4, "UPDATE 样品信息 SET GG_sjk='%s',JL_sjk='%s',GSRYPZ_sjk='%s' WHERE YPMC_sjk='%s'",  SET_YPXX_GG, SET_YPXX_JL, SET_YPXX_GSRY, SET_YPXX_YPMC);


	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		AfxMessageBox(_T("修改成功！"));
	}
	else {
		AfxMessageBox(_T("修改失败!"));
	}

}

void MyDatabase::delete_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC)//删除样品信息
{

	char insert[1000];
	sprintf_s(insert, "DELETE FROM 样品信息 WHERE YPMC_sjk='%s'", SET_YPXX_YPMC);

	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		AfxMessageBox(_T("删除成功！"));
	}
	else {
		AfxMessageBox(_T("删除失败!"));
	}

}





void MyDatabase::add_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF)//插入样品队列信息
{
	

	char insert4[1000];
	sprintf_s(insert4, "insert into 样品队列(供试品名称sql,样品编号sql,批号sql,样品提供单位sql,规格sql,剂量sql,试验方法sql) values (\'%s\',  \'%s\',  \'%s\', \'%s\',  \'%s\',  \'%s\',  \'%s\')", YPDL_gspmc, YPDL_ypbh, YPDL_ph, YPDL_yptgdw, YPDL_GG, YPDL_JL, YPDL_SYFF);//插入数据

	

	// 执行 sql 语句。  
	// mysql_query() 的返回值份很多情形， 进行判断使要注意。  
	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		//AfxMessageBox(_T("添加探头标定温度信息成功!"));
	}
	else {
		AfxMessageBox(_T("添加样品队列信息失败!"));
	}
}


												
void MyDatabase::change_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF)//更改样品队列信息
{
	

	char insert4[1000];
	sprintf_s(insert4, "UPDATE 样品队列 SET 样品编号sql='%s',批号sql='%s',样品提供单位sql='%s',规格sql='%s',剂量sql='%s',试验方法sql='%s' WHERE 供试品名称sql='%s'", YPDL_ypbh, YPDL_ph, YPDL_yptgdw, YPDL_GG, YPDL_JL, YPDL_SYFF, YPDL_gspmc);


	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		AfxMessageBox(_T("样品队列信息修改成功！"));
	}
	else {
		AfxMessageBox(_T("样品队列信息修改失败!"));
	}
}


void MyDatabase::delete_yangpinduilie_mydatabase(char* YPDL_gspmc)//删除样品队列信息
{
	char insert[1000];
	sprintf_s(insert, "DELETE FROM 样品队列 WHERE 供试品名称sql='%s'", YPDL_gspmc);

	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		AfxMessageBox(_T("删除成功！"));
	}
	else {
		AfxMessageBox(_T("删除失败!"));
	}

}
void MyDatabase::add_point_BD_info(char* strDate,char* strTime, struct point_temperature point_temperature_info, int point_number) {//插入探头标定温度信息


	USES_CONVERSION;

	char insert4[1000];
	
	sprintf_s(insert4, "insert into 探头标定信息(Date,Time,point_Num,First_t_real,Second_t_real,Third_t_real,Fourth_t_real,Fifth_t_real,First_t_regress,Second_t_regress,Third_t_regress,Fourth_t_regress,Fifth_t_regress,Conclusion) values (\'%s\',  \'%s\',  %d,  \'%s\',\'%s\',  \'%s\',  \'%s\',  \'%s\',%f,%f,%f,%f,%f,  \'%s\')", strDate, strTime, point_number, T2A(point_temperature_info.first_t), T2A(point_temperature_info.second_t), T2A(point_temperature_info.third_t), T2A(point_temperature_info.fourth_t), T2A(point_temperature_info.fifth_t), point_temperature_info.first_regress, point_temperature_info.second_regress, point_temperature_info.third_regress, point_temperature_info.fourth_regress, point_temperature_info.fifth_regress, T2A(point_temperature_info.qualified));//插入数据



	// 执行 sql 语句。  
	// mysql_query() 的返回值份很多情形， 进行判断使要注意。  
	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		//AfxMessageBox(_T("添加探头标定温度信息成功!"));
	}
	else {
		AfxMessageBox(_T("添加探头标定温度信息失败!"));
	}



}


void MyDatabase::add_SYPC_info(int pointnum, CString tuhao,CString tizhong,CString jiliang,CString qbsj,CString zshsj,CString sswd,CString jw,CString wc,CString ssff,CString gspmc,CString ypbh,CString ph) {//插入试验排程信息



	char insert[1000];
	sprintf_s(insert, "insert into 试验排程(探头号sql,兔号sql,体重sql,剂量sql,全部时间sql,注射后时间sql,实时温度sql,均温sql,温差sql,试验方法sql,供试品名称sql,样品编号sql,批号sql) values ( %d,  \'%s\', \'%s\',  \'%s\',  \'%s\',\'%s\',  \'%s\',  \'%s\',  \'%s\', \'%s\',  \'%s\',  \'%s\',\'%s\')",  pointnum, tuhao.GetBuffer(), tizhong.GetBuffer(), jiliang.GetBuffer(), qbsj.GetBuffer(), zshsj.GetBuffer(), sswd.GetBuffer(), jw.GetBuffer(), wc.GetBuffer(), ssff.GetBuffer(), gspmc.GetBuffer(), ypbh.GetBuffer(), ph.GetBuffer());//插入数据



	// 执行 sql 语句。  
	// mysql_query() 的返回值份很多情形， 进行判断使要注意。  
	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		//AfxMessageBox(_T("添加探头标定温度信息成功!"));
	}
	else {
		AfxMessageBox(_T("添加探头标定温度信息失败!"));
	}



}