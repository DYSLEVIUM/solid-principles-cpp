/*
 * https://www.linkedin.com/pulse/first-5-principles-oop-c-what-so-solid-abdalrahman-hesham/
 * https://medium.com/backticks-tildes/the-s-o-l-i-d-principles-in-pictures-b34ce2f1e898

  * This principle states that your code should generally be open for extension,
yet closed for modification. In the upcoming example, let's say we have a class
named "StringAdder" that has a member function called "AddToText" which takes
two strings and appends the second to the first.

  * Now, say we want to add another functionality to the TextAdder, for example
adding the functionality of adding the new string before the original one.
Extending the class through adding another function named "AddBeforeText" is the
wrong way to extend the functionalities of the class, since we had to modify the
class.

  * Following the Open/Closed Principle, this class should be extended making
the AddToText function take a third argument specifying what kind of string
addition the user wants done. This can be done using polymorphism. A base class
is passed to the "AddToText" function, then its own "add" function is called.

  * By looking at the above code, we see that the "TextAdder" class, which is
the class designed to be interfaced the most by the user, has become open for
extension, but closed for modification. We can easily add another class adding
the functionality of adding the new string after the third letter of the originl
string and so on.
*/

#include <string>

class TextAddType {
public:
  virtual std::string add(const std::string &original,
                          const std::string &new_string) = 0;
};

class TextAdder {
public:
  std::string AddToText(const std::string &original,
                        const std::string &new_string, TextAddType &adder) {
    return adder.add(original, new_string);
  }
};

class TextAppend : public TextAddType {
public:
  std::string add(const std::string &original,
                  const std::string &new_string) override {
    return original + new_string;
  }
};

class TextPrepend : public TextAddType {
public:
  std::string add(const std::string &original,
                  const std::string &new_string) override {
    return new_string + original;
  }
};
