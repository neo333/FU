#ifndef __FU_PAGE_
#define __FU_PAGE_

#include <string>

class FU_HardDisk;

class FU_Page{
private:
	friend class FU_HardDisk;
	char* pnt_mem;
	unsigned long size;

	void ClearMem(void){
		if(this->pnt_mem){
			delete[] this->pnt_mem;
			this->pnt_mem=NULL;
			this->size=0;
		}
	}
public:
	FU_Page(void):pnt_mem(NULL),size(0){

	}
	~FU_Page(void){
		this->ClearMem();
	}
	bool Is_Loaded(void) const{
		if(this->pnt_mem){
			return true;
		}
		return false;
	}

	char* Get_MemoryPointer(void){
		return this->pnt_mem;
	}
	unsigned long Get_MemorySize(void){
		return this->size;
	}
};

#endif