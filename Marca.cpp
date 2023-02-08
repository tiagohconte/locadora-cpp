#include "Marca.hpp"
#include "Veiculo.hpp"

using namespace locadora;

Marca::Marca(const std::string& nome)
    : nome{nome} {}

std::string Marca::getNome() const { return this->nome; }

void Marca::setNome(const std::string& nome) { this->nome = nome; }

std::list<Veiculo*>& Marca::getVeiculos() { return this->veiculos; }