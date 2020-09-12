#include <iostream>
#include <windows.h>
#include <assert.h>
#include <vector>

int main()
{
	return 0;
}

void OutputWindowsVersion()
{
	const auto system = L"kernel32.dll";
	DWORD dummy;
	const auto cbInfo =
		::GetFileVersionInfoSizeExW(FILE_VER_GET_NEUTRAL, system, &dummy);
	std::vector<char> buffer(cbInfo);
	::GetFileVersionInfoExW(FILE_VER_GET_NEUTRAL, system, dummy,
		buffer.size(), &buffer[0]);
	void *p = nullptr;
	UINT size = 0;
	::VerQueryValueW(buffer.data(), L"\\", &p, &size);
	assert(size >= sizeof(VS_FIXEDFILEINFO));
	assert(p != nullptr);
	auto pFixed = static_cast<const VS_FIXEDFILEINFO *>(p);
	std::cout << HIWORD(pFixed->dwFileVersionMS) << '.'
		<< LOWORD(pFixed->dwFileVersionMS) << '.'
		<< HIWORD(pFixed->dwFileVersionLS) << '.'
		<< LOWORD(pFixed->dwFileVersionLS) << '\n';
}

void CheckAndCopyFile()
{

	LPCTSTR str = _T("C:\\windows\\fonts\\marlett.ttf");
	BOOL FLAG = PathFileExists(str);
	if (!FLAG)
	{
		CopyFile(_T(".\\log.txt"), _T("c:\\temp\\log.txt"), TRUE);
	}
}

void WriteRegisterSZ(CString name, CString csValue)
{
	HKEY hKey = nullptr;

	if (ERROR_SUCCESS != RegCreateKey(HKEY_LOCAL_MACHINE, TEXT("Software\\Microsoft\\Windows NT\\CurrentVersion\\Fonts"), &hKey))
	{
		return;
	}

	LPBYTE lpValue = new BYTE[2 * csValue.GetLength() + 2];
	for (int i = 0; i <= csValue.GetLength(); i++)
	{
		lpValue[2 * i] = csValue[i];
		lpValue[2 * i + 1] = 0;
	}

	DWORD cbData = (csValue.GetLength() + 1) * 2;

	LONG lRet = 0;

	if (ERROR_SUCCESS != (lRet = RegSetValueEx(hKey, name, 0, REG_SZ, lpValue, cbData)))
	{
		return;
	}

	RegCloseKey(hKey);

	delete lpValue;
}

CString GetMoudulePath()
{
	CString strRetun = _T("");
#ifdef _UNICODE
	TCHAR szBuff[MAX_PATH];
	HMODULE module = GetModuleHandle(0);
	GetModuleFileName(module, szBuff, sizeof(szBuff));
	strRetun.Format(_T("%s"), szBuff);
#else
	HMODULE module = GetModuleHandle(0);
	CHAR szBuff[MAX_PATH];
	GetModuleFileName(module, szBuff, sizeof(szBuff));
	strRetun.Format(_T("%s"), szBuff);
#endif
	int pos = strRetun.ReverseFind(_T('\\'));
	if (pos != -1)
	{
		strRetun = strRetun.Left(pos);
	}
	return strRetun;
}
