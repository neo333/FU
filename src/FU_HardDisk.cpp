#include <FU/sysHD/FU_HardDisk.h>
#include <cstdio>

FU_HardDisk* FU_HardDisk::p_Instance=NULL;
FU_HardDisk::FU_HardDisk(void):key_cryp(0){

}
FU_HardDisk::FU_HardDisk(const FU_HardDisk& oth){

}
FU_HardDisk& FU_HardDisk::operator=(const FU_HardDisk& oth){
	return *this;
}

bool FU_HardDisk::LoadFile_toMemory(const std::string& filename, const long& cur_start, const long& asize, FU_Page& page){
	if(cur_start<0  || filename.size() < 0){
		//TODO: fare errore, parametri di chiamata non corretti!
		return false;
	}
	if(page.pnt_mem){
		//TODO: fare errore, page già occupata
		return false;
	}

	FILE* pfile=NULL;
#ifdef WIN32
	fopen_s(&pfile,filename.c_str(),"rb");
#else
	pfile=fopen(filename.c_str(),"rb");
#endif
	if(pfile==NULL){
		//TODO: fare errore. Impossibile accedere al file.
		return false;
	}
	
	
	unsigned long size_effective, size_file_tot;
	fseek(pfile, 0, SEEK_END);
	size_file_tot=ftell(pfile);
	if(asize>=0){
		size_effective=asize;
	}else{
		size_effective=size_file_tot-cur_start;		
	}

	if(fseek(pfile,cur_start,SEEK_SET)!=0){
		//TODO: fare errore. Impossibile posizionare il cursore del file nell'area richiesta
		fclose(pfile);
		pfile=NULL;
		return false;
	}

	page.size=size_effective;
	page.pnt_mem=new char[page.size];
	if(page.pnt_mem==NULL){
		//TODO: fare errore. impossibile accedere alla memoria centrale
		fclose(pfile);
		pfile=NULL;
		return false;
	}

	register unsigned int it=0;
	unsigned char buffer;
	while(it<page.size && !feof(pfile)){
		fread(&buffer,sizeof(buffer),1,pfile);
		buffer-=this->key_cryp;
		page.pnt_mem[it]=buffer;
		it++;
	}

	fclose(pfile);
	pfile=NULL;

	return true;
}