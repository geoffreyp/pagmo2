#include <string>

#include "docstrings.hpp"

namespace pygmo
{

std::string population_docstring()
{
    return R"(The population class.

This class represents a population of individuals, i.e., potential candidate solutions to a given problem. In PaGMO an
individual is determined:

* by a unique ID used to track him across generations and migrations,
* by a chromosome (a decision vector),
* by the fitness of the chromosome as evaluated by a :class:`~pygmo.core.problem` and thus including objectives,
  equality constraints and inequality constraints if present.

See also the docs of the C++ equivalent :cpp:class:`pagmo::population`.

)";
}

std::string population_push_back_docstring()
{
    return R"(push_back(x)

Adds one decision vector (chromosome) to the population.

Appends a new chromosome x to the population, evaluating its fitness and creating a new unique identifier for the newly
born individual. In case of exceptions, the population will not be altered.

Args:
    x (array or list of doubles): decision vector to be added to the population

Raises:
    ValueError: if the dimension of *x* is inconsistent with the problem dimension or the calculated fitness vector has
        a dimension which is inconsistent with the fitness dimension of the problem
    TypeError: if *x* cannot be converted to a vector of doubles

Examples:

>>> from numpy import array
>>> pop = population()
>>> pop.push_back([1])
>>> pop.push_back(array([2]))
>>> pop # doctest: +SKIP
[...]
List of individuals:
#0:
        ID:                     7905479722040097576
        Decision vector:        [1]
        Fitness vector:         [0, 0, 0]
#1:
        ID:                     11652046723302057419
        Decision vector:        [2]
        Fitness vector:         [0, 0, 0]
[...]
>>> pop.push_back(3) # doctest: +IGNORE_EXCEPTION_DETAIL
Traceback (most recent call last):
   ...
TypeError: cannot convert the type '<class 'int'>' to a vector of doubles

)";
}

std::string population_decision_vector_docstring()
{
    return R"(decision_vector()

Create random decision_vector.

Returns:
    NumPy array of doubles: a random decision vector within the problem’s bounds

Examples:

>>> pop = population()
>>> pop.decision_vector() # doctest: +SKIP
array([ 0.5393175])

)";
}

std::string population_best_idx_docstring()
{
    return R"(best_idx(tol = 0.)

Index of best individual. See :cpp:func:`pagmo::population::best_idx()`.

Args:
    tol (a double, or an array or list of doubles): a scalar tolerance or a vector of tolerances to be applied to
      each constraints

Returns:
    ``int``: the index of the best individual

Raises:
    ValueError: if the population is empty

Examples:

>>> pop = population(size = 5)
>>> pop.best_idx()
0

)";
}

std::string population_worst_idx_docstring()
{
    return R"(worst_idx(tol = 0.)

Index of worst individual. See :cpp:func:`pagmo::population::worst_idx()`.

Args:
    tol (a double, or an array or list of doubles): a scalar tolerance or a vector of tolerances to be applied to
      each constraints

Returns:
    ``int``: the index of the worst individual

Raises:
    ValueError: if the population is empty

Examples:

>>> pop = population(size = 5)
>>> pop.worst_idx()
0

)";
}

std::string population_size_docstring()
{
    return R"(size()

Size of the population.

The population size can also be queried using the builtin ``len()`` method.

Returns:
    ``int``: the number of individuals

Examples:

>>> pop = population(size = 5)
>>> pop.size()
5
>>> len(pop)
5

)";
}

std::string population_set_xf_docstring()
{
    return R"(set_xf(i,x,f)

Sets the i-th individual's decision vector and fitness.

Sets simultaneously the i-th individual decision vector and fitness, thus avoiding to trigger a fitness
function evaluation.

Args:
    i (an ``int``): individual’s index in the population
    x (an array or list of doubles): a decision vector (chromosome)
    f (an array or list of doubles): a fitness vector

Raises:
    ValueError: if *i* is invalid, or if *x* or *f* have the wrong dimensions (i.e., their dimensions are
        inconsistent with the problem properties)
    TypeError: if the argument types are invalid

Examples:

>>> pop = population(size = 1)
>>> pop.set_xf(0,[1],[1,2,3])
>>> pop # doctest: +SKIP
[...]
List of individuals:
#0:
        ID:                     12917122990260990364
        Decision vector:        [1]
        Fitness vector:         [1, 2, 3]
>>> pop.set_xf(1,[1],[1,2,3]) # doctest: +IGNORE_EXCEPTION_DETAIL
Traceback (most recent call last):
  ...
ValueError: Trying to access individual at position: 1, while population has size: 1

)";
}

std::string population_set_x_docstring()
{
    return R"(set_x(i,x)

Sets the i-th individual's decision vector.

The fitness of the individual will be computed from *x*.

Args:
    i (an ``int``): individual’s index in the population
    x (an array or list of doubles): a decision vector (chromosome)

Raises:
    ValueError: if *i* is invalid, or if *x* has the wrong dimensions (i.e., the dimension is
        inconsistent with the problem properties)
    TypeError: if the argument types are invalid

Examples:

>>> pop = population(size = 1)
>>> pop.set_x(0,[1])
>>> pop # doctest: +SKIP
[...]
List of individuals:
#0:
        ID:                     5051278815751827100
        Decision vector:        [1]
        Fitness vector:         [0, 0, 0]
>>> pop.set_x(1,[1,2]) # doctest: +IGNORE_EXCEPTION_DETAIL
Traceback (most recent call last):
  ...
ValueError: Length of decision vector is 2, should be 1

)";
}

std::string population_set_problem_seed_docstring()
{
    return R"(set_problem_seed(seed)

Sets the problem seed.

Args:
    seed (an ``int``): the desired seed (must be non-negative)

Raises:
    RuntimeError: if the problem is not stochastic
    OverflowError: if *seed* is too large or negative
    TypeError: if the argument types are invalid

Examples:

>>> pop = population(inventory())
>>> pop.set_problem_seed(42)
>>> pop # doctest: +SKIP
[...]
Extra info:
        Weeks: 4
        Sample size: 10
        Seed: 42
[...]
>>> pop = population()
>>> pop.set_problem_seed(seed = 42) # doctest: +IGNORE_EXCEPTION_DETAIL
Traceback (most recent call last):
  ...
RuntimeError: the user-defined problem does not support seed setting

)";
}

std::string population_get_problem_docstring()
{
    return R"(get_problem()

This method will return a deep copy of the internal problem instance.

Returns:
    :class:`~pygmo.core.problem`: a deep copy of the internal problem instance

Examples:

>>> pop = population()
>>> pop.get_problem() # doctest: +SKIP
Problem name: Null problem
        Global dimension:                       1
        Fitness dimension:                      3
[...]

)";
}

std::string population_get_f_docstring()
{
    return R"(get_f()

This method will return the fitness vectors of the individuals as a 2D NumPy array.

Each row of the returned array represents the fitness vector of the individual at the corresponding position in the
population.

Returns:
    NumPy array of doubles: a deep copy of the fitness vectors of the individuals

Examples:

>>> pop = population(size = 1)
>>> pop.get_f() # doctest: +SKIP
array([[ 0.13275027, 0.41543223, 0.28420476]])

)";
}

std::string population_get_x_docstring()
{
    return R"(get_x()

This method will return the chromosomes of the individuals as a 2D NumPy array.

Each row of the returned array represents the chromosome of the individual at the corresponding position in the
population.

Returns:
    NumPy array of doubles: a deep copy of the chromosomes of the individuals

Examples:

>>> pop = population(size = 5)
>>> pop.get_x() # doctest: +SKIP
array([[ 0.13275027],
       [ 0.26826544],
       [ 0.30058279],
       [ 0.41543223],
       [ 0.13370117]])

)";
}

std::string population_get_ID_docstring()
{
    return R"(get_ID()

This method will return the IDs of the individuals as a 2D NumPy array.

Each row of the returned array represents the ID of the individual at the corresponding position in the
population.

Returns:
    NumPy array of ``int``: a deep copy of the IDs of the individuals

Examples:

>>> pop = population(size = 5)
>>> pop.get_ID() # doctest: +SKIP
array([12098820240406021962,  2435494813514879429, 16758705632650014019,
       13060277951708126199,  1018350750245690412], dtype=uint64)

)";
}

std::string population_get_seed_docstring()
{
    return R"(get_seed()

This method will return the random seed of the population.

Returns:
    ``int``: the random seed of the population

Examples:

>>> pop = population(seed = 12)
>>> pop.get_seed()
12

)";
}

std::string problem_docstring()
{
    return R"(The main problem class.

>>> from pygmo import problem, rosenbrock
>>> p = problem(rosenbrock(dim=5))
>>> p.fitness([1,2,3,4,5])
array([ 14814.])

See also the docs of the C++ equivalent :cpp:class:`pagmo::problem`.

)";
}

std::string algorithm_docstring()
{
    return R"(The main algorithm class.

See also :cpp:class:`pagmo::algorithm`.

)";
}

std::string get_best_docstring(const std::string &name)
{
    return R"(best_known()

The best known solution for the )" + name + R"( problem.

Returns:
    NumPy array of doubles: the best known solution for the )" + name + R"( problem

)";
}

std::string rosenbrock_docstring()
{
    return R"(__init__(dim = 2)

The Rosenbrock problem.

Args:
    dim (int): number of dimensions

Raises:
    OverflowError: if *dim* is negative or greater than an implementation-defined value
    ValueError: if *dim* is less than 2

See also the docs of the C++ equivalent :cpp:class:`pagmo::rosenbrock`.

)";
}

std::string moead_docstring()
{
    return R"(__init__(gen = 1, weight_generation = "grid", neighbours = 20, CR = 1, F = 0.5, eta_m = 20, realb = 0.9, limit = 2, preserve_diversity = true, seed = random)

Multi Objective Evolutionary Algorithms by Decomposition (the DE variant)

Args:
    gen (int): number of generations
    weight_generation (float): method used to generate the weights, one of "grid", "low discrepancy" or "random"
    neighbours (int): size of the weight's neighborhood
    CR (float): crossover parameter in the Differential Evolution operator
    F (float): parameter for the Differential Evolution operator
    eta_m (float): distribution index used by the polynomial mutation
    realb (float): chance that the neighbourhood is considered at each generation, rather than the whole population (only if preserve_diversity is true)
    limit (int): stopping criteria on the f tolerance
    preserve_diversity (bool): maximum number of copies reinserted in the population  (only if m_preserve_diversity is true)
    seed (int): seed used by the internal random number generator (default is random)

Raises:
    OverflowError: if *gen*, *neighbours*, *seed* or *limit* are negative or greater than an implementation-defined value
    ValueError: if *cc*, *cs*, *c1*, *cmu* are not in [0,1] or -1

See also the docs of the C++ equivalent :cpp:class:`pagmo::moead`.

)";
}

std::string moead_get_log_docstring()
{
    return R"(moead.get_log()

Returns a log containing relevant parameters recorded during the last call to evolve and printed to screen. The log frequency depends on the verbosity
parameter (by default nothing is logged) which can be set calling the method set_verbosity on an object :class:`~pygmo.core.algoritm`
constructed with a :class:`~pygmo.core.moead`. A verbosity of N implies a log line each N generations.

Returns:
    list of tuples: at each logged epoch, the values Gen, Fevals, ADR, ideal_point.

Where:
    * Gen (int), generation number
    * Fevals (int), number of functions evaluation made.
    * ADF (float), Average Decomposed Fitness, that is the average across all decomposed problem of the single objective decomposed fitness along the corresponding direction.
    * ideal_point (list?), The ideal point of the current population

Examples:
    >>> from pygmo.core import *
    >>> algo  = algorithm(moead(gen = 500))
    >>> algo.set_verbosity(100)
    >>> prob = problem(zdt(1, 30))
    >>> pop = population(prob, 40)
    >>> pop = algo.evolve(pop)
    Gen:        Fevals:           ADF:        ideal1:        ideal2:
      1              0        25.4579      0.0420194        2.70624
    101           4000        5.71961    1.45123e-08       0.509844
    201           8000        5.27717    1.45123e-08        0.08718
    301          12000        5.20037    3.84274e-11      0.0399277
    401          16000        5.20402    1.75423e-12      0.0149309
    >>> al = algo.extract(moead)
    >>> al.get_log()
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    TypeError: No to_python (by-value) converter found for C++ type: std::__1::vector<double, std::__1::allocator<double> >

See also the docs of the C++ equivalent :cpp:function:`pagmo::moead::get_log`.

)";
}

std::string cmaes_docstring()
{
    return R"(__init__(gen = 1, cc = -1, cs = -1, c1 = -1, cmu = -1, sigma0 = 0.5, ftol = 1e-6, xtol = 1e-6, memory = false, seed = random)

Covariance Matrix Evolutionary Strategy (CMA-ES).

Args:
    gen (int): number of generations
    cc (float): backward time horizon for the evolution path (by default is automatically assigned)
    cs (float): makes partly up for the small variance loss in case the indicator is zero (by default is automatically assigned)
    c1 (float): learning rate for the rank-one update of the covariance matrix (by default is automatically assigned)
    cmu (float): learning rate for the rank-mu  update of the covariance matrix (by default is automatically assigned)
    sigma0 (float): initial step-size
    ftol (float): stopping criteria on the x tolerance
    xtol (float): stopping criteria on the f tolerance
    memory (bool): when true the adapted parameters are not reset between successive calls to the evolve method
    seed (int): seed used by the internal random number generator (default is random)

Raises:
    OverflowError: if *gen* is negative or greater than an implementation-defined value
    ValueError: if *cc*, *cs*, *c1*, *cmu* are not in [0,1] or -1

See also the docs of the C++ equivalent :cpp:class:`pagmo::cmaes`.

)";
}

std::string cmaes_get_log_docstring()
{
    return R"(cmaes.get_log()

Returns a log containing relevant parameters recorded during the last call to evolve and printed to screen. The log frequency depends on the verbosity
parameter (by default nothing is logged) which can be set calling the method set_verbosity on an object :class:`~pygmo.core.algoritm`
constructed with a :class:`~pygmo.core.cmaes`. A verbosity of N implies a log line each N generations.

Returns:
    list of tuples: at each logged epoch, the values Gen, Fevals, Best, dx, df, sigma

Where:
    * Gen (int), generation number
    * Fevals (int), number of functions evaluation made.
    * Best (float), the best fitness function currently in the population
    * dx (float), the norm of the distance to the population mean of the mutant vectors
    * df (float), the population flatness evaluated as the distance between the fitness of the best and of the worst individual
    * sigma (float), the current step-size

Examples:
    >>> from pygmo.core import *
    >>> algo = algorithm(cmaes(gen = 500))
    >>> algo.set_verbosity(100)
    >>> prob = problem(rosenbrock(10))
    >>> pop = population(prob, 20)
    >>> pop = algo.evolve(pop)
    Gen:        Fevals:          Best:            dx:            df:         sigma:
      1              0         173924        33.6872    3.06519e+06            0.5
    101           2000        92.9612       0.583942        156.921      0.0382078
    201           4000        8.79819       0.117574          5.101      0.0228353
    301           6000        4.81377      0.0698366        1.34637      0.0297664
    401           8000        1.04445      0.0568541       0.514459      0.0649836
    Exit condition -- generations = 500
    >>> al = algo.extract(cmaes)
    >>> al.get_log()
    [(1, 0, 173924.2840042722, 33.68717961390855, 3065192.3843070837, 0.5), ...

See also the docs of the C++ equivalent :cpp:function:`pagmo::cmaes::get_log`.

)";
}

std::string decompose_decompose_fitness_docstring()
{
    return R"(decompose_fitness(f, weights, ref_point)

Returns the original fitness of the multi-objective problem

Args:
    f (array or list of doubles): fitness vector to be decomposed
    weights (array or list of doubles): weights of the decomposition
    ref_point (array or list of doubles): reference point for the decomposition (only for tchebycheff and bi)

Returns:
    NumPy array of doubles: containing one single value representing the decomposed fitness

Raises:
    ValueError: if the dimensions of *f*, *weights* or *ref_point* are inconsistent
    TypeError: if *f*, *weights* or *ref_point* cannot be converted to vectors of doubles

Examples:
>>> from pygmo.core import *
>>> prob = problem(zdt(id=1, param=30))
>>> prob_d = problem(decompose(prob, [0.5,0.5], [0,0], "weighted", False))
>>> fit = prob.fitness([0.5]*30)
>>> fit_d = prob_d.fitness([0.5]*30)
>>> print(fit)
[ 0.5        3.8416876]
>>> print(fit_d)
[ 2.1708438]
>>> prob_d.extract(decompose).decompose_fitness(fit, [0.5,0.5],[0,0])
array([ 2.1708438])
>>> prob_d.extract(decompose).decompose_fitness(fit, [0.4,0.6],[0,0])
array([ 2.50501256])

)";
}

} // namespace
