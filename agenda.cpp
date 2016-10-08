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
#include <sstream> //stringstream
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
        void logoAgenda()
        {

                cout<<BOLD("                             _       ") <<endl;
                cout<<BOLD("                            | |      ") <<endl;
                cout<<BOLD("   __ _  __ _  ___ _ __   __| | __ _ ") <<endl;
                cout<<BOLD("  / _` |/ _` |/ _ \\ '_ \\ / _` |/ _` |") <<endl;
                cout<<BOLD(" | (_| | (_| |  __/ | | | (_| | (_| |") <<endl;
                cout<<BOLD("  \\__,_|\\__, |\\___|_| |_|\\__,_|\\__,_|") <<endl;
                cout<<BOLD("         __/ |                       ") <<endl;
                cout<<BOLD("        |___/                        ") <<endl<<endl;
        }

	void menuHome()
	{
		cout<<BOLD("HOME")<<"  CADASTRO  CONSULTA  EDITAR  REMOVER"<<endl<<endl;
	}

	void menuCadastro()
	{
		cout<<"HOME  "<<BOLD("CADASTRO")<<"  CONSULTA  EDITAR  REMOVER"<<endl<<endl;

	}

	void menuConsulta()
	{
		cout<<"HOME  CADASTRO  "<<BOLD("CONSULTA")<<"  EDITAR  REMOVER"<<endl<<endl;

	}

	void menuEditar()
	{
		cout<<"HOME  CADASTRO  CONSULTA  "<<BOLD("EDITAR")<<"  REMOVER"<<endl<<endl;

	}
	
	void menuRemover()
	{
		cout<<"HOME  CADASTRO  CONSULTA  EDITAR  "<<BOLD("REMOVER")<<endl<<endl;

	}

};


// CLASSE PRINCIPAL - MAIN
int main()
{

	string Nome, NomeFantasia, Endereco, Email, Telefone;
	string CPF, CNPJ;
	string stream;
	int i, contador;
	char opcao, tipoPessoa, salvar;

	pessoaFisica f;
	pessoaJuridica j;

	// INSTANCIA OBJETO - CONTEUDO SERA ANEXADO QUANDO PERTINENTE
	ofstream escreverAgenda;
	ifstream lerAgenda;

	mensagem exibir;

	// WHILE MENU PRINCIPAL
	while(opcao!='0'){

	system("clear");

	exibir.logoAgenda();
	exibir.menuHome();

	cout<<BOLD("[1]")<<" Cadastro"<<endl;
	cout<<BOLD("[2]")<<" Consulta"<<endl;
	cout<<BOLD("[3]")<<" Editar"<<endl;
	cout<<BOLD("[4]")<<" Remover"<<endl;
	cout<<BOLD("[0]")<<" Fechar"<<endl<<endl;
	cout<<"Opção "<<BOLD("[ ]\b\b");
	cin>>opcao;
	cin.ignore(1000, '\n');
	cout<<endl;

	switch(opcao)
	{
		case '1': // OPÇÃO CADASTRO
		{
		
		// WHILE - SUBMENU CADASTRO		
		while(opcao!='9'){

		system("clear");

		exibir.logoAgenda();
		exibir.menuCadastro();

		cout<<BOLD("[F]")<<" Pessoa Física"<<endl;
		cout<<BOLD("[J]")<<" Pessoa Jurídica"<<endl;
		cout<<BOLD("[9]")<<" Voltar"<<endl<<endl;
		cout<<"Opção "<<BOLD("[ ]\b\b");
		cin>>opcao;
		cin.ignore(1000, '\n');
		
			switch(opcao)
			{
				// CADASTRO PESSOA FISICA
				case 'f':
				case 'F':
				{
					system("clear");

					exibir.logoAgenda();
					exibir.menuCadastro();

					// Exibe o texto abaixo
					cout<<"Opção Cadastro, Pessoa Física."<<endl<<endl;

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

					cout<<endl;
					cout<<"Deseja salvar entrada? "<<"[s/n] :"<<BOLD("[")<<" "<<BOLD("]\b\b");
					cin>>salvar;

					switch(salvar){
					case 'S':
					case 's':					
					{	
						lerAgenda.open("base.dat");
				
						// TESTA SE ARQUIVO EXISTE
						if (lerAgenda.good()){
							cout << "Salvo em Base existente." <<endl;
							escreverAgenda.open("base.dat", ios::app);
						} else {
							cout << "Base não existe, criada."<<endl;
							escreverAgenda.open("base.dat"); //PADRÃO É OUT, CRIA O ARQUIVO
						}

						lerAgenda.close();

						if ( !escreverAgenda ){
							cerr<<"Arquivo não pôde ser criado."<<endl;
						} else {
							escreverAgenda << f.getCPF() << ";" << f.getNome() << ";" << f.getEndereco() << ";" << f.getTelefone() << ";" << f.getEmail() << endl;
							escreverAgenda.close();
							cout<<endl<<BOLD("Cadastro incluído com sucesso!")<<endl;
							system("sleep 1");
						}
					
					} // FIM CASE - SIM
					break;
					
					case 'N':
					case 'n':
					{
						cout<<"Entrada não salva."<<endl<<endl;
						system("sleep 1");
					} // FIM CASE - NAO
					break;

					} // FIM SWITCH - SALVAR

				}
				break;

				// CADASTRO PESSOA JURIDICA
				case 'j':
				case 'J':
				{
					system("clear");                
	        
                		        // Exibe o texto abaixo
	                	        cout<<"Opção Cadastro, Pessoa Jurídica."<<endl<<endl;
	
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

				case '9':
				{
					cout<<"Voltar."<<endl;
				}
				break;

				default:
					cout<<"Opção inválida, tente novamente."<<endl<<endl;
					system("sleep 1");

			} // FIM DO SWITCH - CADASTRO PESSOA FISICA|JURIDICA 

		} // FIM WHILE - SUBMENU - CADASTRO

		} // FIM CASE - OPCAO 1 - CADASTRO
		break;

		case '2': // OPÇÃO CONSULTA
		{
			system("clear");
			
			exibir.logoAgenda();
	                cout<<"HOME  CADASTRO  "<<BOLD("CONSULTA")<<"  EDITAR  REMOVER";
        	        cout<<endl<<endl;
			
			lerAgenda.open("base.dat",ios::in);

			if ( !lerAgenda ){
				cerr << "Arquivo não pode ser aberto." << endl;
				exit(1);
			}

			cout << left << setw(26) << BOLD("CPF") << setw(38) << BOLD("NOME") << setw(58) << BOLD("ENDEREÇO") << setw(38) << BOLD("TELEFONE") << BOLD("EMAIL") << endl;
			//cout << left << setw(18) << "CPF" << setw(30) << "Nome" << setw(50) << "Endereço" << setw(30) << "Telefone" << "Email" << endl;

			string linha;
			
			contador=0;

			while(getline(lerAgenda,linha))
			{
				contador += 1;
				stringstream linestream(linha);

				for (i=1 ; i<=5 ; i++){
					getline(linestream,stream,';');

					switch(i)
					{
						case 1:
							cout << left << setw(18) << stream; // CPF
							break;
						case 2:
							cout << setw(30) << stream; // NOME
							break;
						case 3:
							cout << setw(49) << stream; // ENDERECO
							break;
						case 4:
							cout << setw(30) << stream; // TELEFONE
							break;
						case 5:
							cout << stream << endl; // EMAIL
					}
				}
			}
			lerAgenda.close();
			cout<<contador<<" entrada(s)."<<endl;
			cout<<endl;
			cout<<"Pressione a tecla [ENTER] fechar a exibição.";
			cin.get();
		}
		break;

		case '3': // OPÇÃO EDITAR
			cout<<"Opção Editar: "<<opcao<<endl;
		break;
			
		case '4': // OPÇÃO REMOVER
			cout<<"Opção Remover: "<<opcao<<endl;
		break;
			
		default: // OPÇÃO FECHAR
			cout<<"Opção inválida, tente novamente."<<endl;
			system("sleep 1");
			
		case '0': // OPÇÃO FECHAR
			cout<<"Fechando."<<endl;
		break;
		
			
	} // FIM SWITCH OPCAO - MENU PRINCIPAL

	} // FIM WHILE INICIAL

	return 0;

}
