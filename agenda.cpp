/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: LOGICA DE PROGRAMACAO I
AGENDA DE CONTATOS
AUTOR: BRUNO CORREIA
DATA: 05/10/2016
VERSÃO: 0.001
*/

#include <iostream>

using namespace std;

class pessoa {
private:
	string nome ;
	string endereco ;
	int telefone;
public:
	string getNome();
	string getEndereco();
	int getTelefone();
	
	void setNome(string);
	void setEndereco(string);
	void setTelefone(int);
};

string pessoa::getNome(){ return nome; }
string pessoa::getEndereco(){ return endereco; }
int pessoa::getTelefone(){ return telefone; }

void pessoa::setNome( string Nome ){ nome = Nome ; }
void pessoa::setEndereco( string Endereco ){ endereco = Endereco ; }
void pessoa::setTelefone( int Telefone ){ telefone = Telefone; }


class contato {
private:
	string email ;
public:
	string getEmail();
	void setEmail(string);
};

string contato::getEmail(){ return email; }
void contato::setEmail( string Email ){ email=Email; }


class pessoaFisica: public pessoa, public contato {
private:
	int cpf;
public:
	int getCPF();
	void setCPF(int);
};

int pessoaFisica::getCPF(){ return cpf; }
void pessoaFisica::setCPF( int CPF ){ cpf=CPF; }


class pessoaJuridica: public pessoa, public contato {
private:
	int cnpj;
public:
	int getCNPJ();
	void setCNPJ(int);
};

int pessoaJuridica::getCNPJ(){ return cnpj; }
void pessoaJuridica::setCNPJ( int CNPJ ){ cnpj=CNPJ; }


int main()
{

	string Nome, Endereco, Email ;
	int CPF, CNPJ, Telefone ;

	pessoaFisica z;

/*	z.setNome("Bruno Correia"),
	z.setEndereco("Rua Iaia Paiva"),
	z.setTelefone(839),
	z.setCPF(123456);
*/

	cout << "Definir Nome: ";
	cin >> Nome;
	z.setNome(Nome);
	
	cout << "Definir Endereco: ";
	cin >> Endereco;
	z.setEndereco(Endereco);

	cout << "Definir Email: ";
	cin >> Email;
	z.setEmail(Email);

	cout << "Definir CPF: ";
	cin >> CPF;
	z.setCPF(CPF);

	cout << "Definir Telefone: ";
	cin >> Telefone;
	z.setTelefone(Telefone);

	cout << endl << "Nome: " << z.getNome() << " Endereço: " << z.getEndereco() << " Telefone: " << z.getTelefone() << " CPF: " << z.getCPF() << " Email: " << z.getEmail() <<endl;

	return 0;

}
