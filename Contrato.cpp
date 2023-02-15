#include "Contrato.hpp"
#include "Cliente.hpp"
#include "Veiculo.hpp"
#include "VeiculoIndisponivelException.hpp"
#include "Marca.hpp"

#include <iomanip>

namespace locadora {

unsigned int Contrato::proxId{0};

Contrato::Contrato(Cliente* const cliente, Veiculo* const veiculo, const unsigned int duracao)
    : id{Contrato::proxId}, cliente{nullptr}, veiculo{nullptr}, status{EnumContrato::ATIVO}, duracao{duracao}
{
    this->setVeiculo(veiculo);
    this->setCliente(cliente);
    Contrato::proxId++;
}

unsigned int Contrato::getId() const { return this->id; }

void Contrato::setId(const unsigned int id) { this->id = id; }

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

void Contrato::encerraContrato() {
    this->veiculo->setStatus(EnumStatus::DISPONIVEL);
    this->status = EnumContrato::ENCERRADO;
}

std::ostream& operator<<(std::ostream& stream, const Contrato& contrato) {
    Cliente *c = contrato.getCliente();
    Veiculo *v = contrato.getVeiculo();
    const Marca *m = v->getMarca();

    stream << "Id: " << contrato.getId() << '\n'
            << "Cliente: " << c->getNome() << '\n'
            << "Veículo: ID " << v->getId() << " / " << m->getNome() << " "
            << v->getModelo() << '\n'
            << "Duracao: " << contrato.getDuracao() << '\n'
            << "Preço: R$" << std::setprecision(2) << std::fixed << contrato.getPreco() << '\n';

    return stream;
}
}