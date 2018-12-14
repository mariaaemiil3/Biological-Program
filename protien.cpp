#include "Protein.h"



private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein(){
 	 	type=Hormon;}
 	 	Protein(char * p,Protein_Type atype){
 	 	this->p=p;
 	 	type=atype;}
 	 	~Protein();
