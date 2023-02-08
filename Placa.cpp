#include "Placa.hpp"

#include <ctype.h>

#include "PlacaInvalidaException.hpp"

namespace locadora {

Placa::Placa(const std::string& valor) { this->setValor(valor); }

std::string Placa::getValor() const { return this->valor; }

void Placa::setValor(const std::string& valor) {
    if (!validarPlaca(valor)) {
        throw PlacaInvalidaException{valor};
    }
    this->valor = valor;
}

char Placa::operator[](short int idx) const {
    if (idx < 0 || idx > 6)
        throw std::out_of_range{"O indice precisa estar entre 0 e 6."};
    return this->valor[idx];
}

bool Placa::validarPlaca(const std::string& placa) const {
    int i;
    for (i = 0; i < 3; i++)
        if (!std::isalpha(placa[i])) return false;

    if (!std::isdigit(placa[i++])) return false;

    if (!std::isalnum(placa[i++])) return false;

    for ( ; i < 7; i++)
        if (!std::isdigit(placa[i])) return false;

    return true;

}
}  // namespace locadora