#include "Cliente.hpp"

#include <iostream>

namespace locadora {

Cliente::Cliente(const std::string& nome, const unsigned long cpf)
    : nome{nome}, cpf{cpf} {}

Cliente::Cliente(const std::string& nome, const CPF& cpf)
    : nome{nome}, cpf{cpf} {}

std::string Cliente::getNome() const { return this->nome; }

void Cliente::setNome(const std::string& nome) { this->nome = nome; }

const CPF& Cliente::getCpf() const { return this->cpf; }

void Cliente::setCpf(const CPF& cpf) { this->cpf = cpf; }

std::list<Contrato*> Cliente::getContratos() const { return this->contratos; }

}