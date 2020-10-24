//C log
//C语言函数参数无默认值概念
//所有的声明应该在函数的开头
//path = "C:\\yaoxiang.txt";
//__LINE__,  在content中加入行号
//__FUNCTION__, 获取当前函数名
//__FILE__, 获取当前文件名
void MyIntLog(int number, char* path, char* fileName, char* FUNCTION, int LINE)
{
        char strInt[32] = 0;
	sprintf(strInt, "%d", number);
	MyCharLog(strInt, path, fileName, FUNCTION, LINE);
	//memset(strInt, 0, strlen(strInt));
}

void MyCharLog(char* content, char* path, char* fileName, char* FUNCTION, int LINE)
{
	FILE* fp = NULL;
	char strWrite[256] = { '\0' };
	int i = 0;

	char ch1 = '/';
	char ch2 = '\\';
	char* fName;
	char* fName1 = strrchr(fileName, ch1);
	char* fName2 = strrchr(fileName, ch2);
	if(fName1 != NULL)
	{
	    fName = fName1 + 1;
	}
	else if(fName2 != NULL)
	{
	    fName = fName2 + 1;
	}
	else
	{
	    fName = "";
	}
	
	sprintf(strWrite, "[%s] FILE:%s Func:%s Line:%d -- MSG:[%s]", __TIME__, fName, FUNCTION, LINE, content);
	if (NULL != path)
	{
		fp = fopen(path, "a");
	}
	else
	{
		return;
	}
	for (; i < strlen(strWrite); i++)
	{
		fputc(strWrite[i], fp);
	}
	fputc('\n', fp);
	fclose(fp);
}

//MFC log
void OutputLog(LPCTSTR logName, CString msg)
{
	try
	{
		CStdioFile outFile(logName, CFile::modeNoTruncate | CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		CString msLine;
		CTime tt = CTime::GetCurrentTime();

		msLine = tt.Format("[%Y-%B-%d %A, %H:%M:%S] ") + msg;
		msLine += "\n";

		outFile.SeekToEnd();
		outFile.WriteString(msLine);
		outFile.Close();
	}
	catch (CFileException *fx)
	{
		fx->Delete();
	}
}


//C# log
public void Logger(String content, String path = "c:\\test.txt")
{

	// Write the string to a file.append mode is enabled so that the log
	// lines get appended to  test.txt than wiping content and writing the log

	System.IO.StreamWriter file = new System.IO.StreamWriter(path, true);
	file.WriteLine(content + "\r\t");

	file.Close();
}
