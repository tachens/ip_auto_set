#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <direct.h>
#include <errno.h>
#include <conio.h>
#include <stdlib.h>


int main()
{
	FIRST:
	char strFolderPath[] = { "C:\\ip자동설정기" };

	int nResult = _mkdir(strFolderPath);

	if (nResult == 0)
	{
		printf("폴더 생성 성공\n\n");
	}
	else if (nResult == -1)
	{
		char strPath[] = { "C:\\ip자동설정기\\집.bat" };

		int iResult = remove(strPath);

		if (iResult == 0)
		{
			printf("집.bat 파일 삭제 성공\n");
		}


		char dstrPath[] = { "C:\\ip자동설정기\\학교.bat" };

		int qResult = remove(dstrPath);

		if (qResult == 0)
		{
			printf("학교.bat파일 삭제 성공\n");
		}



		int mResult = _rmdir(strFolderPath);

		if (mResult == 0)
		{
			printf("폴더 삭제 성공\n");
			goto FIRST;
		}
		else if (mResult == -1)
		{
			perror("폴더 삭제 실패 - 폴더 안에 파일이 있거나 사용중");
			printf("로컬디스크C 에 있는 ip자동설정기 폴더을 삭제해주세요.\nerrorno : %d\n\n 엔터를 눌러 창을 닫아주세요.\n", errno); _getch(); return 0;
		}


	}

	FILE* fp;
	int num;
	printf("자신의 아이피 마지막 자리 입력 \n예 : 10.220.12.141 일 경우 141\n\n");
	scanf("%d", &num);

	fp = fopen("C:\\ip자동설정기\\집.bat", "wt");
	if (fp == NULL) {
		printf("집.bat 파일 생성 실패");
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
	fprintf(fp, "netsh -c int ip set address name=\"Wi-Fi\" dhcp\n");
	fprintf(fp, "netsh -c int ip set dnsservers \"Wi-Fi\" dhcp\n");


	fclose(fp);

	fp = fopen("C:\\ip자동설정기\\학교.bat", "wt");
	if (fp == NULL) {
		printf("학교.bat 파일 생성 실패");
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
	fprintf(fp, "netsh -c int ip set address name=\"Wi-Fi\" static 10.220.12.%d 255.255.255.0 gateway=10.220.12.1\n", num);
	fprintf(fp, "netsh -c int ip set dnsservers \"Wi-Fi\" static 168.126.63.2  primary no\n");


	fclose(fp);

	printf("\n완료\n\nip : 10.220.12.%d \n\n파일은 로컬디스크C ip자동설정기 폴더에 생성됩니다.\n바탕화면으로 이동시켜 사용하시면 됩니다.\n오류는 202100041@ushs.hs.kr로 보내주시기 바랍니다.\n\n엔터를 눌러 종료하세요.", num);


	_getch();





}
