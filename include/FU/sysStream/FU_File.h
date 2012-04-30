#ifndef __FU_FILE_
#define __FU_FILE_

/*
			FU_File
				by Neo333
	Questa classe è uno stream di tipo FILE.
	E' una classe derivata da fstream!

*/

#include <fstream>
#include <FU/sysStream/FU_Stream.h>

class FU_File: public FU_Stream, public std::fstream{
private:
	std::string filename;
	ios_base::openmode mode_file;
public:
	FU_File(const std::string& pstr=std::string(""), ios_base::openmode p_mode=std::ios::in):filename(pstr),mode_file(p_mode){

	}
	virtual const bool Open(void){
		if(this->filename.size()>0){
			this->open(this->filename.c_str(),this->mode_file);
			if(!this->fail()){
				return true;
			}
		}
		return false;
	}
	virtual void Close(void){
		if(this->is_open()){
			this->close();
		}
	}
	virtual const bool Is_Open(void) const{
		return this->is_open();
	}
	~FU_File(void){
		this->Close();
	}

	virtual FU_File& operator<<(const std::string& str){
		std::fstream& ogg=(std::fstream&) *this;
		ogg << str;
		return *this;
	}
};

#endif