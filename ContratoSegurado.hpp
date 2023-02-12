#ifndef CONTRATO_SEGURADO_HPP
#define CONTRATO_SEGURADO_HPP

#include "Contrato.hpp"

namespace locadora {
class ContratoSegurado : public Contrato {
    public:
        using Contrato::Contrato;
        virtual ~ContratoSegurado() = default;

        virtual float getPreco() const override;
};
}
#endif