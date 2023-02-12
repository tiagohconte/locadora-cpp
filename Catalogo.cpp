#include "Catalogo.hpp"

using namespace locadora;

Catalogo::Catalogo(){};

std::list<Cliente*> Catalogo::getClientes() const { return this->clientes; }

std::list<Marca*> Catalogo::getMarcas() const { return this->marcas; }

std::list<Veiculo*> Catalogo::getVeiculos() const { return this->veiculos; }

void Catalogo::adicionarCliente(Cliente* const cliente) {
    this->clientes.push_back(cliente);
}

void Catalogo::removerCliente(Cliente* const cliente) {
    this->clientes.remove(cliente);
    delete cliente;
}

void Catalogo::adicionarMarca(Marca* const marca) {
    this->marcas.push_back(marca);
}

void Catalogo::removerMarca(Marca* const marca) {
    this->marcas.remove(marca);
    delete marca;
}

Marca* Catalogo::getMarcaById(const unsigned int id) const {
    std::list<Marca*>::const_iterator it;

    for (it = this->marcas.begin(); it != this->marcas.end(); it++)
        if ((*it)->getId() == id) return (*it);

    return nullptr;
}

void Catalogo::adicionarVeiculo(Veiculo* const veiculo) {
    this->veiculos.push_back(veiculo);
}

void Catalogo::removerVeiculo(Veiculo* const veiculo) {
    this->veiculos.remove(veiculo);
    delete veiculo;
}