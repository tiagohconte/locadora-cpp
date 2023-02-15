#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <list>

#include "CPF.hpp"
#include "Contrato.hpp"

namespace locadora {
class Cliente {
    friend std::ostream& operator<<(std::ostream& stream, const Cliente& cliente);
    friend void Contrato::setCliente(Cliente* const cliente);
    public:
        Cliente(const std::string& nome, const unsigned long cpf);
        Cliente(const std::string& nome, const CPF& cpf);

        virtual ~Cliente() = default;

        std::string getNome() const;
        void setNome(const std::string& nome);

        const CPF& getCpf() const;
        void setCpf(const CPF& cpf);

        std::list<Contrato*> getContratos() const;

    private:
        std::string nome;
        CPF cpf;
        std::list<Contrato*> contratos;
};
}  // namespace locadora
#endif