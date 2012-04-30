#ifndef __FU_REGISTRO_
#define __FU_REGISTRO_

#include <cassert>
#include <vector>
#include <FU/sysStream/FU_Stream.h>
#include <FU/sysLog/FU_Message.h>

class FU_Registro{
private:
	FU_Registro(void);
	FU_Registro(const FU_Registro&);
	FU_Registro& operator=(const FU_Registro&);
	static FU_Registro* p_Instance;

	std::vector<FU_Stream*> p_streams;
	unsigned int level_mess;
public:
	/*Ritorna l'instanza globale del registro*/
	static FU_Registro& Get_Instance(void){
		if(FU_Registro::p_Instance==NULL){
			FU_Registro::p_Instance=new FU_Registro();
			assert(FU_Registro::p_Instance);
		}
		return *FU_Registro::p_Instance;
	}

	/*Aggiunge un puntatore ad uno stream sul quale verranno scritti i messaggi del registro*/
	bool Add_Stream(FU_Stream*);

	/*Ritorna il livello del filtro dei messaggi di avviso*/
	const unsigned int& Get_LevelMess(void) const{
		return this->level_mess;
	}

	/*Setta il livello del filtro dei messaggi di avviso.
	I messaggi con livello più alto di quello settato verranno ignorati dal registro*/
	void Set_LevelMess(const unsigned int& lev_param){
		this->level_mess=lev_param;
	}

	/*Inserisce un messaggio nel registro*/
	FU_Registro& operator<<(const FU_Message&);

	/*Operatore di flusso per std::string*/
	FU_Registro& operator<<(const std::string&);

	/*Stampa un'intestazione di default nel registro.
	Parametri: titolo e sottotitolo*/
	void Print_Init(const std::string&, const std::string&);
};

#endif