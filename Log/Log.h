#pragma once
#ifndef LOG_WGW
#define LOG_WGW "Log"
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

// Written by William Glenn Ward
// WilliamW1979@netscape.net

#if _M_IX86 && _DEBUG
#define ADD_WGW "_32_DEBUG"
#elif _M_IX86
#define ADD_WGW "_32"
#elif _DEBUG
#define ADD_WGW "_DEBUG"
#endif
#ifdef ADD_WGW
#pragma comment(lib, LOG_WGW ADD_WGW ".lib")
#else
#pragma comment(lib, LOG_WGW ".lib")
#endif

using std::string;
using std::ofstream;
using std::ios;
using std::ios_base;
using std::endl;
using std::flush;

class LOG
{
private:
	ofstream ofFile = {};
	string sFilename = "Log.txt";
	ios_base::openmode Mode = ios::app;
	char cSeparator = '-';
	bool bDatestamp = true;
	bool bTimestamp = true;
	bool bLocal = true;
	bool bDaySeparating = true;
	bool bSpaces = true;

public:
	LOG() { Open(); };
	LOG(string filename, ios_base::openmode Mode = ios::app);
	~LOG() { ofFile.close(); };

	void SetFilename(string filename) { sFilename = filename; };
	void SetDateTime(bool Date, bool Time) { bDatestamp = Date; bTimestamp = Time; };
	void SetSeparator(char Separator) { cSeparator = Separator; };
	void SetMode(ios_base::openmode Openmode) { Mode = Openmode; };
	void UseUTCTime() { bLocal = false; };
	void UseLocalTime() { bLocal = true; };
	void UseDayCutter(bool NewDay) { bDaySeparating = NewDay; };
	void UseSpaces(bool Spaces) { bSpaces = Spaces; };

	bool Open();
	void Close() { ofFile.close(); };

	bool Log(std::string Data, bool Newline = true);
	void ClearFile();
	void EraseFile();
};

#endif