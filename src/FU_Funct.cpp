#include <FU/sysCore/FU_Funct.h>
#include <ctime>

#define _CONV_MAX_STR_BUFFER 50
bool FU_Funct::FF_Core::mode_debug=true;

void FU_Funct::FF_Strings::Integer_to_String(const int& num, std::string& str){
#ifdef WIN32
	char buffer[_CONV_MAX_STR_BUFFER];
	_itoa_s(num,buffer,_CONV_MAX_STR_BUFFER,10);
	str.clear();
	str=buffer;
#else
#pragma warning("Funzione non supportata!")
#endif
}
void FU_Funct::FF_Strings::String_Formatted(const std::string& str, std::vector<std::string>& lines){
	lines.clear();
	std::size_t pos=str.find('\n'),cur=0;
	while(pos!=str.npos){
		lines.push_back(str.substr(cur,pos-cur));
		cur=pos+1;
		pos=str.find('\n',cur);
	}
	lines.push_back(str.substr(cur,pos));
}
std::string FU_Funct::FF_Strings::Get_TimeAndDate(void){
	const unsigned int WSDL_MAX_STR_NOW=50;
	std::string rts;
	time_t nowtime;
	time(&nowtime);
	char buffer[WSDL_MAX_STR_NOW];
	ctime_s(buffer,WSDL_MAX_STR_NOW,&nowtime);
	rts=buffer;
	return rts;
}