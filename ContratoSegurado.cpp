#include "ContratoSegurado.hpp"

using namespace locadora;

float ContratoSegurado::getPreco() const { return Contrato::getPreco() * 1.5; }