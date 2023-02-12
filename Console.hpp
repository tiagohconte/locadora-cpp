#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Carro.hpp"
#include "Catalogo.hpp"
#include "Motocicleta.hpp"
#include "Veiculo.hpp"

namespace locadora {
class Console {
   public:
    Console() = delete;
    virtual ~Console() = default;

    static void imprimirDadosVeiculo(const Veiculo& veiculo);
    static void imprimirDadosCarro(const Carro& carro);
    static void imprimirDadosMotocicleta(const Motocicleta& moto);
    static void imprimirCatalogoVeiculos(const Catalogo& catalogo);
    static void imprimirCatalogoMarcas(const Catalogo& catalogo);

    static void imprimirVeiculosDisponiveis(const Catalogo& catalogo);
    static void imprimirVeiculosMarca(const Catalogo& catalogo);

    static void imprimirDadosCliente(const Cliente& cliente);
    static void imprimirCatalogoClientes(const Catalogo& catalogo);
};
}  // namespace locadora
#endif