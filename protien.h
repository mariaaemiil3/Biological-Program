#ifndef PROTIEN_H
#define PROTIEN_H


class Protien
{
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
};

#endif // PROTIEN_H
