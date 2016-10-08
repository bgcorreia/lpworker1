/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: LOGICA DE PROGRAMACAO I
AGENDA DE CONTATOS
AUTOR: BRUNO CORREIA
DATA: 05/10/2016
VERSÃO: 0.001
*/

#include <iostream> // USAR CIN, COUT E ETC
#include <string> // USAR STRING
#include <iomanip> // USAR SETW E ETC
#include <fstream> // MANIPULAR ARQUIVOS
#include <cstdlib> // DESCOBRIR
#include "colors.h" // FUNCOES PARA FORMATAR TEXTO

using namespace std;

// CLASSE PESSOA
class pessoa
{
private:
	string nome ;
	string endereco ;
	string telefone;
public:
	string getNome();
	string getEndereco();
	string getTelefone();
	
	void setNome(string);
	void setEndereco(string);
	void setTelefone(string);
};

// METODO(S) GET - CLASSE PESSOA
string pessoa::getNome(){ return nome; }
string pessoa::getEndereco(){ return endereco; }
string pessoa::getTelefone(){ return telefone; }
// METODO(S) SET - CLASSE PESSOA
void pessoa::setNome( string Nome ){ nome = Nome ; }
void pessoa::setEndereco( string Endereco ){ endereco = Endereco ; }
void pessoa::setTelefone( string Telefone ){ telefone = Telefone; }


// CLASSE CONTATO
class contato
{
private:
	string email ;
public:
	string getEmail();
	void setEmail(string);
};

// METODO(S) GET - CLASSE CONTATO
string contato::getEmail(){ return email; }
// METODO(S) SET - CLASSE CONTATO
void contato::setEmail( string Email ){ email=Email; }


// CLASSE PESSOA FISICA
class pessoaFisica: public pessoa, public contato
{
private:
	string cpf;
public:
	string getCPF();
	void setCPF(string);
};

// METODO(S) GET - CLASSE PESSOA FISICA
string pessoaFisica::getCPF(){ return cpf; }
// METODO(S) SET - CLASSE PESSOA FISICA
void pessoaFisica::setCPF( string CPF ){ cpf=CPF; }


// CLASSE PESSOA JURIDICA
class pessoaJuridica: public pessoa, public contato
{
private:
	string cnpj;
	string nomeFantasia;
public:
	string getCNPJ();
	string getNomeFantasia();

	void setCNPJ(string);
	void setNomeFantasia(string);
};

// METODO(S) GET - CLASSE PESSOA JURIDICA
string pessoaJuridica::getCNPJ(){ return cnpj; }
string pessoaJuridica::getNomeFantasia(){ return nomeFantasia; }
// METODO(S) SET - CLASSE PESSOA JURIDICA
void pessoaJuridica::setCNPJ( string CNPJ ){ cnpj=CNPJ; }
void pessoaJuridica::setNomeFantasia( string NomeFantasia ){ nomeFantasia=NomeFantasia; }


// CLASSE MENSAGEM
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


// CLASSE PRINCIPAL - MAIN
int main()
{

	string Nome, NomeFantasia, Endereco, Email, Telefone;
	string CPF, CNPJ;
	string stream;
	int i;
	char opcao, tipoPessoa;

	pessoaFisica f;
	pessoaJuridica j;

	// INSTANCIA OBJETO - CONTEUDO SERA ANEXADO QUANDO PERTINENTE
	ofstream escreverAgenda;
	ifstream lerAgenda;

	mensagem m;

	//m.boasvidas();
	cout<<BOLD("[1]")<<" Cadastro"<<endl;
	cout<<BOLD("[2]")<<" Consulta"<<endl;
	cout<<BOLD("[3]")<<" Editar"<<endl;
	cout<<BOLD("[4]")<<" Remover"<<endl;
	cout<<BOLD("[0]")<<" Fechar"<<endl;
	cout<<"Opcao "<<BOLD("[ ]\b\b");
	cin>>opcao;
	cin.ignore(1000, '\n');
	cout<<endl;

	switch(opcao)
	{
		case '1':
		{
		cout<<BOLD("[F]")<<"Pessoa Física"<<endl;
		cout<<BOLD("[J]")<<"Pessoa Jurídica"<<endl;
		cout<<BOLD("[0]")<<"Voltar"<<endl;
		cout<<"Opção "<<BOLD("[ ]\b\b");
		cin>>opcao;
		cin.ignore(1000, '\n');
		

			switch(opcao)
			{
				case 'F':
				{
				system("clear");		
	
				// Exibe o texto abaixo
				cout<<"Opção Cadastro, Pessoa Física. "<<opcao<<endl<<endl;

				cout<<"Por favor, preencha o formulário abaixo."<<endl;
				cout<<BLNK("ATENÇÃO!")<<" Formulários que não seguirem as orientações dos campos, não serão salvos."<<endl<<endl;

				cout<<BOLD("CPF")<<"................."<<BOLD("[")<<".............."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				getline(cin,CPF);
				f.setCPF(CPF);
			
				cout<<BOLD("NOME")<<"................"<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				getline(cin,Nome);
				f.setNome(Nome);				

				cout<<BOLD("ENDEREÇO")<<"............"<<BOLD("[")<<".................................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				getline(cin,Endereco);
				f.setEndereco(Endereco);
			
				cout<<BOLD("TELEFONE")<<"............"<<BOLD("[")<<"..............."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				getline(cin,Telefone);
				f.setTelefone(Telefone);

				cout<<BOLD("EMAIL")<<"..............."<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				getline(cin,Email);
				f.setEmail(Email);

				cout<<endl<<BOLD("Cadastro incluído com sucesso!")<<endl;

				escreverAgenda.open("base.dat");

				if ( !escreverAgenda ){
					cerr<<"Arquivo não pôde ser criado."<<endl;
				} else {
					//escreverAgenda << f.getCPF() << " " << "\"" << f.getNome() << "\"" <<  " " << "\"" << f.getEndereco() << "\"" << " " << "\"" << f.getTelefone() << "\"" << " " << f.getEmail() << endl;
					escreverAgenda << f.getCPF() << ";" << f.getNome() << ";" << f.getEndereco() << ";" << f.getTelefone() << ";" << f.getEmail() << endl;
					escreverAgenda.close();
				};

				}
				break;

				case 'J':
				{
				system("clear");                
        
                	        // Exibe o texto abaixo
	                        cout<<"Opção Cadastro, Pessoa Jurídica. "<<opcao<<endl<<endl;
	
	                        cout<<"Por favor, preencha o formulário abaixo."<<endl;
	                        cout<<BLNK("ATENÇÃO!")<<" Formulários que não seguirem as orientações dos campos, não serão salvos."<<endl<<endl;

				cout<<BOLD("CNPJ")<<"................"<<BOLD("[")<<".................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				getline(cin,CNPJ);
				j.setCNPJ(CNPJ);
                        
				cout<<BOLD("NOME FANTASIA")<<"......."<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        	                getline(cin,NomeFantasia);
				j.setNomeFantasia(NomeFantasia);

				cout<<BOLD("RAZÃO SOCIAL")<<"........."<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	                        getline(cin,Nome);
				j.setNome(Nome);
                        
				cout<<BOLD("ENDEREÇO")<<"............"<<BOLD("[")<<".................................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        	                getline(cin,Endereco);
				j.setEndereco(Endereco);

	                        cout<<BOLD("TELEFONE")<<"............"<<BOLD("[")<<"..............."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        	                getline(cin,Telefone);
				j.setTelefone(Telefone);

                	        cout<<BOLD("EMAIL")<<"..............."<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	                        getline(cin,Email);
				j.setEmail(Email);

        	                cout<<endl<<BOLD("Cadastro incluído com sucesso!")<<endl;

				}
				break;
			}
		}
		break;

		case '2':
		{
			cout<<"Opção Consulta: "<<opcao<<endl;

			lerAgenda.open("base.dat",ios::in);

			if ( !lerAgenda ){
				cerr << "Arquivo não pode ser aberto." << endl;
				exit(1);
			}

			cout << left << setw(18) << "CPF" << setw(30) << "Nome" << setw(30) << "Endereço" << setw(30) << "Telefone" << "Email" << endl;

			//while ( lerAgenda >> CPF >> Nome >> Endereco >> Telefone >> Email ){
			for (i=1 ; i<=5 ; i++){
				getline(lerAgenda,stream,';');

				switch(i)
				{
					case 1:
					cout << left << setw(18) << stream; //CPF
					break;
					case 2:
					cout << setw(30) << stream; //NOME
					break;
					case 3:
					cout << setw(29) << stream; //ENDERECO
					break;
					case 4:
					cout << setw(30) << stream; //Telefone
					break;
					case 5:
					cout << stream << endl; //Email
				}

				//cout << left << setw(10) << f.getCPF() << setw(13) << f.getNome() << f.getTelefone() <<  endl;
				//cout << left << setw(15) << CPF << setw(30) << Nome << Telefone <<  endl;
				//cout << stream << ;
				//getline(lerAgenda,stream,';');
				//cout << CPF << endl;
				//cout << left << setw(18) << CPF << setw(30) << Nome << setw(30) << Endereco << setw(30) << Telefone << Email << endl;
				}
			lerAgenda.close();
		}
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
