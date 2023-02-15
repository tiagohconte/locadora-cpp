#ifndef CONTRATO_HPP
#define CONTRATO_HPP

#include "Veiculo.hpp"

namespace locadora {

enum class EnumContrato {ATIVO, ENCERRADO};

class Cliente;
class Contrato {

    friend std::ostream& operator<<(std::ostream& stream, const Contrato& contrato);

    public:
        Contrato(Cliente* const cliente, Veiculo* const veiculo, const unsigned int duracao);
        virtual ~Contrato() = default;

        Cliente *getCliente() const;
        void setCliente(Cliente* const cliente);

        Veiculo *getVeiculo() const;
        void setVeiculo(Veiculo* const veiculo);

        EnumContrato getStatus() const;
        void setStatus(const EnumContrato status);

        unsigned short int getDuracao() const;
        void setDuracao(const unsigned int duracao);

        virtual float getPreco() const;

    private:
        Cliente *cliente;
        Veiculo *veiculo;
        EnumContrato status;
        unsigned int duracao;
};
}
#endif