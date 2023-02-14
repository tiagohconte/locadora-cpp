#include "Contrato.hpp"
#include "Cliente.hpp"
#include "Veiculo.hpp"
#include "VeiculoIndisponivelException.hpp"

using namespace locadora;

Contrato::Contrato(Cliente* const cliente, Veiculo* const veiculo, const unsigned int duracao)
    : cliente{nullptr}, veiculo{nullptr}, status{EnumContrato::ATIVO}, duracao{duracao}
{
    this->setCliente(cliente);
    this->setVeiculo(veiculo);
}

Cliente* Contrato::getCliente() const { return this->cliente; }

void Contrato::setCliente(Cliente* const cliente) {
    if (this->cliente != nullptr)
        this->cliente->contratos.remove(this);
    this->cliente = cliente;
    if (this->cliente != nullptr)
        this->cliente->contratos.push_back(this);
}

Veiculo* Contrato::getVeiculo() const { return this->veiculo; }

void Contrato::setVeiculo(Veiculo* const veiculo) {
    if (veiculo->getStatus() == EnumStatus::INDISPONIVEL) throw VeiculoIndisponivelException{veiculo};
    this->veiculo = veiculo;
    if (this->veiculo != nullptr) veiculo->setStatus(EnumStatus::INDISPONIVEL);
}

EnumContrato Contrato::getStatus() const { return this->status; }

void Contrato::setStatus(const EnumContrato status) { this->status = status; }

unsigned short int Contrato::getDuracao() const { return this->duracao; }

void Contrato::setDuracao(const unsigned int duracao) { this->duracao = duracao; }

float Contrato::getPreco() const { return this->duracao * this->getVeiculo()->getCusto(); }