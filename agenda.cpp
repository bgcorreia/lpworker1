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

#define FILEPF "pf.db"
#define FILEPJ "pj.db"

using namespace std;

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

	void menuEdita()
	{
		cout<<"HOME  CADASTRO  CONSULTA  "<<BOLD("EDITAR")<<"  REMOVER"<<endl<<endl;

	}
	
	void menuRemove()
	{
		cout<<"HOME  CADASTRO  CONSULTA  EDITAR  "<<BOLD("REMOVER")<<endl<<endl;

	}

};


// CLASSE PESSOA
class pessoa
{
private:
	string nome;
	string endereco;
	string telefone;
	string email;
public:
	//pessoa(const int&); // CONSTRUTOR
	//~pessoa(); // DESTRUTOR

	string getNome();
	string getEndereco();
	string getTelefone();
	string getEmail();
	
	void setNome(string);
	void setEndereco(string);
	void setTelefone(string);
	void setEmail(string);
};

/*
pessoa::pessoa(const pessoa&){
	cout<<endl<<"Construtor"<<endl;
}

pessoa::~pessoa(){
	cout<<endl<<"Destrutor"<<endl;
}
*/

// METODO(S) GET - CLASSE PESSOA
string pessoa::getNome(){ return nome; }
string pessoa::getEndereco(){ return endereco; }
string pessoa::getTelefone(){ return telefone; }
string pessoa::getEmail(){ return email; }

// METODO(S) SET - CLASSE PESSOA
void pessoa::setNome( string Nome ){ nome = Nome ; }
void pessoa::setEndereco( string Endereco ){ endereco = Endereco ; }
void pessoa::setTelefone( string Telefone ){ telefone = Telefone; }
void pessoa::setEmail( string Email ){ email=Email; }


// CLASSE PESSOA FISICA
class pessoaFisica: public pessoa
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
class pessoaJuridica: public pessoa
{
private:
	string cnpj;
public:
	string getCNPJ();
	void setCNPJ(string);
};

// METODO(S) GET - CLASSE PESSOA JURIDICA
string pessoaJuridica::getCNPJ(){ return cnpj; }
// METODO(S) SET - CLASSE PESSOA JURIDICA
void pessoaJuridica::setCNPJ( string CNPJ ){ cnpj=CNPJ; }


// CLASSE CONTATO
class contato: public pessoaFisica, public pessoaJuridica, private mensagem
{
private:
	char tipo;
	int id;
public:

	char getTipo();
	int getID();
	int verificaID(char);

	void cadastra(char, contato*);
	int consulta(char, contato*, int);
	void edita(int, char, contato*);
	void remove(int, char, mensagem*, contato*, int);

	void setTipo(char);
	void setID(int);
	
};

// METODO(S) GET - CLASSE CONTATO
char contato::getTipo(){ return tipo; }
int contato::getID(){ return id; }

int contato::verificaID(char tipo){

	string stream;
	int ID, i, maior=0, contador=0, numCampos=7;

	ifstream lerAgenda;

	if ( tipo == 'F' ){

		lerAgenda.open(FILEPF,ios::in);

		if ( !lerAgenda ){
			cerr << "Arquivo não pode ser aberto." << endl;
			cout << "Prosseguindo, diretorio pode nao ter permissao ou arquivo ainda nao criado." <<endl<<endl;
		}

		string linha;

		while(getline(lerAgenda,linha))
		{
			contador += 1;
			stringstream linestream(linha);

			for (i=1 ; i<=numCampos ; i++){
				getline(linestream,stream,';');

				switch(i)
				{
				        case 2:
				                ID=atoi(stream.c_str());
						break;
				}

			}


			//cout << "ANTES - ID: " << ID << " | Maior: " << maior << endl; 		
	
			if ( ID > maior ){
		        	maior = ID;
			}

			//cout << "DEPOIS - ID: " << ID << " | Maior: " << maior << endl;

		}

		// RETORNA PRÓXIMO ID
		return maior + 1 ;
	} 
	
	if ( tipo == 'J' ){

		lerAgenda.open(FILEPJ,ios::in);

		if ( !lerAgenda ){
			cerr << "Arquivo não pode ser aberto." << endl;
			cout << "Prosseguindo, diretorio pode nao ter permissao ou arquivo ainda nao criado." <<endl<<endl;
		}

		string linha;

		while(getline(lerAgenda,linha))
		{
			contador += 1;
			stringstream linestream(linha);

			for (i=1 ; i<=numCampos ; i++){
				getline(linestream,stream,';');

				switch(i)
				{
				        case 2:
				                ID=atoi(stream.c_str());
						break;
				}

			}


			//cout << "ANTES - ID: " << ID << " | Maior: " << maior << endl; 		
	
			if ( ID > maior ){
		        	maior = ID;
			}

			//cout << "DEPOIS - ID: " << ID << " | Maior: " << maior << endl;

		}

		// RETORNA PRÓXIMO ID
		return maior + 1 ;
	}

}

void contato::cadastra(char Tipo, contato *p){

	string Nome, Endereco, Email, Telefone;
	string CPF, CNPJ;
	char salvar;

	// INSTANCIA OBJETO - CONTEUDO SERA ANEXADO QUANDO PERTINENTE
	ofstream escreverAgenda;
	ifstream lerAgenda;

	if (Tipo == 'F'){
		/*
		CHAMAR FUNÇÃO QUE COLOCA ID CORRETO
		CHECAR IDs CADASTRADOS E RETORNAR O CORRETO
		*/

		p->setID(p->verificaID(Tipo));

		// Exibe o texto abaixo
		cout<<"Opção Cadastro, Pessoa Física."<<endl<<endl;

		cout<<"Por favor, preencha o formulário abaixo."<<endl;
		cout<<BLNK("ATENÇÃO!")<<" Formulários que não seguirem as orientações dos campos, não serão salvos."<<endl<<endl;

		cout<<BOLD("ID")<<".................."<<BOLD("[")<< p->getID() <<BOLD("]")<<endl;

		cout<<BOLD("CPF")<<"................."<<BOLD("[")<<".............."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,CPF);
		p->setCPF(CPF);

		cout<<BOLD("NOME")<<"................"<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Nome);
		p->pessoaFisica::setNome(Nome);

		cout<<BOLD("ENDEREÇO")<<"............"<<BOLD("[")<<".................................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Endereco);
		p->pessoaFisica::setEndereco(Endereco);

		cout<<BOLD("TELEFONE")<<"............"<<BOLD("[")<<"..............."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Telefone);
		p->pessoaFisica::setTelefone(Telefone);

		cout<<BOLD("EMAIL")<<"..............."<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Email);
		p->pessoaFisica::setEmail(Email);

		cout<<endl;
		cout<<"Deseja salvar entrada? "<<"[s/n] :"<<BOLD("[")<<" "<<BOLD("]\b\b");
		cin>>salvar;

		switch(salvar){
		case 'S':
		case 's':					
		{	
			lerAgenda.open(FILEPF);

			// TESTA SE ARQUIVO EXISTE
			if (lerAgenda.good()){
				cout << "Salvo em Base existente." <<endl;
				escreverAgenda.open(FILEPF, ios::app);
			} else {
				cout << "Base não existe, criada."<<endl;
				escreverAgenda.open(FILEPF); //PADRÃO É OUT, CRIA O ARQUIVO
			}

			lerAgenda.close();

			if ( !escreverAgenda ){
				cerr<<"Arquivo não pôde ser criado."<<endl;
			} else {
				escreverAgenda << p->getTipo() << ";" << p->getID()  << ";" << p->pessoaFisica::getNome() << ";" << p->getCPF() << ";" << p->pessoaFisica::getEndereco() << ";" << p->pessoaFisica::getTelefone() << ";" << p->pessoaFisica::getEmail() << endl;
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
	
	if (Tipo == 'J'){

		/*
		CHAMAR FUNÇÃO QUE COLOCA ID CORRETO
		CHECAR IDs CADASTRADOS E RETORNAR O CORRETO
		*/

		p->setID(p->verificaID(Tipo));

		// Exibe o texto abaixo
		cout<<"Opção Cadastro, Pessoa Jurídica."<<endl<<endl;

		cout<<"Por favor, preencha o formulário abaixo."<<endl;
		cout<<BLNK("ATENÇÃO!")<<" Formulários que não seguirem as orientações dos campos, não serão salvos."<<endl<<endl;

		cout<<BOLD("ID")<<"..................."<<BOLD("[")<< p->getID() <<BOLD("]")<<endl;

		cout<<BOLD("CNPJ")<<"................."<<BOLD("[")<<".................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,CNPJ);
		p->setCNPJ(CNPJ);

		cout<<BOLD("NOME")<<"................."<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Nome);
		p->pessoaJuridica::setNome(Nome);				

		cout<<BOLD("ENDEREÇO")<<"............."<<BOLD("[")<<".................................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Endereco);
		p->pessoaJuridica::setEndereco(Endereco);

		cout<<BOLD("TELEFONE")<<"............."<<BOLD("[")<<"..............."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Telefone);
		p->pessoaJuridica::setTelefone(Telefone);

		cout<<BOLD("EMAIL")<<"................"<<BOLD("[")<<"............................."<<BOLD("]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin,Email);
		p->pessoaJuridica::setEmail(Email);

		cout<<endl;
		cout<<"Deseja salvar entrada? "<<"[s/n] :"<<BOLD("[")<<" "<<BOLD("]\b\b");
		cin>>salvar;

		switch(salvar){
		case 'S':
		case 's':					
		{	
			lerAgenda.open(FILEPJ);

			// TESTA SE ARQUIVO EXISTE
			if (lerAgenda.good()){
				cout << "Salvo em Base existente." <<endl;
				escreverAgenda.open(FILEPJ, ios::app);
			} else {
				cout << "Base não existe, criada."<<endl;
				escreverAgenda.open(FILEPJ); //PADRÃO É OUT, CRIA O ARQUIVO
			}

			lerAgenda.close();

			if ( !escreverAgenda ){
				cerr<<"Arquivo não pôde ser criado."<<endl;
			} else {
				escreverAgenda << p->getTipo() << ";" << p->getID()  << ";" << p->pessoaJuridica::getNome() << ";" << p->getCNPJ() << ";" << p->pessoaJuridica::getEndereco() << ";" << p->pessoaJuridica::getTelefone() << ";" << p->pessoaJuridica::getEmail() << endl;
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

}


int contato::consulta(char Tipo, contato *p, int pressioneTecla = 1){

	string stream;
	int  i, contador;
	int numCampos=7 ;

	ofstream escreverAgenda;
	ifstream lerAgenda;

	if ( Tipo == 'F'){

		lerAgenda.open(FILEPF,ios::in);

		if ( !lerAgenda ){
			cerr << "Arquivo não existe, sem entradas para exibir." << endl;
		}

		cout << left << setw(12) << BOLD("ID") << setw(38) << BOLD("NOME") << setw(26) << BOLD("CPF") << setw(58) << BOLD("ENDEREÇO") << setw(38) << BOLD("TELEFONE") << BOLD("EMAIL") << endl;
		//cout << left << setw(18) << "CPF" << setw(30) << "Nome" << setw(50) << "Endereço" << setw(30) << "Telefone" << "Email" << endl;

		string linha;

		contador=0;

		while(getline(lerAgenda,linha))
		{
			contador += 1;
			stringstream linestream(linha);

			for (i=1 ; i<=numCampos ; i++){
				getline(linestream,stream,';');

				switch(i)
				{
					case 1:
						p->setTipo(stream[0]);
						break;
					case 2:
						// CONVERSÃO STRING P/ INTEIRO
						//id = atoi(stream.c_str());
						p->setID(atoi(stream.c_str()));
						//id = stream ;  
						//cout << left << setw(1) << stream; //ID
						break;
					case 3:
						p->pessoaFisica::setNome(stream);
						//cpf = stream ;
						//cout <<  setw(18) << stream; // CPF
						break;
					case 4:
						p->pessoaFisica::setCPF(stream);
						//nome = stream ;
						//cout << setw(30) << stream; // NOME
						break;
					case 5:
						p->pessoaFisica::setEndereco(stream);
						//endereco = stream ;
						//cout << setw(49) << stream; // ENDERECO
						break;
					case 6:
						p->pessoaFisica::setTelefone(stream);
						//telefone = stream ;
						//cout << setw(30) << stream; // TELEFONE
						break;
					case 7:
						p->pessoaFisica::setEmail(stream);
						//email = stream ;
						//cout << stream << endl; // EMAIL
				}
			}
		
		// PRINTA NA TELA LINHA A LINHA
		cout << left << setw(4) << p->getID() << setw(30) << p->pessoaFisica::getNome() << setw(18) << p->getCPF() << setw(49) << p->pessoaFisica::getEndereco() << setw(30) << p->pessoaFisica::getTelefone() << p->pessoaFisica::getEmail() << endl  ;
		}
		lerAgenda.close();

		//cout << left << setw(4) << p->getID() << setw(30) << p->getNome() << setw(18) << p->getCPF() << setw(49) << p->getEndereco() << setw(30) << p->getTelefone() << p->getEmail() << endl  ;

		cout<<endl<<contador<<" entrada(s)."<<endl;
		cout<<endl;

		if (pressioneTecla == 1){
			cout<<"Pressione a tecla [ENTER] fechar a exibição.";
			cin.get();
		}

		return contador;

	}

	if ( Tipo == 'J'){

		lerAgenda.open(FILEPJ,ios::in);

		if ( !lerAgenda ){
			cerr << "Arquivo não existe, sem entradas para exibir." << endl;
		}

		cout << left << setw(12) << BOLD("ID") << setw(38) << BOLD("NOME") << setw(27) << BOLD("CNPJ") << setw(58) << BOLD("ENDEREÇO") << setw(38) << BOLD("TELEFONE") << BOLD("EMAIL") << endl;

		string linha;

		contador=0;

		while(getline(lerAgenda,linha))
		{
			contador += 1;
			stringstream linestream(linha);

			for (i=1 ; i<=numCampos ; i++){
				getline(linestream,stream,';');

				switch(i)
				{
					case 1:
						p->setTipo(stream[0]);
						break;
					case 2:
						// CONVERSÃO STRING P/ INTEIRO
						//id = atoi(stream.c_str());
						p->setID(atoi(stream.c_str()));
						//id = stream ;  
						//cout << left << setw(1) << stream; //ID
						break;
					case 3:
						p->pessoaJuridica::setNome(stream);
						//cpf = stream ;
						//cout <<  setw(18) << stream; // CPF
						break;
					case 4:
						p->pessoaJuridica::setCNPJ(stream);
						//nome = stream ;
						//cout << setw(30) << stream; // NOME
						break;
					case 5:
						p->pessoaJuridica::setEndereco(stream);
						//endereco = stream ;
						//cout << setw(49) << stream; // ENDERECO
						break;
					case 6:
						p->pessoaJuridica::setTelefone(stream);
						//telefone = stream ;
						//cout << setw(30) << stream; // TELEFONE
						break;
					case 7:
						p->pessoaJuridica::setEmail(stream);
						//email = stream ;
						//cout << stream << endl; // EMAIL
				}
			}
		
		// PRINTA NA TELA LINHA A LINHA
		cout << left << setw(4) << p->getID() << setw(30) << p->pessoaJuridica::getNome() << setw(19) << p->getCNPJ() << setw(49) << p->pessoaJuridica::getEndereco() << setw(30) << p->pessoaJuridica::getTelefone() << p->pessoaJuridica::getEmail() << endl  ;
		}
		lerAgenda.close();

		cout<<endl<<contador<<" entrada(s)."<<endl;
		cout<<endl;

		if (pressioneTecla == 1){
			cout<<"Pressione a tecla [ENTER] fechar a exibição.";
			cin.get();
		}

		return contador;

	}


}


void contato::edita(int ID, char Tipo, contato *p){
	//MONTAR MÉTODO PARA EDITAR
}


// MÉTODO REMOVER
void contato::remove(int removerID, char Tipo, mensagem *exibir, contato *p, int pressioneTecla = 1){

	string stream;
	int  i, contador, encontrado=0, numCampos=7;

	ofstream escreverAgenda;
	ifstream lerAgenda;

	if ( Tipo == 'F'){

		lerAgenda.open(FILEPF,ios::in);
		escreverAgenda.open("tempf");

		if ( !lerAgenda ){
			cerr << "Arquivo não existe, sem entradas para editar." << endl;
		}

		string linha;

		contador=0;

		while(getline(lerAgenda,linha))
		{
			contador += 1;
			stringstream linestream(linha);

			for (i=1 ; i<=numCampos ; i++){
				getline(linestream,stream,';');

				switch(i)
				{
					case 1:
						p->setTipo(stream[0]);
						break;
					case 2:
						p->setID(atoi(stream.c_str()));
						break;
					case 3:
						p->pessoaFisica::setNome(stream);
						break;
					case 4:
						p->setCPF(stream);
						break;
					case 5:
						p->pessoaFisica::setEndereco(stream);
						break;
					case 6:
						p->pessoaFisica::setTelefone(stream);
						break;
					case 7:
						p->pessoaFisica::setEmail(stream);
						break;
				} // FIM SWITCH

			} // FIM FOR
		
			// ESCREVER NO ARQUIVO

			if ( removerID == p->getID() ){
				encontrado = 1;
			} else {

				if ( !escreverAgenda ){
					cerr<<"Arquivo não pôde ser criado."<<endl;
				} else {
					escreverAgenda << p->getTipo() << ";" << p->getID()  << ";" << p->pessoaFisica::getNome() << ";" << p->getCPF() << ";" << p->pessoaFisica::getEndereco() << ";" << p->pessoaFisica::getTelefone() << ";" << p->pessoaFisica::getEmail() << endl;
				}

			} // FIM IF QUE ESCREVE TUDO MENOS O QUE O ID COINCIDE


		} // FIM WHILE

		lerAgenda.close();
		escreverAgenda.close();

		system("mv tempf "FILEPF);

		if ( encontrado == 1 ){
			
			system("clear");

			exibir->logoAgenda();
			exibir->menuRemove();			

			cout<<BOLD("Código ID encontrado, cadastro removido com sucesso!")<<endl<<endl;

			p->consulta(p->getTipo(),p);

		} else {
			cout<<"O código de ID digitado, não foi encontrado."<<endl<<endl;
			cout<<"Pressione a tecla [ENTER] fechar a exibição.";
			cin.get();
		}

	} 

	if ( Tipo == 'J'){

		lerAgenda.open(FILEPJ,ios::in);
		escreverAgenda.open("tempj");

		if ( !lerAgenda ){
			cerr << "Arquivo não existe, sem entradas para editar." << endl;
		}

		string linha;

		contador=0;

		while(getline(lerAgenda,linha))
		{
			contador += 1;
			stringstream linestream(linha);

			for (i=1 ; i<=numCampos ; i++){
				getline(linestream,stream,';');

				switch(i)
				{
					case 1:
						p->setTipo(stream[0]);
						break;
					case 2:
						p->setID(atoi(stream.c_str()));
						break;
					case 3:
						p->pessoaJuridica::setNome(stream);
						break;
					case 4:
						p->setCNPJ(stream);
						break;
					case 5:
						p->pessoaJuridica::setEndereco(stream);
						break;
					case 6:
						p->pessoaJuridica::setTelefone(stream);
						break;
					case 7:
						p->pessoaJuridica::setEmail(stream);
						break;
				} // FIM SWITCH

			} // FIM FOR
		
			// ESCREVER NO ARQUIVO

			if ( removerID == p->getID() ){
				encontrado = 1;
			} else {

				if ( !escreverAgenda ){
					cerr<<"Arquivo não pôde ser criado."<<endl;
				} else {
					escreverAgenda << p->getTipo() << ";" << p->getID()  << ";" << p->pessoaJuridica::getNome() << ";" << p->getCNPJ() << ";" << p->pessoaJuridica::getEndereco() << ";" << p->pessoaJuridica::getTelefone() << ";" << p->pessoaJuridica::getEmail() << endl;
				}

			} // FIM IF QUE ESCREVE TUDO MENOS O QUE O ID COINCIDE


		} // FIM WHILE

		lerAgenda.close();
		escreverAgenda.close();

		system("mv tempj "FILEPJ);

		if ( encontrado == 1 ){
			
			system("clear");

			exibir->logoAgenda();
			exibir->menuRemove();			

			cout<<BOLD("Código ID encontrado, cadastro removido com sucesso!")<<endl<<endl;

			p->consulta(p->getTipo(),p);

		} else {
			cout<<"O código de ID digitado, não foi encontrado."<<endl<<endl;
			cout<<"Pressione a tecla [ENTER] fechar a exibição.";
			cin.get();
		}

	}
	
}


// METODO(S) SET - CLASSE CONTATO
void contato::setTipo(char Tipo){ tipo=Tipo; }
void contato::setID(int ID){ id=ID; }


// CLASSE PRINCIPAL - MAIN
int main()
{

	int ID;
	char opcao;

	// CRIA INSTANCIA	
	contato p;

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

		/*

		OPÇÃO 1 - CADASTRAR

		*/

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

						//CADASTRO
						p.setTipo('F');
						p.cadastra(p.getTipo(),&p);

					}
					break;

					// CADASTRO PESSOA JURIDICA
					case 'j':
					case 'J':
					{
						system("clear");

						exibir.logoAgenda();
						exibir.menuCadastro();

						//CADASTRO
						p.setTipo('J');
						p.cadastra(p.getTipo(),&p);					
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

		/*

		OPÇÃO 2 - CONSULTAR

		*/

		case '2': // OPÇÃO CONSULTA
		{

			// WHILE - SUBMENU CADASTRO
			while(opcao!='9'){

			system("clear");

			exibir.logoAgenda();
			exibir.menuConsulta();

			cout<<BOLD("[F]")<<" Pessoa Física"<<endl;
			cout<<BOLD("[J]")<<" Pessoa Jurídica"<<endl;
			cout<<BOLD("[9]")<<" Voltar"<<endl<<endl;
			cout<<"Opção "<<BOLD("[ ]\b\b");
			cin>>opcao;
			cin.ignore(1000, '\n');
		
				switch(opcao)
				{
					// CONSULTA PESSOA FISICA
					case 'f':
					case 'F':
					{
						system("clear");

						exibir.logoAgenda();
						exibir.menuConsulta();

						//CONSULTA
						p.setTipo('F');
						p.consulta(p.getTipo(),&p);

					}
					break;

					// CONSULTA PESSOA JURIDICA
					case 'j':
					case 'J':
					{
						system("clear");

						exibir.logoAgenda();
						exibir.menuConsulta();

						//CONSULTA
						p.setTipo('J');
						p.consulta(p.getTipo(),&p);					
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

				} // FIM DO SWITCH - CONSULTA PESSOA FISICA|JURIDICA 

			} // FIM WHILE - SUBMENU - CONSULTA

		} // FIM CASE - OPCAO 2 - CONSULTA
		break;

		/*

		OPÇÃO 3 - EDITAR
	
		*/

		case '3': // OPÇÃO EDITAR
			
			cout<<"Opção Editar: "<<opcao<<endl;

			// WHILE - SUBMENU EDITAR
			while(opcao!='9'){

			system("clear");

			exibir.logoAgenda();
			exibir.menuEdita();

			cout<<BOLD("[F]")<<" Pessoa Física"<<endl;
			cout<<BOLD("[J]")<<" Pessoa Jurídica"<<endl;
			cout<<BOLD("[9]")<<" Voltar"<<endl<<endl;
			cout<<"Opção "<<BOLD("[ ]\b\b");
			cin>>opcao;
			cin.ignore(1000, '\n');
		
				switch(opcao)
				{
					// EDITA PESSOA FISICA
					case 'f':
					case 'F':
					{
						system("clear");

						exibir.logoAgenda();
						exibir.menuEdita();

						//REMOVE
						p.setTipo('F');
						//p.consulta(p.getTipo(),&p,0);

						// SE EXISTIR ALGUM REGISTRO
						if ( p.consulta(p.getTipo(),&p,0) ){
							
							cout<<endl;
						
							cout<<"Entre com o ID do registro que deseja editar "<<BOLD("[ ]\b\b");
							cin>>ID;
							cin.ignore(1000, '\n');

						} else {
							cout<<endl;
							cout<<"Não existem registros para serem editados.";
							cout<<endl;
							cout<<"Pressione a tecla [ENTER] fechar a exibição.";
							cin.get();
						}

						// CHAMAR FUNÇÃO QUE EDITA PASSANDO ARGUMENTO DO ID E PONTEIRO PRA OBJETO DA CLASSE
						/*

		
						CHAMAR AQUI FUNÇÃO QUE EDITA

						*/

					}
					break;

					// EDITA PESSOA JURIDICA
					case 'j':
					case 'J':
					{
						system("clear");

						exibir.logoAgenda();
						exibir.menuEdita();

						//CADASTRO
						p.setTipo('J');

						if ( p.consulta(p.getTipo(),&p,0) ){
	
							cout<<endl;

							cout<<"Entre com o ID do registro que deseja editar "<<BOLD("[ ]\b\b");
							cin>>ID;
							cin.ignore(1000, '\n');

						} else {
							cout<<endl;
							cout<<"Não existem registros para serem editados.";
							cout<<endl;
							cout<<"Pressione a tecla [ENTER] fechar a exibição.";
							cin.get();
						}

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

				} // FIM DO SWITCH - EDITAR PESSOA FISICA|JURIDICA 

			} // FIM WHILE - SUBMENU - EDITAR

	

		break;

		/*

		OPÇÃO 4 - REMOVER

		*/
			
		case '4':
			cout<<"Opção Remover: "<<opcao<<endl;
		
			// WHILE - SUBMENU REMOVER
			while(opcao!='9'){

			system("clear");

			exibir.logoAgenda();
			exibir.menuRemove();

			cout<<BOLD("[F]")<<" Pessoa Física"<<endl;
			cout<<BOLD("[J]")<<" Pessoa Jurídica"<<endl;
			cout<<BOLD("[9]")<<" Voltar"<<endl<<endl;
			cout<<"Opção "<<BOLD("[ ]\b\b");
			cin>>opcao;
			cin.ignore(1000, '\n');
		
				switch(opcao)
				{
					// REMOVE PESSOA FISICA
					case 'f':
					case 'F':
					{
						system("clear");

						exibir.logoAgenda();
						exibir.menuRemove();

						// DEFINE TIPO
						p.setTipo('F');
						/* 
						ULTIMO PARAMETRO DA CHAMADA É PARA PRESSIONAR TECLA OU NÃO
						0 = DESABILITADO
						*/
						if ( p.consulta(p.getTipo(),&p,0) ){
	
							cout<<endl;

							cout<<"Entre com o ID do registro que deseja remover "<<BOLD("[ ]\b\b");
							cin>>ID;
							cin.ignore(1000, '\n');

							// REMOVE ID
							p.remove(ID,p.getTipo(),&exibir,&p);

						} else {
							cout<<"Não existem registros para serem removidos.";
							cout<<endl<<endl;
							cout<<"Pressione a tecla [ENTER] fechar a exibição.";
							cin.get();
						}

					}
					break;

					// REMOVE PESSOA JURIDICA
					case 'j':
					case 'J':
					{
						system("clear");

						exibir.logoAgenda();
						exibir.menuRemove();

						// DEFINE TIPO
						p.setTipo('J');
						
						/* 
						ULTIMO PARAMETRO DA CHAMADA É PARA PRESSIONAR TECLA OU NÃO
						0 = DESABILITADO
						*/
						if ( p.consulta(p.getTipo(),&p,0) ){
	
							cout<<endl;

							cout<<"Entre com o ID do registro que deseja remover "<<BOLD("[ ]\b\b");
							cin>>ID;
							cin.ignore(1000, '\n');

							// REMOVE ID
							p.remove(ID,p.getTipo(),&exibir,&p);

						} else {
							cout<<"Não existem registros para serem removidos.";
							cout<<endl<<endl;
							cout<<"Pressione a tecla [ENTER] fechar a exibição.";
							cin.get();
						}
						
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

				} // FIM DO SWITCH - REMOVE PESSOA FISICA|JURIDICA 

			} // FIM WHILE - SUBMENU - REMOVE


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
