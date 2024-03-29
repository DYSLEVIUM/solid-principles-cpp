/*
 * https://www.linkedin.com/pulse/first-5-principles-oop-c-what-so-solid-abdalrahman-hesham/
 * https://medium.com/backticks-tildes/the-s-o-l-i-d-principles-in-pictures-b34ce2f1e898

 * This principle suggests that a class should have only a single
responsibility. In other words, a class should only have one purpose and
shouldn't do more than just that purpose, so when a change in this purpose is
needed, we have exactly one class to modify.

  * A good example of that would be to have countries around the globe as
classes, where each country has its average citizen income as a member.

  * Say we need to calculate the average tax from that average citizen income, a
bad approach contradicting the single responsibility principle would be to give
each class its own "CalcTax" member function. A good design approach, however,
should be to make a tax calculator class. This way whenever the tax calculation
process needs a change, we only need modify the tax calculator class and not
modify 195 classes (a class for each country).

  * So, as you can see the strategy for the calculation of each tax can be
different from one country to another, this TaxCalculator class could easily
account for that. Assuming a change in the policy of the taxes in a country,
modifying the code to account for that's takes only modifying one function,
which is the case if each country had its CalcuateTax member function too. What
the single responsibility principle really added, was that modifying a policy,
doesn't really modify the whole country class, which could be time consuming in
a more realistic complex project.
*/

#include <cstdint>

class TaxCalculator;

class UnitedStates {
  friend TaxCalculator;
  std::uint16_t m_avg_citizen_income;

public:
  explicit UnitedStates(const std::uint16_t &avg_income)
      : m_avg_citizen_income(avg_income){};
};

class UnktedKingdom {
  friend TaxCalculator;
  std::uint16_t m_avg_citizen_income;

public:
  explicit UnktedKingdom(const std::uint16_t &avg_income)
      : m_avg_citizen_income(avg_income){};
};

class TaxCalculator {
public:
  std::uint16_t CalculateTax(const UnitedStates &country) {
    return country.m_avg_citizen_income / 8;
  }

  std::uint16_t CalculateTax(const UnktedKingdom &country) {
    return country.m_avg_citizen_income / 10;
  }
};
