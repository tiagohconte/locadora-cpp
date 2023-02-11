#include "Placa.hpp"

#include <ctype.h>
#include <iomanip>

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

const Placa& Placa::operator=(const Placa& outro) {
    if (&outro != this) {
        this->valor = outro.valor;
    }
    return *this;
}

const Placa& Placa::operator=(const std::string& valor) {
    this->setValor(valor);
    return *this;
}

char Placa::operator[](short int idx) const {
    if (idx < 0 || idx > 6)
        throw std::out_of_range{"O indice precisa estar entre 0 e 6."};
    return this->valor[idx];
}

std::string Placa::operator()(short int inicio, short int tam) const {
    if (inicio < 0 || inicio >= 7 || tam < 1 || tam > 7)
        throw std::out_of_range{
            "Inicio deve estar entre 0 e 6, e tam entre 1 e 7"};
    if (inicio + tam > 7)
        throw std::out_of_range{"Inicio + tam deve ser menor ou igual a 7"};

    return this->getValor().substr(inicio, tam);
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

std::ostream& operator<<(std::ostream& stream, const Placa& placa) {
    stream << placa(0, 3) << "-" << placa(3, 4);

    return stream;
}

std::istream& operator>>(std::istream& stream, Placa& placa) {
    std::string parte1, parte2;
    stream >> std::setw(3) >> parte1;
    stream.ignore(1);  // pular o -
    stream >> std::setw(4) >> parte2;

    placa.setValor(parte1+parte2);

    return stream;
}

}  // namespace locadora