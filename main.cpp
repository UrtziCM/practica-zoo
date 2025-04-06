#include <iostream>
#include "classes/Zoo.h"


void Clear()
{
	#if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined (__APPLE__)
		system("clear");
	#endif
}

int main(void) {
	bool salir = true;
	int opciones;
	Zoo listaZoo;
	while (salir)
	{
		std::cout << "----¿Que accion quiere realizar?----" << std::endl;
		std::cout << "1-<Añadir Animal>" << std::endl;
		std::cout << "2-<Buscar Animal>" << std::endl;
		std::cout << "3-<Mostrar lista de Animales>" << std::endl;
		std::cout << "4-<SALIR>"<< std::endl;
		std::cin >> opciones;

		switch (opciones)
		{
			case 1: {//Añadir
				Clear();
				listaZoo.AddAnimal();
				break;
			}
			case 2: {//Buscar
				Clear();
				std::string busqueda;
				Animal* animal = nullptr;
				std::cout << "----¿Como quieres buscar?----" << std::endl;
				std::cout << "1-<Por Nombre>" << std::endl;
				std::cout << "2-<Por Especie>" << std::endl;
				std::cin >> opciones;
				switch (opciones)
				{
					case 1: {//Nombre
						Clear();
						std::cout << "Ingresa el nombre del animal a buscar:" << std::endl;
						std::cin >> busqueda;
						animal = listaZoo.SearchAnimal(busqueda, false);
						break;
					}
					case 2: {//Especie
						Clear();
						std::cout << "Ingresa la especie del animal a buscar:" << std::endl;
						std::cin >> busqueda;
						animal = listaZoo.SearchAnimal(busqueda, true);
						break;
					}
				}
				listaZoo.ShowAnimalInfo(*animal);
				std::cout << "1-<Borrar Animal>" << std::endl;
				std::cout << "2-<SALIR>" << std::endl;
				std::cin >> opciones;
				if (opciones == 1) {
					listaZoo.RemoveAnimal(*animal);
					Clear();
					std::cout << "**ANIMAL ELIMINADO**" << std::endl;
				}
				break;
			}
			case 3: {//Mostrar
				Clear();
				listaZoo.ListAnimals();
				break;
			}
			case 4: {//Salir
				Clear();
				salir = false;
				break;
			}
		}
		Clear();
	}
	return (0);
}