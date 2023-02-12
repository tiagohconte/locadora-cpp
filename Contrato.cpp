#include "Contrato.hpp"
#include "Cliente.hpp"
#include "Veiculo.hpp"

using namespace locadora;

Contrato::Contrato(Cliente* const cliente, Veiculo* const veiculo, const unsigned int duracao)
    : cliente{nullptr}, veiculo{nullptr}, duracao{duracao}
{
    this->cliente = cliente;

    if (this->veiculo != nullptr) {
        this->veiculo = veiculo;
        veiculo->setStatus(EnumStatus::INDISPONIVEL);
    }

}

Cliente* Contrato::getCliente() const { return this->cliente; }

void Contrato::setCliente(Cliente* const cliente) { this->cliente = cliente; }

Veiculo* Contrato::getVeiculo() const { return this->veiculo; }

void Contrato::setVeiculo(Veiculo* const veiculo) { this->veiculo = veiculo; }

unsigned short int Contrato::getDuracao() const { return this->duracao; }

void Contrato::setDuracao(const unsigned int duracao) { this->duracao = duracao; }

float Contrato::getPreco() const { return this->duracao * this->getVeiculo()->getCusto(); }