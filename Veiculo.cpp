#include "Veiculo.hpp"

using namespace locadora;

unsigned int Veiculo::proxId{0};

Veiculo::Veiculo(std::string& modelo, float custo)
    : id{Veiculo::proxId},  modelo{modelo}, custo{custo} {
    Veiculo::proxId++;
}

unsigned int Veiculo::getId() const { return this->id; }

std::string Veiculo::getModelo() const { return this->modelo; }

void Veiculo::setModelo(const std::string& modelo) { this->modelo = modelo; }

float Veiculo::getCusto() const { return this->custo; }

void Veiculo::setCusto(float custo) { this->custo = custo; }
