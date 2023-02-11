#include "Console.hpp"

#include <iostream>

#include "Marca.hpp"

using namespace locadora;

void Console::imprimirDadosVeiculo(const Veiculo& veiculo) {
    std::cout << "ID: " << veiculo.getId() << '\n';
    std::cout << "Placa: " << veiculo.getPlaca() << '\n';
    // std::cout << "Disicplina: " << disciplina.getNome() << '\n';
    if (veiculo.getMarca() != nullptr)
        std::cout << "Marca: " << veiculo.getMarca()->getNome() << '\n';
    else
        std::cout << "Sem marca" << '\n';

    std::cout << "Modelo: " << veiculo.getModelo() << '\n';
    std::cout << "Custo: " << veiculo.getCusto() << '\n';
    std::cout << "Capacidade: " << veiculo.getCapacidade() << '\n';
}

void Console::imprimirDadosCarro(const Carro& carro) {
    imprimirDadosVeiculo(carro);
    std::cout << "Portas: " << carro.getPortas() << '\n';
    std::cout << "Categoria: " << carro.getNomeCategoria() << '\n';
}

void Console::imprimirDadosMotocicleta(const Motocicleta& moto) {
    imprimirDadosVeiculo(moto);
    std::cout << "Cilindrada: " << moto.getCilindrada() << '\n';
}

void Console::imprimirCatalogoVeiculos(const Catalogo& catalogo) {
    for (Veiculo* v : catalogo.getVeiculos()) {
        Console::imprimirDadosVeiculo(*v);
        std::cout << std::endl;
    }
}

void Console::imprimirCatalogoMarcas(const Catalogo& catalogo) {
    for (Marca* m : catalogo.getMarcas()) {
        std::cout << m->getNome() << std::endl;
    }
}