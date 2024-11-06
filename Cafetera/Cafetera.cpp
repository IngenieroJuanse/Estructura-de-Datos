// Integrantes: Juan Sebastian Rodriguez Pabon
// Tema: Estructura de datos
// Taller: CAFETERAS
// 14/10/2024 corregido

#include <iostream>  // Incluimos la biblioteca iostream para operaciones de entrada y salida
#include <memory>    // Incluimos la biblioteca memory para utilizar punteros inteligentes como unique_ptr
#include <string>    // Incluimos la biblioteca string para manejar cadenas de texto

using namespace std;

// Clase que maneja la lógica de las recetas de café
class Receta {
public:

    // Método estático que se encarga de preparar una receta de café, segun el tipo de cafetera (nombre) y la receta(nombre)

    static void prepararReceta(const string& cafetera, const string& receta) {
        // Verificamos si la receta es "capuccino" y la preparamos
        if (receta == "capuccino") {
            cout << "Preparando capuccino en " << cafetera << ".\n";
        }
        // Verificamos si la receta es "tinto" y la preparamos
        else if (receta == "tinto") {
            cout << "Preparando tinto en " << cafetera << ".\n";
        }
        // Si la receta no es reconocida, indicamos que no está disponible
        else {
            cout << "Receta no disponible.\n";
        }
    }
};

// Esta clase será la base, es decir una clase abstracta para otras cafeteras como Haceb y Oster
class Cafetera {
public:
     // Metodo que sera implementado por todas las clases que hereden de cafetera para la receta que se preparará
    virtual void preparar(const string& receta) = 0;

      //Destructor virtual para que cuando se elimine un objeto de una clase derivada, se llame al destructor correcto.
    virtual ~Cafetera() = default;
};

// Clase que representa una cafetera de marca Haceb, hereda de Cafetera
class Haceb : public Cafetera {
public:
    //Implementación del método preparar para la cafetera Haceb, es decir (capuccino y tinto

    void preparar(const string& receta) override {
        Receta::prepararReceta("Haceb", receta);
    }
};

// Clase que representa una cafetera de marca Oster, hereda de Cafetera
class Oster : public Cafetera {
public:
     //Implementación del método preparar para la cafetera Oster, para la preparacion de la receta
    void preparar(const string& receta) override {
        Receta::prepararReceta("Oster", receta);
    }
};

int main() {
    string opcion, opcion2;  // Variables para almacenar las opciones seleccionadas por el usuario
    unique_ptr<Cafetera> cafetera;  // Puntero inteligente para manejar una instancia de Cafetera (Haceb u Oster)

    // Imprimimos un saludo y las opciones de recetas disponibles
    cout << "Hola, bienvenido a mi cafetera\n";
    cout << "¿Qué receta quieres preparar hoy?\n";
    cout << "1. capuccino\n";
    cout << "2. tinto\n";

    // Capturamos la elección del usuario sobre qué receta quiere
    cin >> opcion;

    // Validamos la elección del usuario y asignamos el nombre correcto de la receta
    if (opcion == "1") {
        opcion = "capuccino";
    } else if (opcion == "2") {
        opcion = "tinto";
    } else {
        // Si la opción no es válida, mostramos un mensaje de error y terminamos el programa
        cout << "Opción no válida.\n";
        return 1;
    }

    // Preguntamos al usuario qué tipo de cafetera desea usar
    cout << "¿Qué tipo de cafetera deseas?\n";
    cout << "1. Haceb\n";
    cout << "2. Oster\n";

    // Capturamos la elección del usuario sobre el tipo de cafetera
    cin >> opcion2;

    // Creamos una instancia de la cafetera seleccionada usando punteros inteligentes
    if (opcion2 == "1") {
        // Si elige Haceb, creamos una instancia de Haceb
        cafetera = make_unique<Haceb>();
    } else if (opcion2 == "2") {
        // Si elige Oster, creamos una instancia de Oster
        cafetera = make_unique<Oster>();
    } else {
        // Si la opción no es válida, mostramos un mensaje de error y terminamos el programa
        cout << "Opción no válida.\n";
        return 1;
    }

    // Llamamos al método preparar de la cafetera seleccionada, pasándole la receta elegida
    cafetera->preparar(opcion);

    return 0;  // El programa finaliza correctamente y listo
}
