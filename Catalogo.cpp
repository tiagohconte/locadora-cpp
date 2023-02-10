#include "Catalogo.hpp"

using namespace locadora;

std::list<Veiculo*> Catalogo::getCatalogo() const { return this->veiculos; }

void Catalogo::adicionaVeiculo(Veiculo* const veiculo) { this->veiculos.push_back(veiculo); }