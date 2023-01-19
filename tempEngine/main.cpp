#include <iostream>

int main() {
  double tempEnvironment;
  std::cout << "Укажите температуру среды: ";
  std::cin >> tempEnvironment;

  // Объявление констант
  const int overheat = 110;
  const int I = 10;
  const double Hm = 0.01;
  const double Hv = 0.0001;
  const double C = 0.1;

  // Объявление переменных
  int time = 0;
  double engineTemp = tempEnvironment;
  int M[] = { 20, 75, 100, 105, 75,  0 };
  int V[] = { 0,  75, 150, 200, 250, 300 };
  double VCooling = C * (tempEnvironment - engineTemp);
  
  // Вычисление температуры нагрева
  double VHeating;
  for (int i = 0; i < 6; i++) {
     if (engineTemp >= overheat) {
      std::cout << "перегрев через " << time << std::endl;
      return 0;
    }
     
    VHeating = M[i] * Hm + V[i] * V[i] * Hv;
    std::cout << "скорость нагрева " << VHeating << std::endl;
    VCooling = C * (tempEnvironment - engineTemp);
    std::cout << "влияние охлаждения " << VCooling << std::endl;
    engineTemp += VHeating + VCooling;
    std::cout << "температура двигателя " << engineTemp << std::endl;
    time++;
  }
  if (engineTemp >= overheat) std::cout << "перегрев через " << time << std::endl;
}
