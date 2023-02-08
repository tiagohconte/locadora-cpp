#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

#include "CPF.hpp"

namespace locadora {
class Cliente {
   public:
    Cliente(const std::string& nome, const unsigned long cpf);
    Cliente(const std::string& nome, const CPF& cpf);

    virtual ~Cliente() = default;

    std::string getNome() const;
    void setNome(const std::string& nome);

    const CPF& getCpf() const;
    void setCpf(const CPF& cpf);

   private:
    std::string nome;
    CPF cpf;
};
}  // namespace locadora
#endif