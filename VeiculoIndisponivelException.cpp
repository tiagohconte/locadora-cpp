#include "VeiculoIndisponivelException.hpp"

namespace locadora {

VeiculoIndisponivelException::VeiculoIndisponivelException(const Veiculo* veiculo)
    : std::runtime_error{"Veiculo Indisponivel."}, veiculo{veiculo} {}
}