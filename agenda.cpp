/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: LOGICA DE PROGRAMACAO I
AGENDA DE CONTATOS
AUTOR: BRUNO CORREIA
DATA: 05/10/2016
VERSÃO: 0.001
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "colors.h"

using namespace std;

class pessoa
{
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


class contato
{
private:
	string email ;
public:
	string getEmail();
	void setEmail(string);
};

string contato::getEmail(){ return email; }
void contato::setEmail( string Email ){ email=Email; }


class pessoaFisica: public pessoa, public contato
{
private:
	int cpf;
public:
	int getCPF();
	void setCPF(int);
};

int pessoaFisica::getCPF(){ return cpf; }
void pessoaFisica::setCPF( int CPF ){ cpf=CPF; }


class pessoaJuridica: public pessoa, public contato
{
private:
	int cnpj;
public:
	int getCNPJ();
	void setCNPJ(int);
};

int pessoaJuridica::getCNPJ(){ return cnpj; }
void pessoaJuridica::setCNPJ( int CNPJ ){ cnpj=CNPJ; }


class mensagem
{
public:
	void boasvidas()
	{
		cout << BOLD(" .d8888b.                 888           888                   ") <<endl; 
		cout << BOLD("d88P  Y88b                888           888                   ") <<endl;
		cout << BOLD("888    888                888           888                   ") <<endl;
		cout << BOLD("888        .d88b. 88888b. 888888 8888b. 888888 .d88b. .d8888b ") <<endl;
		cout << BOLD("888       d88\"\"88b888 \"88b888       \"88b888   d88\"\"88b88K     ") <<endl;
		cout << BOLD("888    888888  888888  888888   .d888888888   888  888\"Y8888b.") <<endl;
		cout << BOLD("Y88b  d88PY88..88P888  888Y88b. 888  888Y88b. Y88..88P     X88") <<endl;
		cout << BOLD(" \"Y8888P\"  \"Y88P\" 888  888 \"Y888\"Y888888 \"Y888 \"Y88P\"  88888P\'") <<endl<<endl;
	}

	void opcoes()
	{
		cout<<"[1] Cadastro\n[2] Consulta\n[3] Editar\n[4] Remover\n[0] Fechar\nOpcao [ ]\b\b";
	}

	

};

int main()
{

	string Nome, Endereco, Email, Telefone;
	int CPF, CNPJ;
	char opcao;

	pessoaFisica z;

	mensagem m;

	//m.boasvidas();
	cout<<"[1] Cadastro\n[2] Consulta\n[3] Editar\n[4] Remover\n[0] Fechar\nOpcao [ ]\b\b";
	cin>>opcao;
	cin.ignore(1000, '\n');

	switch(opcao)
	{
		case '1':
		{
			
			system("clear");		
	
			// Exibe o texto abaixo
			cout<<"Opção Cadastro: "<<opcao<<endl<<endl;

			cout<<"Por favor, preencha o formulário abaixo."<<endl;
			cout<<BLNK("ATENÇÃO!")<<" Formulários que não seguirem as orientações dos campos, não serão salvos."<<endl<<endl;

			cout<<"NOME................[                             ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			//cout<<"Nome: ";
			getline (cin,Nome);
			//cin>>Nome;
			//cout<<endl;

			cout<<"ENDEREÇO............[                             ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			getline(cin,Endereco);
			
//			cout<<"TELEFONE.................. [(  )         ]\b\b\b\b\b\b\b\b\b\b\b\b\b";
//			getline(cin,Telefone);
			//cout<<endl;

/*
			cout<<"EMAIL..................... [                             ]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			cin>>Email;
			cout<<endl;
*/
		break;
		}
			
		case '2':
			cout<<"Opção Consulta: "<<opcao<<endl;
		break;

		case '3':
			cout<<"Opção Editar: "<<opcao<<endl;
		break;
			
		case '4':
			cout<<"Opção Remover: "<<opcao<<endl;
		break;
			
		case '0':
			cout<<"Opção Fechar: "<<opcao<<endl;
		break;
			
	}

	return 0;

}
