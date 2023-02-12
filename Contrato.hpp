#ifndef CONTRATO_HPP
#define CONTRATO_HPP

#include "Veiculo.hpp"
#include "Cliente.hpp"

namespace locadora {
class Contrato {
    public:
        Contrato(Cliente* const cliente, Veiculo* const veiculo, const unsigned int duracao);
        virtual ~Contrato() = default;

        Cliente *getCliente() const;
        void setCliente(Cliente* const cliente);

        Veiculo *getVeiculo() const;
        void setVeiculo(Veiculo* const veiculo);

        unsigned short int getDuracao() const;
        void setDuracao(const unsigned int duracao);

        virtual float getPreco() const;

    private:
        Cliente *cliente;
        Veiculo *veiculo;
        unsigned int duracao;
};
}
#endif