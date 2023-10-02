/*
 * https://www.linkedin.com/pulse/first-5-principles-oop-c-what-so-solid-abdalrahman-hesham/
 * https://medium.com/backticks-tildes/the-s-o-l-i-d-principles-in-pictures-b34ce2f1e898
 
  * This principle states that every derived class should be substitutable for
their base class. In other words, derived classes should behave correctly, as
expected and avoid logical errors due to their parent class.

  * Say we have a Rectangle class, which is a basic class that has width and
height attributes, set and get width functions, set and get height functions and
a calculate area function.

  * If we want to add a Square subclass based on this class.

  * So, what's the problem with that code? Isn't the square correctly handling
the dimension inequality case? Well, the problem is that the user using
"SetWidth" and "SetHeight" functions might not get that they change the other
attribute, so the user might get unexpected results when calling "CalculateArea"
function.

  * So, to sum it up, This Square class isn't substitutable for the Rectangle
class, and thereby breaks Liskov principle.
*/

#include <cstdint>

class Rectangle {
protected:
  std::uint16_t m_width, m_height;

public:
  Rectangle(const std::uint16_t &width, const std::uint16_t &height)
      : m_width(width), m_height(height){};

  virtual void setWidth(const std::uint16_t &width) { m_width = width; }
  virtual void setHeight(const std::uint16_t &height) { m_height = height; }

  virtual std::uint16_t getWidth() const { return m_width; }
  virtual std::uint16_t getHeight() const { return m_height; }

  virtual std::uint32_t calculateArea() const {
    return std::uint32_t(m_width) * m_height;
  }
};

class Square : public Rectangle {
public:
  explicit Square(const std::uint16_t &side) : Rectangle(side, side){};

  void setWidth(const std::uint16_t &width) override {
    m_width = width, m_height = width;
  }
  void setHeight(const std::uint16_t &height) override {
    m_width = height, m_height = height;
  }

  std::uint16_t getWidth() const override { return m_width; };
  std::uint16_t getHeight() const override { return m_height; };
};
