#ifndef __FU_HARDDISK_
#define __FU_HARDDISK_

#include <cassert>
#include <FU/sysHD/FU_Page.h>

class FU_HardDisk{
private:
	FU_HardDisk(void);
	FU_HardDisk(const FU_HardDisk&);
	FU_HardDisk& operator=(const FU_HardDisk&);
	static FU_HardDisk* p_Instance;

	unsigned int key_cryp;
public:
	/*Ritorna l'istanza globale della classe*/
	static FU_HardDisk& Get_Instance(void){
		if(FU_HardDisk::p_Instance==NULL){
			FU_HardDisk::p_Instance = new FU_HardDisk();
			assert(FU_HardDisk::p_Instance);
		}
		return *FU_HardDisk::p_Instance;
	}

	/*Carica un file dal filesystem del sistema operativo.
	PARAMETRI:
		1) const std::string&	= path+nome file da caricare		_INPUT_
		2) const long&			= primo byte da leggere nel file	_INPUT_
		3) const long&			= offset di byte da leggere (numero
									di byte da leggere).
									Inserire -1 per leggere fino alla
									fine del file.					_INPUT_
		4) FU_Page&				= pagina della memoria che verrà
									caricata.
									Deve essere vuota!				_OUTPUT_
	RITORNO:
		Ritorna true se l'operazione va a buon file, altrimenti false*/
	bool LoadFile_toMemory(const std::string&, const long&, const long&, FU_Page&);
};

#endif