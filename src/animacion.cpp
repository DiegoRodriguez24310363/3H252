#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>

#include <Dibujo.hpp>
#include <GestorDibujos.hpp>

using namespace ftxui;

int main()
{

    auto screen = Screen::Create(
        Dimension::Fixed(80), //ancho
        Dimension::Fixed(20)); //alto


const std::vector<std::u32string> Perro = { 
        U"             .--~~,__",
        U":-....,-------`~~'._.'",
        U" `-,,,  ,_      ;'~U'",
        U"  _,-' ,'`-__; '--.",
        U" (_/'~~      ''''(;"
    };

     const std::vector<std::u32string> Pelota = { 
         U"  _._",
         U".'--.`.",
         U"|  .' |",
         U" `--`'"
         
    };

    GestorDibujos gestor;

    gestor.Agregar(Dibujo(2, 1, Perro, ftxui::Color::White));     // perro volador blanco
    gestor.Agregar(Dibujo(25, 3, Pelota, ftxui::Color::Green));     // pelota verde

    //Bucle de animación 
    for (int frame=0; frame<110; ++frame)
    {
        screen.Clear();

       gestor.dibujos[0].x = 2 + (frame % 40);  // Perro volador
       gestor.dibujos[1].x = 25 + (frame % 40); // Pelota

        gestor.DibujarTodos(screen);

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}