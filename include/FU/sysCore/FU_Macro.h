#ifndef __FU_MACRO_
#define __FU_MACRO_
#ifndef FU_NO_MACRO

#include <FU/sysStream/FU_Console.h>
#define Console					FU_Console::Get_Instance()

#include <FU/sysLog/FU_Registro.h>
#define Registro				FU_Registro::Get_Instance()
#define ERRORE(ID,MESS)			FU_NewMessage(ID,MESS,TYPE_FU_MESS_ERROR,0)	
#define AVVISO(ID,MESS,LEV)		FU_NewMessage(ID,MESS,TYPE_FU_MESS_WARNING,LEV)

#endif
#endif