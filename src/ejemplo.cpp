#include<iostream>
#include<string>
#include<thread>
#include<chrono>
using namespace std;
#include <ftxui/screen/screen.hpp>
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10)

    );
    int y=5;
    int x=0;

    while(true)
    {
     Pixel& pixel = pantalla.PixelAt(x,y);
    pixel.foreground_color = Color::Red;
    pixel.background_color = Color::Green;
    pixel.character= 'x';

    pantalla.Print();
    pantalla.Clear(); 
    x++;  
    }

    pantalla.Print();
    this_thread::sleep_for(chrono::milliseconds(100));
    pantalla.Clear();
    
    cout<< pantalla.ResetPosition();
    return 0;
}
