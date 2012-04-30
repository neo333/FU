#ifndef __FU_MESSAGE_
#define __FU_MESSAGE_

#include <string>

class FU_Registro;

enum TYPE_FU_MESS{
	TYPE_FU_MESS_ERROR,
	TYPE_FU_MESS_WARNING
};

class FU_Message{
public:
	/*Costruttore di copia*/
	FU_Message(const FU_Message& oth):ID(oth.ID),mess(oth.mess),type_mess(oth.type_mess),level_warning(oth.level_warning),
		file(oth.file),line(oth.line){

	}
private:
	friend class FU_Registro;
	FU_Message& operator=(const FU_Message& oth){
		return *this;
	}
private:
	const std::string ID;
	const std::string mess;
	const TYPE_FU_MESS type_mess;
	const unsigned int level_warning;
	const std::string file;
	const long line;

	std::string Rts_Type_inString(void) const{
		switch(this->type_mess){
		case TYPE_FU_MESS_ERROR:
			return std::string("ERRORE");
		default:
			return std::string("AVVISO");
		}
	}
public:
	/*Costruttore.
	Utilizzare la macro FU_NewMessage(...), per creare un nuovo messaggio:
		esempio:
			FU_Message temp=FU_NewMessage("ID","Mess",...);*/
	FU_Message(const std::string& id_p,const std::string& mess_p,const TYPE_FU_MESS& type_p,
		const unsigned int& lev_p, const std::string& file_p, const long& line_p):ID(id_p),mess(mess_p),
		type_mess(type_p), level_warning(lev_p), file(file_p), line(line_p){
	}

	/*Crea una copia di un messaggio già esistente.
	Usare la macro FU_CopyMessage(oth_mess) invece di questa funzione!*/
	static FU_Message CopyMessage(const char* file,const long line,const FU_Message& oth){
		return FU_Message::FU_Message(oth.ID,oth.mess,oth.type_mess,oth.level_warning,file,line);
	}
};

#define FU_NewMessage(ID,MESS,TYPE,LEV) FU_Message::FU_Message(ID,MESS,TYPE,LEV,__FILE__,__LINE__)
#define FU_CopyMessage(OTH) FU_Message::CopyMessage(__FILE__,__LINE__,OTH)

#endif