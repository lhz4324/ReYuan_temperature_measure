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


bool MyDatabase::ConnectDB_orcreate()//�������ݿ�
{

	

	const char user[] = "root";
	const char pswd[] = "root";
	const char host[] = "localhost";
	unsigned int port = 3306;

	CString dbname = L"reyuan_mydatabase";
	
	//MYSQL m_sqlCon;
	// 1.��ʼ�����ݿ���
	mysql_init(&m_sqlCon);
	res = nullptr;
	// 2.�����ַ�����
	mysql_options(&m_sqlCon, MYSQL_SET_CHARSET_NAME, "gbk");
	
	//char value = 1;
	//mysql_options(&m_sqlCon, MYSQL_OPT_RECONNECT, &value);



	if (mysql_real_connect(&m_sqlCon, host, user, pswd, "mysql", port, NULL, 0)) {

	

		std::string create_db = "CREATE DATABASE IF NOT EXISTS " + CS2S(dbname) + " DEFAULT CHARACTER SET utf8";
		if (0 != mysql_query(&m_sqlCon, create_db.c_str()))
		{	
			AfxMessageBox(_T("���ݿⴴ��ʱ����ʧ��"));
			return false;
		}
		mysql_close(&m_sqlCon);

		

		mysql_init(&m_sqlCon);//����ͳ�ʼ����myonlydatabase��m_sqlCon
		res = nullptr;
		mysql_options(&m_sqlCon, MYSQL_SET_CHARSET_NAME, "gbk");
	/*	char value = 1;
		mysql_options(&m_sqlCon, MYSQL_OPT_RECONNECT, &value);*/
	}




	if (!mysql_real_connect(&m_sqlCon, host, user, pswd, CStringA(dbname), port, NULL, 0)) {
		return false;
		AfxMessageBox(_T("���ݿ�����ʧ��"));

	}


	//1.���� ̽ͷ�궨��Ϣ  ���
	CString table_str1 = _T("\
	CREATE TABLE  IF NOT EXISTS `̽ͷ�궨��Ϣ` (\
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


	//2.����  ��Ʒ����   ���
	CString table_str2 = _T("\
	CREATE TABLE  IF NOT EXISTS `��Ʒ����` (\
		`����Ʒ����sql` VARCHAR(45) NOT NULL,\
		`��Ʒ���sql` VARCHAR(45) NULL,\
		`����sql` VARCHAR(45) NULL,\
		`��Ʒ�ṩ��λsql` VARCHAR(45) NULL,\
		`���sql` VARCHAR(45) NULL,\
		`����sql` VARCHAR(45) NULL,\
		`���鷽��sql` VARCHAR(45) NOT NULL,\
		`��ǰ�����ܺ�sql` VARCHAR(45) NULL,\
		`��ǰ����ֻ��sql` VARCHAR(45) NULL,\
		PRIMARY KEY(`����Ʒ����sql`, `���鷽��sql`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str2).c_str()))
	{

		return false;
	}

	//PRIMARY KEY(`����Ʒ����sql`, `���鷽��sql`, `��ǰ�����ܺ�sql`, `��ǰ����ֻ��sql`, `��Ʒ���sql`, `��Ʒ�ṩ��λsql`, `����sql`)\
	
	//3.����  ��Ʒ��Ϣ   ���
	CString table_str3 = _T("\
	CREATE TABLE  IF NOT EXISTS `��Ʒ��Ϣ` (\
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


	//4.����  �û��˺�����   ���
	CString table_str4 = _T("\
	CREATE TABLE  IF NOT EXISTS `�û��˺�����` (\
		`name` VARCHAR(45) NOT NULL,\
		`password` VARCHAR(45) NULL,\
		`juese` VARCHAR(45) NULL,\
		`quanxiandengji` VARCHAR(45) NULL,\
		`���ε�¼��������` INT(11) NULL,\
		`�˻�����` INT(11) NULL,\
		`�¶Ȳⶨ` INT(11) NULL,\
		`��Ʒ��Ϣ����` INT(11) NULL,\
		`��¼��ʽ����` INT(11) NULL,\
		`�鿴̽ͷ�궨���` INT(11) NULL,\
		`�鿴������ѡ���` INT(11) NULL,\
		`��ѯ����ӡ��ԭ���` INT(11) NULL,\
		`���ݱ���` INT(11) NULL,\
		`�궨̽ͷ` INT(11) NULL,\
		`�趨ʵʱ������������` INT(11) NULL,\
		`�����������` INT(11) NULL,\
		`���ݸ�ʽ����` INT(11) NULL,\
		`�鿴��ѡ����` INT(11) NULL,\
		`����ά��` INT(11) NULL,\
		`�˻�����` INT(11) NULL,\
		PRIMARY KEY(`name`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str4).c_str()))
	{

		return false;
	}


	//5.����  �����ų�   ���
	CString table_str5 = _T("\
	CREATE TABLE  IF NOT EXISTS `�����ų�` (\
		`̽ͷ��sql` INT NOT NULL,\
		`�ú�sql` VARCHAR(45) NULL,\
		`����sql` VARCHAR(45) NULL,\
		`����sql` VARCHAR(45) NULL,\
		`ȫ��ʱ��sql` VARCHAR(45) NULL,\
		`ע���ʱ��sql` VARCHAR(45) NULL,\
		`ʵʱ�¶�sql` VARCHAR(45) NULL,\
		`����sql` VARCHAR(45) NULL,\
		`�²�sql` VARCHAR(45) NULL,\
		`���鷽��sql` VARCHAR(45) NULL,\
		`����Ʒ����sql` VARCHAR(45) NULL,\
		`��Ʒ���sql` VARCHAR(45) NULL,\
		`����sql` VARCHAR(45) NULL,\
		PRIMARY KEY(`̽ͷ��sql`)\
			)");
	if (0 != mysql_query(&m_sqlCon, CS2S(table_str5).c_str()))
	{

		return false;
	}


	//6.����  ѡ����Ʒ  ���
	CString table_str6 = _T("\
	CREATE TABLE  IF NOT EXISTS `ѡ����Ʒ` (\
		`����Ʒ����sql` VARCHAR(45) NOT NULL,\
		`��Ʒ���sql` VARCHAR(45) NULL,\
		`����sql` VARCHAR(45) NULL,\
		`��Ʒ�ṩ��λsql` VARCHAR(45) NULL,\
		`���sql` VARCHAR(45) NULL,\
		`��ǰ�����ܺ�sql` VARCHAR(45) NULL,\
		`��ǰ����ֻ��sql` VARCHAR(45) NULL,\
		PRIMARY KEY(`����Ʒ����sql`)\
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
	sprintf_s(insert, "insert into �û��˺�����(name, password,juese,quanxiandengji,���ε�¼��������,�˻�����,�¶Ȳⶨ,��Ʒ��Ϣ����,��¼��ʽ����,�鿴̽ͷ�궨���,�鿴������ѡ���,��ѯ����ӡ��ԭ���,���ݱ���,�궨̽ͷ,�趨ʵʱ������������,�����������,���ݸ�ʽ����,�鿴��ѡ����,����ά��,�˻�����) values (\'%s\',  \'%s\', \'%s\',  \'%s\', %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d, %d,  %d)",
		T2A(user_info_now.username_now), T2A(user_info_now.password_now), T2A(user_info_now.juese_now), "erji", user_info_now.ccdlggmm_now, user_info_now.zhsd_now, user_info_now.wdcd_now, user_info_now.ypxxsz_now, user_info_now.jlgssz_now, user_info_now.ckttbdjg_now, user_info_now.ckxttxjg_now, user_info_now.cxdyryjg_now, user_info_now.sjbf_now, user_info_now.bdtt_now, user_info_now.sdsscwqxsf_now, user_info_now.gzsjsj_now, user_info_now.sjgssz_now, user_info_now.cklxjt_now, user_info_now.sjwh_now, user_info_now.zhgl_now);//��������


	// ִ�� sql ��䡣  
	// mysql_query() �ķ���ֵ�ݺܶ����Σ� �����ж�ʹҪע�⡣  
	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		AfxMessageBox(_T("����˻���Ϣ�ɹ�!"));
	}
	else {
		AfxMessageBox(_T("����˻���Ϣʧ��!"));
	}

}


void MyDatabase::change_account(struct user_info user_info_now){



	USES_CONVERSION;

	char insert2[1000];
	sprintf_s(insert2, "UPDATE �û��˺����� SET password='%s',juese='%s',���ε�¼��������=%d,�˻�����=%d,�¶Ȳⶨ=%d,��Ʒ��Ϣ����=%d,��¼��ʽ����=%d,�鿴̽ͷ�궨���=%d,�鿴������ѡ���=%d,��ѯ����ӡ��ԭ���=%d,���ݱ���=%d,�궨̽ͷ=%d,�趨ʵʱ������������=%d,�����������=%d,���ݸ�ʽ����=%d,�鿴��ѡ����=%d,����ά��=%d,�˻�����=%d WHERE name='%s'",
		T2A(user_info_now.password_now), T2A(user_info_now.juese_now), user_info_now.ccdlggmm_now, user_info_now.zhsd_now, user_info_now.wdcd_now, user_info_now.ypxxsz_now, user_info_now.jlgssz_now, user_info_now.ckttbdjg_now, user_info_now.ckxttxjg_now, user_info_now.cxdyryjg_now, user_info_now.sjbf_now, user_info_now.bdtt_now, user_info_now.sdsscwqxsf_now, user_info_now.gzsjsj_now, user_info_now.sjgssz_now, user_info_now.cklxjt_now, user_info_now.sjwh_now, user_info_now.zhgl_now, T2A(user_info_now.username_now));//��������;

	if (mysql_query(&m_sqlCon, insert2) == 0)
	{
		AfxMessageBox(_T("�޸ĳɹ���"));

	}
	else {
		AfxMessageBox(_T("�޸�ʧ��!"));

	}


}


void MyDatabase::change_account_password_mydatabase(char* new_password, char*  username_now){//�����˻�����



	char insert2[1000];
	sprintf_s(insert2, "UPDATE �û��˺����� SET password='%s' WHERE name='%s'", new_password, username_now);

	if (mysql_query(&m_sqlCon, insert2) == 0)
	{
		AfxMessageBox(_T("�޸ĳɹ���"));

	}
	else {
		AfxMessageBox(_T("�޸�ʧ��!"));

	}


}



void MyDatabase::add_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY)//�����Ʒ��Ϣ
{
	
	char insert3[1000];
	sprintf_s(insert3, "insert into ��Ʒ��Ϣ(YPMC_sjk, GG_sjk,JL_sjk,GSRYPZ_sjk) values (\'%s\',  \'%s\',  \'%s\',  \'%s\')", SET_YPXX_YPMC, SET_YPXX_GG, SET_YPXX_JL, SET_YPXX_GSRY);//��������

	// ִ�� sql ��䡣  
	// mysql_query() �ķ���ֵ�ݺܶ����Σ� �����ж�ʹҪע�⡣  

	if (mysql_query(&m_sqlCon, insert3) == 0)
	{
		AfxMessageBox(_T("�����Ʒ��Ϣ�ɹ�!"));
	}
	else {
		AfxMessageBox(_T("�����Ʒ��Ϣʧ��!"));
	}
}

void MyDatabase::change_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC, char* SET_YPXX_GG, char* SET_YPXX_JL, char* SET_YPXX_GSRY) //������Ʒ��Ϣ
{



	char insert4[1000];
	sprintf_s(insert4, "UPDATE ��Ʒ��Ϣ SET GG_sjk='%s',JL_sjk='%s',GSRYPZ_sjk='%s' WHERE YPMC_sjk='%s'",  SET_YPXX_GG, SET_YPXX_JL, SET_YPXX_GSRY, SET_YPXX_YPMC);


	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		AfxMessageBox(_T("�޸ĳɹ���"));
	}
	else {
		AfxMessageBox(_T("�޸�ʧ��!"));
	}

}

void MyDatabase::delete_yangpinxinxi_mydatabase(char* SET_YPXX_YPMC)//ɾ����Ʒ��Ϣ
{

	char insert[1000];
	sprintf_s(insert, "DELETE FROM ��Ʒ��Ϣ WHERE YPMC_sjk='%s'", SET_YPXX_YPMC);

	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		AfxMessageBox(_T("ɾ���ɹ���"));
	}
	else {
		AfxMessageBox(_T("ɾ��ʧ��!"));
	}

}





void MyDatabase::add_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF)//������Ʒ������Ϣ
{
	

	char insert4[1000];
	sprintf_s(insert4, "insert into ��Ʒ����(����Ʒ����sql,��Ʒ���sql,����sql,��Ʒ�ṩ��λsql,���sql,����sql,���鷽��sql) values (\'%s\',  \'%s\',  \'%s\', \'%s\',  \'%s\',  \'%s\',  \'%s\')", YPDL_gspmc, YPDL_ypbh, YPDL_ph, YPDL_yptgdw, YPDL_GG, YPDL_JL, YPDL_SYFF);//��������

	

	// ִ�� sql ��䡣  
	// mysql_query() �ķ���ֵ�ݺܶ����Σ� �����ж�ʹҪע�⡣  
	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		//AfxMessageBox(_T("���̽ͷ�궨�¶���Ϣ�ɹ�!"));
	}
	else {
		AfxMessageBox(_T("�����Ʒ������Ϣʧ��!"));
	}
}


												
void MyDatabase::change_yangpinduilie_mydatabase(char* YPDL_gspmc, char* YPDL_ypbh, char* YPDL_ph, char* YPDL_yptgdw, char* YPDL_GG, char* YPDL_JL, char* YPDL_SYFF)//������Ʒ������Ϣ
{
	

	char insert4[1000];
	sprintf_s(insert4, "UPDATE ��Ʒ���� SET ��Ʒ���sql='%s',����sql='%s',��Ʒ�ṩ��λsql='%s',���sql='%s',����sql='%s',���鷽��sql='%s' WHERE ����Ʒ����sql='%s'", YPDL_ypbh, YPDL_ph, YPDL_yptgdw, YPDL_GG, YPDL_JL, YPDL_SYFF, YPDL_gspmc);


	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		AfxMessageBox(_T("��Ʒ������Ϣ�޸ĳɹ���"));
	}
	else {
		AfxMessageBox(_T("��Ʒ������Ϣ�޸�ʧ��!"));
	}
}


void MyDatabase::delete_yangpinduilie_mydatabase(char* YPDL_gspmc)//ɾ����Ʒ������Ϣ
{
	char insert[1000];
	sprintf_s(insert, "DELETE FROM ��Ʒ���� WHERE ����Ʒ����sql='%s'", YPDL_gspmc);

	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		AfxMessageBox(_T("ɾ���ɹ���"));
	}
	else {
		AfxMessageBox(_T("ɾ��ʧ��!"));
	}

}
void MyDatabase::add_point_BD_info(char* strDate,char* strTime, struct point_temperature point_temperature_info, int point_number) {//����̽ͷ�궨�¶���Ϣ


	USES_CONVERSION;

	char insert4[1000];
	
	sprintf_s(insert4, "insert into ̽ͷ�궨��Ϣ(Date,Time,point_Num,First_t_real,Second_t_real,Third_t_real,Fourth_t_real,Fifth_t_real,First_t_regress,Second_t_regress,Third_t_regress,Fourth_t_regress,Fifth_t_regress,Conclusion) values (\'%s\',  \'%s\',  %d,  \'%s\',\'%s\',  \'%s\',  \'%s\',  \'%s\',%f,%f,%f,%f,%f,  \'%s\')", strDate, strTime, point_number, T2A(point_temperature_info.first_t), T2A(point_temperature_info.second_t), T2A(point_temperature_info.third_t), T2A(point_temperature_info.fourth_t), T2A(point_temperature_info.fifth_t), point_temperature_info.first_regress, point_temperature_info.second_regress, point_temperature_info.third_regress, point_temperature_info.fourth_regress, point_temperature_info.fifth_regress, T2A(point_temperature_info.qualified));//��������



	// ִ�� sql ��䡣  
	// mysql_query() �ķ���ֵ�ݺܶ����Σ� �����ж�ʹҪע�⡣  
	if (mysql_query(&m_sqlCon, insert4) == 0)
	{
		//AfxMessageBox(_T("���̽ͷ�궨�¶���Ϣ�ɹ�!"));
	}
	else {
		AfxMessageBox(_T("���̽ͷ�궨�¶���Ϣʧ��!"));
	}



}


void MyDatabase::add_SYPC_info(int pointnum, CString tuhao,CString tizhong,CString jiliang,CString qbsj,CString zshsj,CString sswd,CString jw,CString wc,CString ssff,CString gspmc,CString ypbh,CString ph) {//���������ų���Ϣ



	char insert[1000];
	sprintf_s(insert, "insert into �����ų�(̽ͷ��sql,�ú�sql,����sql,����sql,ȫ��ʱ��sql,ע���ʱ��sql,ʵʱ�¶�sql,����sql,�²�sql,���鷽��sql,����Ʒ����sql,��Ʒ���sql,����sql) values ( %d,  \'%s\', \'%s\',  \'%s\',  \'%s\',\'%s\',  \'%s\',  \'%s\',  \'%s\', \'%s\',  \'%s\',  \'%s\',\'%s\')",  pointnum, tuhao.GetBuffer(), tizhong.GetBuffer(), jiliang.GetBuffer(), qbsj.GetBuffer(), zshsj.GetBuffer(), sswd.GetBuffer(), jw.GetBuffer(), wc.GetBuffer(), ssff.GetBuffer(), gspmc.GetBuffer(), ypbh.GetBuffer(), ph.GetBuffer());//��������



	// ִ�� sql ��䡣  
	// mysql_query() �ķ���ֵ�ݺܶ����Σ� �����ж�ʹҪע�⡣  
	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		//AfxMessageBox(_T("���̽ͷ�궨�¶���Ϣ�ɹ�!"));
	}
	else {
		AfxMessageBox(_T("���̽ͷ�궨�¶���Ϣʧ��!"));
	}



}