#include <eosio/eosio.hpp>

using namespace eosio;

class [[eosio::contract("diploma")]] diploma : public eosio::contract {

public:

  using contract::contract;

  diploma(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds) {}

  [[eosio::action]]
  void upsert(name user, std::string id, std::string signature, std::string nacionalidade, std::string naturalidade, std::string cpf, std::string rg, std::string data_nascimento, std::string nome,
  std::string codigo_mec, std::string cnpj, std::string endereco, std::string credenciamento, std::string mantenedora, std::string nome_curso, std::string codigo_curso_mec, std::string nome_habilitacao,
  std::string modalidade, std::string titulo_conferido, std::string grau_conferido, std::string filiacao, std::string historico_escolar, std::string carga_horaria_curso, std::string ingresso_curso,
  std::string data, std::string forma_acesso, std::string data_conclusao) {
    require_auth( name("master") );
    is_account( name(user) );
    diploma_index diploma( get_self(), get_first_receiver().value );
    auto iterator = diploma.find(user.value);
    if( iterator == diploma.end() )
    {
      diploma.emplace(_self, [&]( auto& row ) {
       row.key = user;
       row.id = id;
       row.signature = signature;
       row.nacionalidade = nacionalidade;
       row.naturalidade = naturalidade;
       row.cpf = cpf;
       row.rg = rg;
       row.data_nascimento = data_nascimento;
       row.nome = nome;
       row.codigo_mec = codigo_mec;
       row.cnpj = cnpj;
       row.endereco = endereco;
       row.credenciamento = credenciamento;
       row.mantenedora = mantenedora;
       row.nome_curso = nome_curso;
       row.codigo_curso_mec = codigo_curso_mec;
       row.nome_habilitacao = nome_habilitacao;
       row.modalidade = modalidade;
       row.titulo_conferido = titulo_conferido;
       row.grau_conferido = grau_conferido;
       row.filiacao = filiacao;
       row.historico_escolar = historico_escolar;
       row.carga_horaria_curso = carga_horaria_curso;
       row.ingresso_curso = ingresso_curso;
       row.data = data;
       row.forma_acesso = forma_acesso;
       row.data_conclusao = data_conclusao;
      });
    }
    else {
      diploma.modify(iterator, _self, [&]( auto& row ) {
        row.key = user;
        row.id = id;
        row.signature = signature;
        row.nacionalidade = nacionalidade;
        row.naturalidade = naturalidade;
        row.cpf = cpf;
        row.rg = rg;
        row.data_nascimento = data_nascimento;
        row.nome = nome;
        row.codigo_mec = codigo_mec;
        row.cnpj = cnpj;
        row.endereco = endereco;
        row.credenciamento = credenciamento;
        row.mantenedora = mantenedora;
        row.nome_curso = nome_curso;
        row.codigo_curso_mec = codigo_curso_mec;
        row.nome_habilitacao = nome_habilitacao;
        row.modalidade = modalidade;
        row.titulo_conferido = titulo_conferido;
        row.grau_conferido = grau_conferido;
        row.filiacao = filiacao;
        row.historico_escolar = historico_escolar;
        row.carga_horaria_curso = carga_horaria_curso;
        row.ingresso_curso = ingresso_curso;
        row.data = data;
        row.forma_acesso = forma_acesso;
        row.data_conclusao = data_conclusao;
      });
    }
  }

  [[eosio::action]]
  void erase(name user) {
    require_auth( name("master") );

    diploma_index diploma( get_self(), get_first_receiver().value);

    auto iterator = diploma.find(user.value);
    check(iterator != diploma.end(), "Não existem dados");
    diploma.erase(iterator);
  }

private:
  struct [[eosio::table]] tdiploma {
    name key;
    //infDiploma
    std::string id;
    std::string signature;
    //TDadosDiplomado
    std::string nacionalidade;
    std::string naturalidade;
    std::string cpf;
    std::string rg;
    std::string data_nascimento;
    //TDadosIesEmissora
    std::string nome;
    std::string codigo_mec;
    std::string cnpj;
    std::string endereco;
    std::string credenciamento;
    std::string mantenedora;
    //TDadosCurso
    std::string nome_curso;
    std::string codigo_curso_mec;
    std::string nome_habilitacao;
    std::string modalidade;
    std::string titulo_conferido;
    std::string grau_conferido;
    //TDadosPrivadosDiploma
    std::string filiacao;
    std::string historico_escolar;
    std::string carga_horaria_curso;
    std::string ingresso_curso;
    std::string data;
    std::string forma_acesso;
    std::string data_conclusao;

    uint64_t primary_key() const { return key.value; }
  };
  typedef eosio::multi_index<"aluno"_n, tdiploma> diploma_index;

};
