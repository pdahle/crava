#ifndef RPLIB_DRY_ROCK_H
#define RPLIB_DRY_ROCK_H

#include <vector>

// Abstract DryRock class.
class DryRock {
public:

  DryRock(){}
  virtual ~DryRock() {}

  virtual DryRock * Clone() const = 0;

  virtual void ComputeElasticParams(double & k, double & mu, double & rho) const = 0;

  // DryRock is an abstract class, hence pointer must be used in Evolve.
  // Allocated memory (using new) MUST be deleted by caller.
  // Input parameters:
  //      delta_time : the set of previous and present incremental time steps
  //      DryRock : the set of previous fluid samples
  // Recommended in implementation: assert(delta_time.size() == DryRock.size() + 1);
  virtual DryRock * Evolve(const std::vector<int>             & delta_time,
                         const std::vector< const DryRock * > & dryrock) const = 0;

protected:

};

#endif
