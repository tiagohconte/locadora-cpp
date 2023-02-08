#include "Marca.hpp"

namespace locadora {

Marca::Marca(const std::string& nome)
    : nome{nome} {}

std::string Marca::getNome() const { return this->nome; }

void Marca::setNome(const std::string& nome) { this->nome = nome; }

}  // namespace locadora