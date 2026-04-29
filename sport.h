#ifndef PROIECT_POO2_SPORTURI_H
#define PROIECT_POO2_SPORTURI_H

#include <iostream>
#include <string>
#include <memory>

class Sport {
private:
    std::string numeEchipe;
    double cotaBaza;
    static int nrEvenimenteActive; // variabila statica,numaram global cate obiecte Sport exista

protected:
    std::string pronostic; //accesibil doar in clasele derivate

public:
    Sport(std::string nume_,double cota_, std::string pronostic_);//constructor

    virtual ~Sport();//destructor virtual,esential pentru a elibera corect memoria ob derivate

    //Constructor virtual, pentru a putea copia derivatele;
    virtual std::shared_ptr<Sport> clone() const=0;

    //Interfata non-virtuala,metoda fixa care apeleaza polimorfismul
    void afisareEvenimente() const;

    virtual double calculeazaCastig(double miza) const =0;//calculul depinde de regulile fiecarui sport

    static int getNrEvenimente();

    friend std::ostream& operator<<(std::ostream& os, const Sport& s);

protected:
    //permitem derivatelor sa acceseze cota pentru calcule
    double getCotaBaza() const ;

    std::string getPronostic() const { return pronostic; }

private:
    virtual void afisareSpecifica(std::ostream &os) const =0; //supraincarcare operator
};

#endif //PROIECT_POO2_SPORTURI_H