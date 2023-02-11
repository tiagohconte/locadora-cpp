#include "Catalogo.hpp"

using namespace locadora;

Catalogo::Catalogo(){};

std::list<Veiculo*> Catalogo::getVeiculos() const { return this->veiculos; }

std::list<Marca*> Catalogo::getMarcas() const { return this->marcas; }

void Catalogo::adicionarVeiculo(Veiculo* const veiculo) {
    this->veiculos.push_back(veiculo);
}

void Catalogo::removerVeiculo(Veiculo* const veiculo) {
    this->veiculos.remove(veiculo);
    delete veiculo;
}

void Catalogo::adicionarMarca(Marca* const marca) {
    this->marcas.push_back(marca);
}

void Catalogo::removerMarca(Marca* const marca) {
    this->marcas.remove(marca);
    delete marca;
}