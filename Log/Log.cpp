#include "Log.h"


LOG::LOG(std::string filename, std::ios_base::openmode Mode)
{
	sFilename = filename;
	Mode = Mode;
}

bool LOG::Open()
{
	string sFilename2 = sFilename;
	if (bDaySeparating == true)
	{
		string date;
		char* buffer = new char[100];
		long long t = {};
		_time64(&t);
		tm now;
		if (bLocal) _localtime64_s(&now, &t);
		else _gmtime64_s(&now, &t);
		if (bSpaces)
		{
			strftime(buffer, 100, "%G %b %D %a", &now);
			sFilename2.append(" ");
		}
		else
		{
			strftime(buffer, 100, "%G_%b_%D_%a", &now);
			sFilename2.append("_");
		}
		sFilename2.append(buffer);
	}
	ofFile.open(sFilename2, Mode);
	if (!ofFile.is_open()) return false;
	return true;
}

void LOG::EraseFile()
{
	if(ofFile.is_open()) ofFile.close();
	remove(sFilename.c_str());
}

bool LOG::Log(std::string Data, bool newline)
{
	if (bTimestamp || bDatestamp)
	{
		long long iNow;
		tm tmNow;
		_time64(&iNow);
		if (bLocal) _localtime64_s(&tmNow, &iNow);
		else _gmtime64_s(&tmNow, &iNow);
		char date_string[100];
		char time_string[100];

		strftime(date_string, 50, "%a %b %d %G", &tmNow);
		strftime(time_string, 50, "%T", &tmNow);

		ofFile << "[";
		if (bDatestamp && bTimestamp)
			ofFile << date_string << " " << time_string;
		else if (bDatestamp)
			ofFile << date_string;
		else if (bTimestamp)
			ofFile << time_string;
		ofFile << "] ";
	}

	ofFile << Data;

	if (newline)
		ofFile << endl << flush;

	return true;
}

void LOG::ClearFile()
{
	if(ofFile.is_open()) ofFile.close();
	ofFile.open(sFilename, ios::out | ios::trunc);
}