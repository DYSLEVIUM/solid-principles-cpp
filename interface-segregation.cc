/*
 * https://www.linkedin.com/pulse/first-5-principles-oop-c-what-so-solid-abdalrahman-hesham/
 * https://medium.com/backticks-tildes/the-s-o-l-i-d-principles-in-pictures-b34ce2f1e898
 
 * This principle states that a client should never be forced to implement an
 interface that it doesn't use. In other words, if a class has a function public
 to the user, it must be callable.

 * Back to our square example, one might think that adding a "SetLenght" and
 "GetLenght" functions, while making the other width and height related
 functions empty or even warn the user somehow, is a good approach. This can be
 seen below.

 * Now, the "SetWidth" and "SetHeight" functions do, basically nothing, while
 the "GetWidth" and "GetHeight" functions call "GetLength" under the hood. So,
 what's the problem witht this design? Does our square class follow Liskov
 principle, now?

 * Actually, our class follows it indeed, by making the square class not behave
 in an unexpected way as the Width and height functions have been emptied, they
 could also be redesigned to print a warning or throw an exception when used.
 Still, this square class provides interfaces that aren't usable by the user,
 which is confusing and requires wasting lots of time both reading and writing
 the accompanying documentation.

*/

#include <cstdint>

// class Rectangle {
// protected:
//   std::uint16_t m_width, m_height;

// public:
//   Rectangle(const std::uint16_t &width, const std::uint16_t &height)
//       : m_width(width), m_height(height){};

//   virtual void setWidth(const std::uint16_t &width) { m_width = width; }
//   virtual void setHeight(const std::uint16_t &height) { m_height = height; }

//   virtual std::uint16_t getWidth() const { return m_width; }
//   virtual std::uint16_t getHeight() const { return m_height; }

//   virtual std::uint32_t calculateArea() const {
//     return std::uint32_t(m_width) * m_height;
//   }
// };

// class Square : public Rectangle {
// public:
//   explicit Square(const std::uint16_t &side) : Rectangle(side, side){};

//   /*
//     * (void) 'variable name' works around some compiler warnings. Some
//     compilers
// will warn if you don't use a function parameter. In such a case, you might
// have deliberately not used that parameter, not be able to change the
// interface for some reason, but still want to shut up the warning. That (void)
// casting construct is a no-op that makes the warning go away. Here's a simple
// example using clang
//   */
//   void setWidth(const std::uint16_t &width) override { (void)m_width; }
//   void setHeight(const std::uint16_t &height) override { (void)m_height; }
//   void setLength(const std::uint16_t &side) { m_width = side, m_height =
//   side; }

//   std::uint16_t getWidth() const override { return getLength(); };
//   std::uint16_t getHeight() const override { return getLength(); };
//   std::uint16_t getLength() const { return m_width; };
// };

/*
 * A better approach would be to redesign the whole thing by simply making a 2D
 simple shape base class that has all the basic functionalities, then each child
 class adds its own specific functions. That way each class has no unused
 interfaces and follows the interface segregation principle. This can be seen in
 the code below.

*/
class TwoDSimpleShape {
protected:
  std::uint16_t m_width, m_height;

public:
  TwoDSimpleShape(const std::uint16_t &width, const std::uint16_t &height)
      : m_width(width), m_height(height){};
  virtual std::uint32_t calculateArea() const {
    return uint32_t(m_width) * m_height;
  }
};

class Rectangle : public TwoDSimpleShape {
public:
  Rectangle(const std::uint16_t &width, const std::uint16_t &height)
      : TwoDSimpleShape(width, height) {}
  void setWidth(const std::uint16_t &width) { m_width = width; }
  void setHeight(const std::uint16_t &height) { m_height = height; }

  std::uint16_t getWidth() const { return m_width; }
  std::uint16_t getHeight() const { return m_height; }
};

class Square : public TwoDSimpleShape {
public:
  explicit Square(const std::uint16_t &side) : TwoDSimpleShape(side, side) {}

  void setLength(const std::uint16_t &side) { m_width = side, m_height = side; }

  std::uint16_t getLength() const { return m_width; };
};
