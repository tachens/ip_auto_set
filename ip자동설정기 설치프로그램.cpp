#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <direct.h>
#include <errno.h>
#include <conio.h>



int main()
{
	char strFolderPath[] = { "C:\\ip�ڵ�������" };
	
	int nResult = mkdir( strFolderPath );
 
	if( nResult == 0 )
	{
		printf( "���� ���� ����\n\n" );
	}
	else if( nResult == -1 )
	{
		perror( "���� ���� ���� - ������ �̹� �ְų� ����Ȯ��(���õ�ũ C�� �ִ� ip�ڵ������� ������ ������ �ּ���.)\n" );
		printf( "errorno : %d", errno ); return 0;
	}
	
	FILE *fp;
	int num;
	printf("�ڽ��� ������ ������ �ڸ� �Է� \n�� : 10.220.12.141 �� ��� 141\n");
	scanf("%d",&num);
	
	fp = fopen( "C:\\ip�ڵ�������\\��.bat", "wt" );
	if(fp==NULL){
		printf("��.bat ���� ���� ����"); 
		return 1;
	}
	fprintf(fp, "REM --add the following to the top of your bat file--\n");
	fprintf(fp, "@echo off\n");
	fprintf(fp, ":: BatchGotAdmin\n");
	fprintf(fp, ":-------------------------------------\n");
	fprintf(fp, "REM --> Check for permissions\n");
	fprintf(fp, ">nul 2>&1 \"%%SYSTEMROOT%%\\system32\\cacls.exe\" \"%%SYSTEMROOT%%\\system32\\config\\system\"\n");
	fprintf(fp, "REM --> If error flag set, we do not have admin.\n");
	fprintf(fp, "if \'%%errorlevel%%\' NEQ \'0\' (\n");
	fprintf(fp, "echo Requesting administrative privileges...\n");
	fprintf(fp, "goto UACPrompt\n");
	fprintf(fp, ") else ( goto gotAdmin )\n");
	fprintf(fp, ":UACPrompt\n");
	fprintf(fp, "echo Set UAC = CreateObject^(\"Shell.Application\"^) > \"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "set params = %%*:\"=\"\"\n");
	fprintf(fp, "echo UAC.ShellExecute \"cmd.exe\", \"/c %%~s0 %%params%%\", \"\", \"runas\", 1 >> \"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "\"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "del \"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "exit /B\n");
	fprintf(fp, ":gotAdmin\n");
	fprintf(fp, "pushd \"%%CD\"\n");
	fprintf(fp, "CD /D \"%%~dp0\" \n");
	fprintf(fp, ":-------------------------------------\n");
	fprintf(fp, "netsh -c int ip set address name=\"Wi-Fi\" dhcp\n");
	fprintf(fp, "netsh -c int ip set dnsservers \"Wi-Fi\" dhcp\n");
	
	
	fclose(fp);
	
	fp = fopen( "C:\\ip�ڵ�������\\�б�.bat", "wt" );
	if(fp==NULL){
		printf("�б�.bat ���� ���� ����");
		return 1;
	}
	fprintf(fp, "REM --add the following to the top of your bat file--\n");
	fprintf(fp, "@echo off\n");
	fprintf(fp, ":: BatchGotAdmin\n");
	fprintf(fp, ":-------------------------------------\n");
	fprintf(fp, "REM --> Check for permissions\n");
	fprintf(fp, ">nul 2>&1 \"%%SYSTEMROOT%%\\system32\\cacls.exe\" \"%%SYSTEMROOT%%\\system32\\config\\system\"\n");
	fprintf(fp, "REM --> If error flag set, we do not have admin.\n");
	fprintf(fp, "if \'%%errorlevel%%\' NEQ \'0\' (\n");
	fprintf(fp, "echo Requesting administrative privileges...\n");
	fprintf(fp, "goto UACPrompt\n");
	fprintf(fp, ") else ( goto gotAdmin )\n");
	fprintf(fp, ":UACPrompt\n");
	fprintf(fp, "echo Set UAC = CreateObject^(\"Shell.Application\"^) > \"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "set params = %%*:\"=\"\"\n");
	fprintf(fp, "echo UAC.ShellExecute \"cmd.exe\", \"/c %%~s0 %%params%%\", \"\", \"runas\", 1 >> \"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "\"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "del \"%%temp%%\\getadmin.vbs\"\n");
	fprintf(fp, "exit /B\n");
	fprintf(fp, ":gotAdmin\n");
	fprintf(fp, "pushd \"%%CD%%\"\n");
	fprintf(fp, "CD /D \"%%~dp0\" \n");
	fprintf(fp, ":-------------------------------------\n");
	fprintf(fp, "netsh -c int ip set address name=\"Wi-Fi\" static 10.220.12.%d 255.255.255.0 gateway=10.220.12.1\n",num);
	fprintf(fp, "netsh -c int ip set dnsservers \"Wi-Fi\" static 168.126.63.2  primary no\n");
	
	
	fclose(fp);
	
	printf("�Ϸ�\nip : 10.220.12.%d \n������ ���õ�ũC ip�ڵ������� ������ �����˴ϴ�.\n���͸� ���� â�� �ݾ��ֽʽÿ�.",num);
	
	
	getch();	 




	
}
