#ifndef __FU_STREAM_
#define __FU_STREAM_

/*
			FU_Stream
				by Neo333
	Questa classe rappresenta un'astrazione di uno 'Stream'.
	Uno Stream è un oggetto che permette il flusso di dati in ingresso o in uscita.

*/

#include <string>

class FU_Stream{
public:
	/*Apre uno stream. Ritorna true se l'operazione viene eseguita correttamente. Altrimenti false!*/
	virtual const bool Open(void)=0;

	/*Chiude uno stream. Viene invocato anche dal distruttore*/
	virtual void Close(void){

	}

	/*Ritorna true se uno stream è aperto, altrimenti false*/
	virtual const bool Is_Open(void) const=0;

	/*Distruttore*/
	virtual ~FU_Stream(void){
		this->Close();
	}

	/*Operatore di flusso su una std::string*/
	virtual FU_Stream& operator<<(const std::string&){
		return *this;
	}
};

#endif