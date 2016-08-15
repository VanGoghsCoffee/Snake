#include "app_main.h"

#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
  Game::CApplication Snake;

  std::cout << "main entry" << std::endl;
  try
  {
    Snake.OnStart(argc, argv);
    Snake.OnRun();
  }
  catch (std::exception& _rException)
  {
    std::cout << _rException.what() << std::endl;
  }
  catch (const char* _pMessage)
  {
    std::cout << _pMessage << std::endl;
  }
  catch (...)
  {
    std::cout << "Uknown exception" << std::endl;
  }

  try
  {
    Snake.OnExit();
  }
  catch (std::exception& _rException)
  {
    std::cout << _rException.what() << std::endl;
  }
  catch (...)
  {
    std::cout << "Unkonwn exception" << std::endl;
  }
}
