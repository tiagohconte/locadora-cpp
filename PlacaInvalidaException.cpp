#include "PlacaInvalidaException.hpp"

namespace locadora {

PlacaInvalidaException::PlacaInvalidaException(const std::string& placa)
    : std::runtime_error{"Placa Invalida."}, placa{placa} {}
}