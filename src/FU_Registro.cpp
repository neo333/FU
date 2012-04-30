#include <FU/sysLog/FU_Registro.h>
#include <FU/sysCore/FU_Funct.h>

FU_Registro* FU_Registro::p_Instance=NULL;
FU_Registro::FU_Registro(void):level_mess(3){

}
FU_Registro::FU_Registro(const FU_Registro& oth){

}
FU_Registro& FU_Registro::operator=(const FU_Registro& oth){
	return *this;
}
bool FU_Registro::Add_Stream(FU_Stream* pp_stream){
	if(pp_stream==NULL) return false;
	this->p_streams.push_back(pp_stream);
	return true;
}
FU_Registro& FU_Registro::operator<<(const std::string& str){
	std::vector<FU_Stream*>::iterator it;
	for(it=this->p_streams.begin(); it!=this->p_streams.end(); it++){
		if((*it)->Is_Open()==false){
			if((*it)->Open()==true){
				*(*it) << str;
				(*it)->Close();
			}
		}else{
			*(*it) << str;
		}
	}
	return *this;
}
FU_Registro& FU_Registro::operator<<(const FU_Message& mess){
	if(mess.level_warning > this->level_mess && mess.type_mess==TYPE_FU_MESS_WARNING){
		return *this;
	}

	std::vector<std::string> mess_lines;
	std::string buffer_conv;
	FU_Funct::FF_Strings::String_Formatted(mess.mess,mess_lines);

	*this << "\t > " << mess.Rts_Type_inString() << " - " << mess.ID;
	if(mess.type_mess==TYPE_FU_MESS_WARNING){
		FU_Funct::FF_Strings::Integer_to_String(mess.level_warning,buffer_conv);
		*this << " - LEVEL: " << buffer_conv;
	}
	*this << "\n";
	std::vector<std::string>::iterator riga;
	for(riga=mess_lines.begin(); riga!=mess_lines.end(); riga++){
		*this << "\t\t" << (*riga) << "\n";
	}

	if(FU_Funct::FF_Core::Is_ModeDebug()){
		FU_Funct::FF_Strings::Integer_to_String(mess.line,buffer_conv);
		*this << "\t\t" << mess.file << "  - " << buffer_conv << "\n";
	}

	*this << "\n";

	return *this;
}
void FU_Registro::Print_Init(const std::string& title, const std::string& subtitle){
	*this << "---------------------------------------------------------------------\n\n"
			" " << title << "\n"
			" " << subtitle << "\n\n"
			" REGISTRO APPLICAZIONE: "<<FU_Funct::FF_Strings::Get_TimeAndDate() << "\n\n";
}