#ifndef __FU_CONSOLE_
#define __FU_CONSOLE_

/*
			FU_Console
				by Neo333
	Questa classe rappresenta l'oggetto console.
	E' un'instanza globale

*/

#include <FU/sysStream/FU_Stream.h>
#include <cassert>
#include <iostream>

class FU_Console: public FU_Stream{
private:
	FU_Console(void);
	FU_Console(const FU_Console&);
	FU_Console& operator=(const FU_Console&);
	static FU_Console* p_Instance;

public:
	/*Ritorna l'instanza globale della console*/
	static FU_Console& Get_Instance(void){
		if(FU_Console::p_Instance==NULL){
			FU_Console::p_Instance=new FU_Console();
			assert(FU_Console::p_Instance);
		}
		return *FU_Console::p_Instance;
	}

	/*Apre lo stream. Non è necessario chiamare questo metodo per questo tipo di stream!*/
	virtual const bool Open(void){
		return true;
	}

	/*Chiude lo stream. Non è necessario chiamare questo metodo per questo tipo di stream!*/
	virtual void Close(void){
	}

	/*Ritorna sempre 'true' per questo stream*/
	virtual const bool Is_Open(void) const{
		return true;
	}

	/*Operatore di flusso per std::string*/
	virtual FU_Console& operator<<(const std::string&);

	/*Operatore di flusso generico*/
	template<class type> FU_Console& operator<<(const type& obj){
		std::cout << obj;
		return *this;
	}
};

#endif