#include <FU/sysStream/FU_Console.h>

FU_Console* FU_Console::p_Instance=NULL;
FU_Console::FU_Console(void){

}
FU_Console::FU_Console(const FU_Console& oth){

}
FU_Console& FU_Console::operator=(const FU_Console& oth){
	return *this;
}

FU_Console& FU_Console::operator<<(const std::string& str){
	std::cout << str;
	return *this;
}