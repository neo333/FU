#ifndef __FU_FUNCT_
#define __FU_FUNCT_

#include <string>
#include <vector>

class FU_Funct{
public:
	class FF_Strings{
	public:
		/*Converte l'intero costante passato nel parametro in stringa.
		NOTA: il dato precedente contenuto nella stringa verrà cancellato!*/
		static void Integer_to_String(const int&, std::string&);

		/*Paragrafa una stringa scomponendo in linee se la stringa presenta caratteri new-line (\n)*/
		static void String_Formatted(const std::string&, std::vector<std::string>&);

		/*Ritorna una stringa contenente data e ora in formato intellegibile*/
		static std::string Get_TimeAndDate(void);
	};

	class FF_Core{
	private:
		static bool mode_debug;
	public:
		/*Ritorna true se la libreria è in esecuzione in modalità DEBUG; false altrimenti.*/
		static const bool& Is_ModeDebug(void){
			return FU_Funct::FF_Core::mode_debug;
		}

		/*Setta attiva o meno la modalità di debug della libreria*/
		static void Set_ModeDebug(const bool& pmode){
			FU_Funct::FF_Core::mode_debug=pmode;
		}
	};
};

#endif