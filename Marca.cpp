#include "Marca.hpp"
#include "Veiculo.hpp"

using namespace locadora;

unsigned int Marca::proxId{0};

Marca::Marca(const std::string& nome)
    : id{Marca::proxId}, nome{nome} {
    Marca::proxId++;
}

unsigned int Marca::getId() const { return id; }

std::string Marca::getNome() const { return this->nome; }

void Marca::setNome(const std::string& nome) { this->nome = nome; }

std::list<Veiculo*>& Marca::getVeiculos() { return this->veiculos; }