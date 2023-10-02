/*
 * https://www.linkedin.com/pulse/first-5-principles-oop-c-what-so-solid-abdalrahman-hesham/
 * https://medium.com/backticks-tildes/the-s-o-l-i-d-principles-in-pictures-b34ce2f1e898

  * This principle states that a higher level-module should not depend on a
 lower-level module, but they both should depend on abstractions. It also states
 that abstractions should not depend on details, but details should depend on
 abstractions.

 * Suppose we have a "FruitBasket" class, which is a low-level module, where the
 user has "AddToBasket" functionality that appends a tuple of strings containing
 the fruit and the color to a vector.

 * Now suppose we have a high-level class named "ColorSeracher" that has a
 "ListColor" functionality, which goes through the vector item by item, then
 prints each found fruit with the matching color given to the function. This can
 be seen below.

 * The problem with this design is that the "ColorSeracher" high-level module
 depends heavily on the low-level module, since it knows the details about the
 "Basket" object found in it, as it knows it's a vector of tuples. Any
 modification to the low-level class, will now affect the higher-level one.

*/

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

// // low-level module
// class FruitBasket {
// public:
//   std::vector<std::tuple<std::string, std::string>> Basket;
//   void addToBasket(const std::string &Fruit, const std::string &Color) {
//     Basket.push_back(std::make_tuple(Fruit, Color));
//   }
// };
//
// // high-level module
// class ColorSearcher {
// public:
//   void listColor(const FruitBasket &fruit_basket,
//                  const std::string &color) const {
//     for (const auto &item : fruit_basket.Basket) {
//       if (std::get<1>(item) == color)
//         std::cout << "Found " << std::get<0>(item) << std::endl;
//     }
//   }
// };

/*
 * A simple solution would be to introduce an abstract class that both these
 modules depend on. By doing so, the high level class is seperated from the
 details. The code given below follows the dependency inversion principle.

 * Note that this design approach also follows the single responsibility
 principle, since it's the responsibility of the "FruitBasket" class to filter
 the items in it. Now, the high-level module doesn't depend on the lower-level
 one and it only knows that the "SearchByColor" member function returns a vector
 of strings of the found objects.

*/

// abstract module
class BasketSearcher {
public:
  virtual std::vector<std::string> searchByColor(const std::string &color) = 0;
};

// low-level module
class FruitBasket : public BasketSearcher {
public:
  std::vector<std::tuple<std::string, std::string>> Basket;
  void addToBasket(const std::string &Fruit, const std::string &Color) {
    Basket.push_back(std::make_tuple(Fruit, Color));
  }

  std::vector<std::string> searchByColor(const std::string &color) override {
    std::vector<std::string> found;
    for (const auto &item : Basket) {
      if (std::get<1>(item) == color)
        found.push_back(std::get<0>(item));
    }
    return found;
  }
};

// high-level module
class ColorSearcher {
public:
  void listColor(BasketSearcher &basket, const std::string &color) const {
    for (const auto &item : basket.searchByColor(color))
      std::cout << "Found " << item << std::endl;
  }
};
